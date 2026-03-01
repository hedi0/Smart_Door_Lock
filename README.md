# 🔐 Smart Door Lock with Fingerprint

[![Version](https://img.shields.io/badge/version-1.0.0-blue)](https://github.com/hedi0/Smart_Door_Lock/releases)
![License](https://img.shields.io/badge/license/Smart_DustBin-green)
![Stars](https://img.shields.io/github/stars/hedi0/Smart_DustBin?style=social)
![Forks](https://img.shields.io/github/forks/hedi0/Smart_DustBin?style=social)

A professional biometric access control system built using **Arduino**
and an **R307 fingerprint sensor**. Secure your door with fingerprint
authentication and automatic relocking.

![example-preview-image](/images/16-9overview_image_smart_door_lock.png)

------------------------------------------------------------------------

# 📋 Table of Contents

-   [Overview](#-overview)
-   [System Architecture](#-system-architecture)
-   [Features](#-features)
-   [Hardware Requirements](#-hardware-requirements)
-   [Professional Wiring Schematic](#-professional-wiring-schematic)
-   [Software Requirements](#-software-requirements)
-   [Installation Guide](#-installation-guide)
-   [Fingerprint Enrollment](#-fingerprint-enrollment)
-   [System Operation](#-system-operation)
-   [Configuration](#-configuration)
-   [Security Considerations](#-security-considerations)
-   [Troubleshooting](#-troubleshooting)
-   [Future Improvements](#-future-improvements)
-   [License](#-license)

------------------------------------------------------------------------

# 🌟 Overview

The Smart Door Lock transforms a standard mechanical door into a secure
biometric access system. When an authorized fingerprint is detected, the
solenoid unlocks the door for a configurable time.

Designed for: - DIY electronics enthusiasts - Embedded systems
learners - Smart home prototypes - Security system experiments

------------------------------------------------------------------------

# 🧠 System Architecture

    User Finger
        ↓
    Fingerprint Sensor (R307)
        ↓ UART
    Arduino Microcontroller
        ↓
    Access Decision Logic
        ↓
    Relay Module
        ↓
    12V Solenoid Lock

------------------------------------------------------------------------

# ✨ Features

-   🔐 Secure fingerprint authentication
-   👥 Supports up to 162 stored fingerprints
-   🟢 Green LED (Access Granted)
-   🔴 Red LED (Access Denied)
-   ⏱ Configurable unlock duration
-   🔌 Relay isolation for safe 12V control
-   🧩 Modular and expandable firmware

------------------------------------------------------------------------

# 🔧 Hardware Requirements

| Component                | Quantity | Notes                     |
|--------------------------|----------|----------------------------|
| Arduino Uno / Nano      | 1        | 5V compatible              |
| R307 Fingerprint Sensor  | 1        | UART interface             |
| 12V Solenoid Lock        | 1        | Fail-secure recommended    |
| 5V Relay Module          | 1        | 1-channel                  |
| Green LED                | 1        | 220Ω resistor required     |
| Red LED                  | 1        | 220Ω resistor required     |
| 12V DC Adapter           | 1        | ≥1A                        |
| Jumper Wires             | Several  | —                          |
| USB Cable                | 1        | Arduino programming        |

⚠️ Never power the solenoid directly from Arduino.

------------------------------------------------------------------------

# 🔌 Professional Wiring Schematic

                        +12V DC Supply
                            (+)     (-)
                             |       |
                             |       |
                      ┌──────▼───────▼──────┐
                      │      Relay Module   │
                      │ VCC  GND  IN  COM NO│
                      └───┬────┬────┬───┬───┘
                          |    |    |   |
                          |    |    |   └─────── To Solenoid +
                          |    |    └────────── Pin 8 (Arduino)
                          |    └────────────── GND
                          |
                   ┌──────▼────────┐
                   │   Arduino Uno │
                   │               │
                   │ Pin 2 ← TX    │
                   │ Pin 3 → RX    │
                   │ Pin 8 → Relay │
                   │ Pin 9 → Green LED →[220Ω]→ GND
                   │ Pin10 → Red LED →[220Ω]→ GND
                   │ GND ───────────────┐
                   └────────┬───────────┘
                            |
                   ┌────────▼────────┐
                   │ Fingerprint R307│
                   │ VCC TX RX GND   │
                   └─────────────────┘

------------------------------------------------------------------------

# 💻 Software Requirements

-   Arduino IDE (1.8.x or newer)
-   Libraries:
    -   Adafruit Fingerprint Sensor Library
    -   SoftwareSerial (built-in)

------------------------------------------------------------------------

# 🚀 Installation Guide

## 1️⃣ Clone Repository

``` bash
git clone https://github.com/hedi0/Smart_Door_Lock.git
cd Smart_Door_Lock/codes
```

## 2️⃣ Open in Arduino IDE

Open `code.ino`.


## 3️⃣ Select Board & Port

-   Tools → Board → Arduino Uno
-   Tools → Port → Select correct COM port

## 4️⃣ Upload

Click **Upload** and wait for completion.

## 5️⃣ Open Serial Monitor

Set baud rate to **9600**.

------------------------------------------------------------------------

# 👤 Fingerprint Enrollment

1.  Open Arduino IDE
2.  Go to: File → Examples → Adafruit Fingerprint Sensor → enroll
3.  Upload example sketch
4.  Open Serial Monitor (57600 baud)
5.  Follow prompts to enroll fingerprints
6.  Re-upload main project code

------------------------------------------------------------------------

# 🔄 System Operation

## Access Granted

-   Green LED ON
-   Relay activates
-   Solenoid unlocks
-   Auto-lock after timeout

## Access Denied

-   Red LED ON for 1 second
-   Door remains locked

------------------------------------------------------------------------

# ⚙️ Configuration

Modify in code:

``` cpp
#define UNLOCK_TIME 3000
#define SOLENOID_PIN 8
#define GREEN_LED 9
#define RED_LED 10
```

------------------------------------------------------------------------

# 🔐 Security Considerations

-   Use secure enclosure for electronics
-   Protect wiring from tampering
-   Consider adding:
    -   Buzzer alarm
    -   Attempt counter lockout
    -   Logging system

------------------------------------------------------------------------

# 🔍 Troubleshooting

| Issue               | Solution                  |
|---------------------|---------------------------|
| Sensor not detected | Swap RX/TX                |
| Door not unlocking  | Check 12V supply          |
| Constant denial     | Enroll fingerprints       |
| Random reset        | Use stable power supply   |

------------------------------------------------------------------------

# 🚀 Future Improvements

-   LCD display integration
-   Keypad backup
-   Bluetooth unlock
-   WiFi cloud logging
-   SD card event storage

---
