#Hatchmate Smart Incubator

ESP32-based Wi-Fi enabled automatic egg incubator for full incubation cycle.

## Overview
Hatchmate is a smart incubator designed to automatically control temperature, humidity, ventilation, and egg turning. It provides both local monitoring (OLED, LEDs, buzzer) and remote monitoring via a Wi-Fi dashboard or mobile app.

The system operates safelt even without internet connectivity.

## Features
- Automatic temperature control (37.5°C ±0.5°C)
- Humidity control based on incubation day
- Automatic turning
- OLED status display
- Buzzer and LED alerts
- Wi-Fi monitoring and notifications
- Works offline after startup

## Hardware Summary
- ESP32 (Wi-Fi enabled)
- Temperature and humidity sensors
- Relays for heater, fan, humidifier, egg turner
- OLED display
- LEDs  and buzzer
- 12V DC power system

## Documentation
- [System Overview](docs/system_overview.md)
- [Hardware Design](docs/hardware_design.md)
- [Incubation Parameters](docs/incubation_parameters.md)
- [Startup Sequence](docs/startup_sequence.md)
- [Control Logic](docs/control_logic.md)
- [Algorithm](docs/algorithm.md)
- [Alerts & Faults](docs/alerts_and_faults.md)
- [Display UI](docs/display_ui.md)
- [Testing & Calibration](docs/testing_and_calibration.md)]

## Author
**Ezra Keumbu Asiago**  
Diploma in Electrical & Electronic Engineering
