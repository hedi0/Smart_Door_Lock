# 🔐 Smart Door Lock with Fingerprint

An intelligent biometric door locking system using Arduino and a
fingerprint sensor for secure and automated access control.

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license/Smart_Door_Lock-green)
![Stars](https://img.shields.io/github/stars/hedi0/Smart_Door_Lock?style=social)
![Forks](https://img.shields.io/github/forks/hedi0/Smart_Door_Lock?style=social)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)

![Smart Door Lock Preview](/preview_example.png)

------------------------------------------------------------------------

# 📋 Table of Contents

-   [Overview](#-overview)
-   [Features](#-features)
-   [Hardware Requirements](#-hardware-requirements)
-   [Professional ASCII Wiring Schematic](#-professional-ascii-wiring-schematic)
-   [Software Setup](#-software-setup)
-   [Installation Guide](#-installation-guide)
-   [Fingerprint Enrollment](#-fingerprint-enrollment)
-   [System Operation](#-system-operation)
-   [Configuration](#-configuration)
-   [Troubleshooting](#-troubleshooting)
-   [Project Roadmap](#-project-roadmap)
-   [License](#-license)

------------------------------------------------------------------------

# 🌟 Overview

The Smart Door Lock is a biometric access control system built using
Arduino and an R307 fingerprint sensor. It allows secure entry using
fingerprint authentication and automatically locks after a timeout.

------------------------------------------------------------------------

# ✨ Features

-   🔐 Fingerprint authentication
-   👥 Multi-user support
-   🟢 Access granted indicator (Green LED)
-   🔴 Access denied indicator (Red LED)
-   ⏱ Auto-lock system
-   🧩 Expandable architecture

------------------------------------------------------------------------

# 🔧 Hardware Requirements

  Component                   Quantity
  --------------------------- ----------
  Arduino Uno / Nano          1
  R307 Fingerprint Sensor     1
  12V Solenoid Lock           1
  5V Relay Module             1
  Green LED                   1
  Red LED                     1
  220Ω Resistors              2
  Jumper Wires                Several
  12V External Power Supply   1

⚠️ Important: Do NOT power the solenoid directly from Arduino.

------------------------------------------------------------------------
``` ```
# 🔌 Professional ASCII Wiring Schematic

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

------------------------------------------------------------------------

# 💻 Software Setup

## Required Software

-   Arduino IDE

## Required Libraries

Install via Arduino IDE → Library Manager: - Adafruit Fingerprint Sensor
Library - SoftwareSerial

------------------------------------------------------------------------

# 🚀 Installation Guide

## Clone Repository

```bash
git clone https://github.com/hedi0/Smart_Door_Lock.git
cd Smart_Door_Lock/codes
```

## Upload Steps

1.  Open `.ino` file in Arduino IDE










