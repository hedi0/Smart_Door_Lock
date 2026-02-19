#include <Adafruit_Fingerprint.h>

// Pin definitions
#define SOLENOID_PIN 8
#define GREEN_LED 9
#define RED_LED 10

// Software serial for fingerprint sensor
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
  Serial.begin(9600);
  pinMode(SOLENOID_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  // Initialize fingerprint sensor
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("Fingerprint sensor found!");
  } else {
    Serial.println("Sensor not found - check wiring");
    while(1);
  }
}

void loop() {
  int fingerprintID = getFingerprintID();
  
  if (fingerprintID >= 0) {
    // Valid fingerprint detected
    openDoor();
    Serial.print("Access granted to user #");
    Serial.println(fingerprintID);
  }
  
  delay(50);
}

int getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK) return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK) return -1;

  return finger.fingerID;
}

void openDoor() {
  digitalWrite(SOLENOID_PIN, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  delay(3000); // Keep unlocked for 3 seconds
  digitalWrite(SOLENOID_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);
}
