# 🔐 Smart Door Lock with Fingerprint Sensor

A DIY Arduino-based smart door lock system that uses fingerprint authentication for secure access control.

---

## 📌 Project Overview

This project implements a biometric door locking system using:

- Arduino Uno / Nano
- R307 Fingerprint Sensor
- 12V Solenoid Door Lock
- Relay Module
- Status LEDs (Access Granted / Denied)

The system unlocks the door only when a registered fingerprint is detected.

---

## 🚀 Features

- Fingerprint-based authentication
- Multiple user support (stored in sensor memory)
- Visual feedback (Green LED = Access Granted, Red LED = Access Denied)
- Auto-lock after configurable timeout
- Serial monitor debugging
- Simple and expandable design

---

## 🛠️ Hardware Requirements

| Component | Quantity |
|------------|----------|
| Arduino Uno/Nano | 1 |
| R307 Fingerprint Sensor | 1 |
| 12V Solenoid Door Lock | 1 |
| 5V Relay Module | 1 |
| Green LED | 1 |
| Red LED | 1 |
| 220Ω Resistors | 2 |
| Jumper Wires | Several |
| External 12V Power Supply | 1 |

---

## 🔌 Wiring Connections

| Component | Arduino Pin |
|------------|-------------|
| Fingerprint TX | Pin 2 |
| Fingerprint RX | Pin 3 |
| Solenoid Relay | Pin 8 |
| Green LED | Pin 9 |
| Red LED | Pin 10 |

> ⚠️ Use an external 12V supply for the solenoid lock.

---

## 📦 Required Libraries

Install using Arduino Library Manager:

- `Adafruit Fingerprint Sensor Library`
- `SoftwareSerial`

---

## ⚙️ Installation Steps

1. Connect all components according to the wiring table.
2. Install required libraries.
3. Open `Smart_Door_Lock.ino` in Arduino IDE.
4. Select correct Board and COM Port.
5. Upload the code.
6. Open Serial Monitor (9600 baud).

---

## 👤 Enrolling Fingerprints

To enroll new fingerprints:

1. Use the official Adafruit fingerprint enrollment example.
2. Enroll users into sensor memory.
3. The system will automatically recognize stored IDs.

---

## 🔄 System Workflow

1. User places finger on sensor.
2. Sensor scans and matches fingerprint.
3. If match found:
   - Green LED turns ON
   - Solenoid unlocks for 3 seconds
4. If no match:
   - Red LED blinks
   - Access denied

---

## 🔒 Security Notes

- Fingerprint templates are stored inside the sensor.
- Consider adding:
  - LCD display
  - Keypad backup password
  - Bluetooth/WiFi remote unlock
  - Access logging

---

## 📈 Future Improvements

- Add keypad fallback authentication
- Add mobile app control
- Add EEPROM-based access logging
- Add buzzer feedback
- Add OLED display status

---

## 🧠 Author

Developed by Hedi

---

## 📜 License

This project is open-source and free to use for educational purposes.
