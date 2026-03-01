
 * For enrollment, use the Adafruit "enroll" example sketch first.
 * 
 * Pins:
 *   - Fingerprint sensor: TX → Pin 2, RX → Pin 3
 *   - Relay: Pin 8
 *   - Green LED: Pin 9
 *   - Red LED: Pin 10

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

// ===================== Configuration =====================
#define UNLOCK_TIME 3000UL

// Pin assignments
#define SOLENOID_PIN 8
#define GREEN_LED_PIN 9
#define RED_LED_PIN 10

// Fingerprint sensor UART pins
#define FINGERPRINT_RX_PIN 2   // Arduino RX → sensor TX
#define FINGERPRINT_TX_PIN   3   // Arduino TX → sensor RX

// ===================== Global Objects =====================
SoftwareSerial fingerSerial(FINGERPRINT_RX_PIN, FINGERPRINT_TX_PIN);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&fingerSerial);

// ===================== Function Prototypes =====================
int  getFingerprintID(void);
void openDoor(void);
void accessDenied(void);
void blinkLED(int pin, int times, int duration);

// ===================== Setup =====================
void setup() {
  Serial.begin(9600);
  while (!Serial);          // For Leonardo/Micro, wait for serial

  // Initialize pins
  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  // Ensure lock is engaged and LEDs off
  digitalWrite(SOLENOID_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);

  Serial.println(F("\n=== Smart Door Lock Initializing ==="));

  // Set up fingerprint sensor
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println(F("✅ Fingerprint sensor detected."));
  } else {
    Serial.println(F("❌ ERROR: Fingerprint sensor not found!"));
    Serial.println(F("   Check wiring (TX/RX) and restart."));
    // Indefinite blink of red LED to signal fatal error
    while (1) {
      blinkLED(RED_LED_PIN, 2, 200);
      delay(1000);
    }
  }

  // Read sensor parameters (optional)
  finger.getTemplateCount();
  Serial.print(F("📊 Sensor contains "));
  Serial.print(finger.templateCount);
  Serial.println(F(" templates."));

  Serial.println(F("🟢 System ready. Place finger on sensor.\n"));
}

// ===================== Main Loop =====================
void loop() {
  int fingerprintID = getFingerprintID();

  if (fingerprintID >= 0) {
    Serial.print(F("🔓 Access granted to User ID #"));
    Serial.println(fingerprintID);
    openDoor();
  }
  // Small delay to reduce CPU usage
  delay(50);
}

// ===================== Fingerprint Functions =====================
/**
 * Captures an image, converts it, and searches the database.
 * @return Fingerprint ID (0-161) if found, -1 if no match or error.
 */
int getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) {
    // No finger or image error – silently ignore
    return -1;
  }

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) {
    Serial.println(F("⚠️ Image conversion failed"));
    return -1;
  }

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) {
    // No match found
    accessDenied();
    return -1;
  }

  // Found a match
  return finger.fingerID;
}

// ===================== Door Control =====================
/**
 * Unlocks the door for UNLOCK_TIME milliseconds,
 * then relocks it. Visual feedback via green LED.
 */
void openDoor() {
  digitalWrite(SOLENOID_PIN, HIGH);   // Energize relay (lock opens)
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(RED_LED_PIN, LOW);

  Serial.println(F("🚪 Door UNLOCKED"));

  delay(UNLOCK_TIME);

  digitalWrite(SOLENOID_PIN, LOW);    // De‑energize relay (lock closes)
  digitalWrite(GREEN_LED_PIN, LOW);

  Serial.println(F("🔒 Door LOCKED\n"));
}

/**
 * Handles failed access attempt: flashes red LED.
 */
void accessDenied() {
  Serial.println(F("❌ Access Denied"));
  blinkLED(RED_LED_PIN, 2, 500);      // Two slow flashes
}

// ===================== Helper =====================
/**
 * Blinks an LED a given number of times.
 * @param pin     LED pin
 * @param times   Number of blinks
 * @param duration On/off duration in milliseconds
 */
void blinkLED(int pin, int times, int duration) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(duration);
    digitalWrite(pin, LOW);
    if (i < times - 1) delay(duration);
  }
}
