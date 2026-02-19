#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

// =====================
// Pin Definitions
// =====================
#define SOLENOID_PIN 8
#define GREEN_LED 9
#define RED_LED 10

#define UNLOCK_TIME 3000   // Door unlock time in milliseconds

// =====================
// Fingerprint Sensor Setup
// =====================
SoftwareSerial mySerial(2, 3); // RX, TX
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

// =====================
// Setup
// =====================
void setup() {
  Serial.begin(9600);

  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Default states
  digitalWrite(SOLENOID_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("Smart Door Lock System Initializing...");

  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Fingerprint sensor detected successfully.");
  } else {
    Serial.println("ERROR: Fingerprint sensor not found!");
    Serial.println("Check wiring and restart.");
    while (1);
  }

  Serial.println("System Ready. Waiting for valid fingerprint...");
}

// =====================
// Main Loop
// =====================
void loop() {

  int fingerprintID = getFingerprintID();

  if (fingerprintID >= 0) {
    Serial.print("Access granted to User ID #");
    Serial.println(fingerprintID);
    openDoor();
  }

  delay(100);
}

// =====================
// Fingerprint Matching
// =====================
int getFingerprintID() {

  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) {
    accessDenied();
    return -1;
  }

  return finger.fingerID;
}

// =====================
// Door Control
// =====================
void openDoor() {
  digitalWrite(SOLENOID_PIN, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  Serial.println("Door Unlocked");

  delay(UNLOCK_TIME);

  digitalWrite(SOLENOID_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);

  Serial.println("Door Locked");
}

void accessDenied() {
  Serial.println("Access Denied");

  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);
}
