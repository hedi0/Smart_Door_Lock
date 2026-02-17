# Smart Door Lock with Fingerprint Sensor

## Hardware Required
- Arduino Uno/Nano
- R307 Fingerprint Sensor
- 12V Solenoid Lock
- Relay Module
- 5V Power Supply
- 12V Power Supply
- LEDs and Resistors
- Jumper Wires

## Wiring Diagram
| Component | Arduino Pin |
|-----------|-------------|
| Fingerprint RX | Pin 2 |
| Fingerprint TX | Pin 3 |
| Solenoid Relay | Pin 8 |
| Green LED | Pin 9 |
| Red LED | Pin 10 |

## Setup Instructions
1. Install required libraries:
   - Adafruit Fingerprint Library
   - SoftwareSerial
2. Upload code to Arduino
3. Enroll fingerprints using serial monitor
4. Test the system
