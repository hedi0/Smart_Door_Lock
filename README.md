# 🔐 Smart Door Lock with Fingerprint (v2.0)

[![Version](https://img.shields.io/badge/version-2.0.0-blue)](https://github.com/hedi0/Smart_Door_Lock/releases)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Arduino-orange)](https://www.arduino.cc/)
[![Language](https://img.shields.io/badge/language-C%2B%2B-blue)](https://www.arduino.cc/)

A professional biometric access control system built using **Arduino**
and an **R307 fingerprint sensor**. Secure your door with fingerprint
authentication and automatic relocking.

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

  Component                 Quantity   Notes
  ------------------------- ---------- -------------------------
  Arduino Uno / Nano        1          5V compatible
  R307 Fingerprint Sensor   1          UART interface
  12V Solenoid Lock         1          Fail-secure recommended
  5V Relay Module           1          1-channel
  Green LED                 1          220Ω resistor required
  Red LED                   1          220Ω resistor required
  12V DC Adapter            1          ≥1A
  Jumper Wires              several    
  USB Cable                 1          Arduino programming

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
