# 🔐 Smart Door Lock with Fingerprint

[![Version](https://img.shields.io/badge/version-2.0.0-blue)](https://github.com/hedi0/Smart_Door_Lock/releases)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![Stars](https://img.shields.io/github/stars/hedi0/Smart_Door_Lock?style=social)](https://github.com/hedi0/Smart_Door_Lock/stargazers)
[![Language](https://img.shields.io/badge/language-C%2B%2B-blue)](https://www.arduino.cc/)

A robust, biometric door access control system using **Arduino** and an **R307 fingerprint sensor**.  
Authenticate with your fingerprint – the door unlocks automatically and relocks after a preset time.

> 📸 *Example image placeholder – replace `preview_example.png` with a photo of your actual setup.*

---

## 📋 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Hardware Requirements](#-hardware-requirements)
- [Wiring Diagram](#-wiring-diagram)
- [Software Setup](#-software-setup)
- [Installation](#-installation)
- [Enrolling Fingerprints](#-enrolling-fingerprints)
- [System Operation](#-system-operation)
- [Configuration](#-configuration)
- [Troubleshooting](#-troubleshooting)
- [Roadmap](#-roadmap)
- [License](#-license)

---

## 🌟 Overview
This project turns a standard door into a **smart, keyless entry system**.  
It uses an Arduino-compatible board, an optical fingerprint sensor, and a solenoid lock.  
When a registered fingerprint is presented, the lock opens for a configurable period, then secures itself again.

---

## ✨ Features
- ✅ **Fingerprint authentication** – secure and fast  
- 👥 **Multi‑user support** – store up to 162 fingerprints  
- 🟢 **Green LED** – access granted indication  
- 🔴 **Red LED** – access denied indication  
- ⏱ **Auto‑lock** – programmable lock duration  
- 🧩 **Modular code** – easy to expand with keypad, Bluetooth, etc.  
- 🔌 **Relay‑controlled lock** – safe isolation from Arduino  

---

## 🔧 Hardware Requirements

| Component                   | Quantity | Notes                                   |
|-----------------------------|----------|-----------------------------------------|
| Arduino Uno / Nano          | 1        | Any 5V logic board                      |
| R307 Fingerprint Sensor     | 1        | Optical sensor with UART interface      |
| 12V Solenoid Lock           | 1        | Fail‑secure type                        |
| 5V Relay Module             | 1        | 1‑channel, active LOW or HIGH (check)   |
| Green LED                    | 1        | 3‑5mm                                   |
| Red LED                      | 1        | 3‑5mm                                   |
| 220Ω Resistors               | 2        | Current limiting for LEDs               |
| Jumper Wires                 | several  | Male‑female, male‑male                  |
| 12V DC Power Supply          | 1        | ≥1A, for solenoid                       |
| USB Cable & Power (5V)       | 1        | For Arduino                             |

⚠️ **Important:** Never power the solenoid directly from the Arduino – always use the relay and a separate 12V supply.

---

## 🔌 Wiring Diagram
Below is the professional ASCII schematic. All connections are clearly labeled.
text
                    +12V External Supply
                         (+)        (-)
                          |          |
                          |          |
                     ┌────▼──────────▼────┐
                     │      Relay Module   │
                     │  VCC  GND  IN  COM  │
                     │   |    |    |    |   │
                     └───┼────┼────┼────┼───┘
                         |    |    |    |
                         |    |    |    └───── NO ──────┐
                         |    |    |                     |
                         |    |    └──────── Pin 8       |
                         |    |                          |
                         |    └──────────── GND          |
                         |                               |
                         |                           ┌───▼───────┐
                         |                           │ Solenoid  │
                         |                           │   Lock    │
                         |                           └───────────┘
                         |
                ┌────────▼────────┐
                │   Arduino Uno   │
                │                  │
                │ Pin 2  ← TX     │
                │ Pin 3  → RX     │
                │ Pin 8  → Relay  │
                │ Pin 9  → Green LED ──[220Ω]──►│── GND
                │ Pin10  → Red LED   ──[220Ω]──►│── GND
                │ GND    ───────────────┐
                └────────┬──────────────┘
                         |
                         |
               ┌─────────▼─────────┐
               │ Fingerprint Sensor│
               │   VCC  TX  RX GND │
               └───────────────────┘
text

**Connections summary:**
- Fingerprint sensor: VCC → 5V, GND → GND, TX → Arduino Pin 2, RX → Arduino Pin 3
- Relay module: VCC → 5V, GND → GND, IN → Arduino Pin 8, COM → 12V+, NO → Solenoid positive
- Solenoid: negative to 12V GND
- LEDs: anodes through 220Ω resistors to Pins 9 (green) and 10 (red), cathodes to GND

---

## 💻 Software Setup

### Required Software
- [Arduino IDE](https://www.arduino.cc/en/software) (version 1.8.5 or later)

### Required Libraries
Install via **Sketch → Include Library → Manage Libraries**:
- `Adafruit Fingerprint Sensor Library` by Adafruit
- `SoftwareSerial` (built‑in)

---

## 🚀 Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/hedi0/Smart_Door_Lock.git
   cd Smart_Door_Lock/codes
Open the sketch
Launch Arduino IDE and open code.ino.

Select board and port

Board: Arduino Uno (or your specific board)

Port: the COM port your Arduino is connected to

Upload
Click the Upload button (→).

Open Serial Monitor
Set baud rate to 9600. You will see initialisation messages.

👤 Enrolling Fingerprints
Before using the main system, you must enroll fingerprints using the library’s example:

In Arduino IDE, go to File → Examples → Adafruit Fingerprint Sensor → enroll.

Upload the example sketch.

Open Serial Monitor (57600 baud) and follow the prompts to add fingerprints.

Important: After enrollment, re‑upload the main code.ino sketch.

The sensor can store up to 162 different fingerprints (IDs 0–161).

🔄 System Operation
✅ Access Granted
Green LED turns on

Relay activates → solenoid unlocks

Door stays open for UNLOCK_TIME (default 3 seconds)

After delay, solenoid locks again, green LED turns off

❌ Access Denied
Red LED flashes for 1 second

Door remains locked

Message appears on Serial Monitor

⚙️ Configuration
All settings are defined at the top of code.ino. Modify them to suit your needs.

cpp
// Unlock duration in milliseconds (e.g., 5000 = 5 seconds)
#define UNLOCK_TIME 3000

// Pin assignments
#define SOLENOID_PIN 8
#define GREEN_LED    9
#define RED_LED      10
🔍 Troubleshooting
Problem	Likely Solution
Sensor not detected	Check RX/TX wiring; swap TX/RX if necessary.
Door never unlocks	Verify relay wiring; check 12V supply.
Always "Access Denied"	Ensure fingerprints are enrolled (see section above).
Arduino resets randomly	Use separate 5V supply for Arduino; avoid shared ground loops.
Red LED flashes on every scan	Sensor may not be getting a clear image – clean sensor and finger.
🗺️ Roadmap
Future enhancements planned:

LCD display – show user feedback and system status

Keypad backup – enter PIN if fingerprint fails

Bluetooth control – unlock via smartphone

WiFi / IoT – remote access and logging

Access logs – store events on SD card

Contributions and suggestions are welcome!

📄 License
This project is licensed under the MIT License – see the LICENSE file for details.
