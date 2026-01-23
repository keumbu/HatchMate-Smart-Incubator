# System Overview

## Introduction

HatchMate is a smart, microcontroller-based egg incubator designed to provide
a stable and automated environment for egg incubation.  
The system integrates sensors, actuators, control logic, and a user interface
to regulate temperature, humidity, ventilation, and egg turning with minimal
human intervention.

The design emphasizes reliability, modularity, and future expandability,
including IoT-based monitoring and control.


## System Architecture

The system is built around a **central ESP32 microcontroller** which acts as
the main processing and decision-making unit.

At a high level, the system consists of the following subsystems:

- Sensing subsystem
- Control subsystem
- Actuation subsystem
- User interface subsystem
- Power subsystem
- (Future) Communication subsystem

Each subsystem is modular and interacts through clearly defined interfaces.


## Sensing Subsystem

The sensing subsystem is responsible for collecting environmental data from
inside the incubator.

It includes:
- Temperature sensor (DS18B20)
- Humidity sensor

These sensors provide real-time feedback to the control logic, allowing the
system to make accurate and timely decisions.


## Control Subsystem

The control subsystem is implemented in firmware running on the ESP32.

Its responsibilities include:
- Processing sensor data
- Comparing values against predefined incubation thresholds
- Managing timing operations (egg turning, display refresh, alerts)
- Coordinating all system actions

The control logic operates using non-blocking timing mechanisms to ensure
continuous and responsive operation.


## Actuation Subsystem

The actuation subsystem executes physical actions based on decisions made by
the control logic.

It consists of:
- Heating element (incubation bulb)
- Ventilation fan
- Egg turning motor (via relay or driver module)

These actuators maintain optimal incubation conditions and reduce the need
for manual intervention.


## User Interface Subsystem

The user interface provides real-time system feedback to the user.

It includes:
- OLED display (I2C)

Displayed information typically includes:
- Current temperature
- Current humidity
- System status
- Egg turning countdown
- Alerts and warnings

This allows the user to monitor incubator performance at a glance.


## Power Subsystem

The power subsystem supplies energy to all components of the system.

Key characteristics:
- 12V DC main power supply
- Voltage regulation for logic-level components (5V / 3.3V)
- Electrical isolation between high-power loads and the microcontroller
  using relays

Proper power design ensures safety, stability, and long-term reliability.


## Communication Subsystem (Future Expansion)

The system is designed with future connectivity in mind.

Planned features include:
- Wi-Fi-based monitoring
- Remote alerts and notifications
- Cloud or mobile dashboard integration

The ESP32’s built-in Wi-Fi capability enables these features without major
hardware changes.


## Data Flow Summary

1. Sensors collect temperature and humidity data
2. Data is processed by the ESP32 control logic
3. Decisions are made based on predefined parameters
4. Actuators are switched accordingly
5. System status is displayed on the OLED
6. Alerts are generated when necessary


## Design Philosophy

The system is designed following these principles:
- Modularity for easy maintenance and expansion
- Non-blocking firmware architecture
- Safety-first operation
- Real-world usability and reliability


## Conclusion

The HatchMate system combines electronics, embedded software, and control
logic to form a reliable smart incubation solution.  
Its modular architecture allows for continuous improvement while maintaining
a stable and efficient incubation environment.
