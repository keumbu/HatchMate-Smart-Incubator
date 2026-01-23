# Hardware Design

## Overview

The hardware design of the HatchMate smart incubator focuses on reliability,
electrical safety, and modularity.  
The system integrates low-voltage digital electronics with higher-power loads
such as heating elements, fans, and motors.

The design ensures proper isolation between control logic and power circuits
while allowing future expansion.


## Main Hardware Components

The system consists of the following core components:

- ESP32 (LOLIN32) microcontroller
- Temperature sensor (DS18B20)
- Humidity sensor
- Relay module
- Heating element (incubation bulb)
- Ventilation fan (12V DC)
- Egg turning motor
- OLED display (I2C)
- 12V DC power supply
- Voltage regulation circuitry


## Microcontroller Unit (MCU)

The ESP32 serves as the central control unit.

Key features:
- Dual-core processor
- Built-in Wi-Fi and Bluetooth
- Multiple GPIOs
- Low power consumption
- 3.3V logic level

The ESP32 interfaces with sensors, actuators, and the display through digital
and serial communication protocols.


## Sensor Interface Design

### Temperature Sensor (DS18B20)

- Digital one-wire interface
- Powered at 3.3V or 5V
- Uses a pull-up resistor on the data line

Advantages:
- High accuracy
- Long cable support
- Noise-resistant digital signal


### Humidity Sensor

- Digital or analog output (depending on model)
- Powered from regulated supply
- Connected directly to ESP32 GPIOs

Humidity readings assist in ventilation and airflow control.


## Actuator Interface Design

### Heating Element

- Controlled via relay module
- Isolated from ESP32 using opto-isolation (relay board)
- Powered by external supply

The heater maintains incubation temperature under control logic supervision.


### Ventilation Fan

- 12V DC fan
- Controlled using a relay or transistor-based driver
- Provides airflow regulation and heat distribution


### Egg Turning Motor

- Low-speed DC motor or geared motor
- Controlled through a relay or motor driver
- Activated periodically to rotate eggs

The motor is energized only for short durations to reduce wear.


## Relay & Driver Circuits

Relays are used to:
- Isolate high-voltage / high-current loads
- Protect the microcontroller
- Enable safe switching of actuators

Flyback diodes and proper grounding are used to suppress electrical noise.


## Display Interface

### OLED Display (I2C)

- Communicates via I2C protocol
- Requires only two data lines (SDA, SCL)
- Powered at 3.3V or 5V

The display provides real-time feedback and system status.


## Power Supply Design

The system uses a multi-level power approach:

  - 12V DC main supply for:
  - Fan
  - Motor
  - Heating element
  - Voltage regulation to:
  - 5V (peripherals)
  - 3.3V (ESP32 logic)

Relays provide electrical separation between control and power domains.


## Grounding & Noise Considerations

- Common ground reference for low-voltage electronics
- Separate high-current paths for actuators
- Proper decoupling capacitors near sensitive components
- Short signal paths to reduce interference

These measures improve system stability and sensor accuracy.


## Safety Considerations

The hardware design prioritizes safety:

- Electrical isolation via relays
- Controlled switching of heating elements
- Fail-safe default states
- Proper cable management and insulation

These features reduce the risk of overheating and electrical faults.


## Expandability & Future Enhancements

The hardware design allows for:
- Additional sensors
- Wi-Fi antennas
- SD card module
- Backup power (battery or solar)
- Improved motor drivers

Unused GPIOs and modular wiring support future upgrades.


## Summary

The HatchMate hardware design combines robust electronics, safe power handling,
and modular architecture to support reliable incubation operations.  
The system is designed to be scalable, maintainable, and suitable for real-world
deployment.
