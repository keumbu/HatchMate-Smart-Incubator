# HatchMate – Smart IoT Egg Incubator

## 1. What is this project?

HatchMate is a smart IoT-based egg incubator built using an ESP32 microcontroller.  
It automatically controls temperature, humidity, ventilation, and egg turning, while displaying real-time data on an OLED screen and allowing future Wi-Fi monitoring and control.



## 2. Why did I build this project?

I built this project to:
- Apply my skills in electrical & electronics engineering
- Gain hands-on experience with embedded systems and IoT
- Solve a real-world agricultural problem using technology
- Build a strong, practical portfolio project for employment and entrepreneurship

This project also supports my long-term goal of working with smart systems and automation.


## 3. What problem does it solve?

Traditional egg incubation methods often suffer from:
- Poor temperature and humidity regulation
- Manual egg turning errors
- Lack of monitoring and alerts
- Low hatch rates

HatchMate solves these problems by providing:
- Precise automatic temperature and humidity control
- Timed egg turning
- Visual feedback via OLED display
- Expandability for remote monitoring and alerts


## 4. Hardware Used

- ESP32 (LOLIN32)
- DS18B20 temperature sensor
- Humidity sensor (DHT / equivalent)
- Relay module
- 12V DC fan
- Heating bulb
- OLED display (I2C)
- 12V power supply
- Egg turning motor
- Miscellaneous wiring and connectors


## 5. Software Stack

- Embedded C / C++
- PlatformIO (VS Code)
- ESP32 Arduino framework
- Git & GitHub (version control)
- OLED libraries (Adafruit / U8g2)
- Arduino IoT / Wi-Fi libraries (planned)


## 6. How it works (Logic / Flow)

1. Sensors continuously read temperature and humidity values
2. Control logic compares readings against set thresholds
3. Actuators are triggered:
   - Heater turns ON/OFF to maintain temperature
   - Fan regulates airflow and humidity
   - Motor turns eggs at fixed time intervals
4. OLED display shows:
   - Temperature
   - Humidity
   - System status
   - Egg turning countdown
5. Alerts are generated when values exceed safe limits
6. (Future) Data is sent over Wi-Fi for remote monitoring


## 7. Documentation

Detailed technical documentation for this project is available in the `docs/` directory:

- [System Overview](docs/system_overview.md)
- [Hardware Design](docs/hardware_design.md)
- [Incubation Parameters](docs/incubation_parameters.md)
- [Startup Sequence](docs/startup_sequence.md)
- [Control Logic](docs/control_logic.md)
- [Algorithm](docs/algorithm.md)
- [Alerts & Faults](docs/alerts_and_faults.md)
- [Display UI](docs/display_ui.md)
- [Testing & Calibration](docs/testing_and_calibration.md)


## 8. How to Build / Flash the Firmware

### Requirements
- VS Code
- PlatformIO extension
- ESP32 USB drivers

### Steps
```bash
git clone https://github.com/your-username/HatchMate-Smart-Incubator.git
cd HatchMate-Smart-Incubator/firmware

1. Open the project in VS Code

2. Select the correct ESP32 board in platformio.ini

3. Connect ESP32 via USB

4. Click Upload in PlatformIO8. 


## 9.Future Improvements
   • Wi-Fi dashboard for remote monitoring

   • Mobile notifications (temperature / humidity alerts)

   • Data logging to SD card or cloud

   • PID temperature control

   • Solar-powered operation

   • Mobile app integration


## 10. Author
Ezra Keumbu Asiago
Diploma in Electrical & Electronic Engineering
Skills: Embedded Systems, ESP32, Arduino, AutoCAD, IoT
