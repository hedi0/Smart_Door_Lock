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
   
