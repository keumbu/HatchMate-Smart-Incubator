# Algorithm

## Overview

This document describes the step-by-step operational algorithm used by the
HatchMate smart egg incubator.  
The algorithm defines how the system initializes, monitors environmental
conditions, makes decisions, and controls actuators in real time.

The system is designed to operate continuously using non-blocking logic.


## High-Level Algorithm Flow

The incubator operates in an infinite loop after initialization.

Main phases:
1. System initialization
2. Sensor data acquisition
3. Decision making
4. Actuator control
5. Display update
6. Alert monitoring
7. Timing management


## System Initialization Algorithm

1. Power ON system
2. Initialize ESP32 hardware
3. Configure GPIO pins
4. Initialize sensors
5. Initialize OLED display
6. Load incubation parameters
7. Set all actuators to safe default states
8. Display startup message

If any critical component fails to initialize, the system enters a safe state.


## Sensor Data Acquisition Algorithm

1. Read temperature sensor value
2. Read humidity sensor value
3. Validate sensor readings
4. Store values for processing

Invalid or missing sensor data triggers an alert condition.


## Temperature Control Algorithm

1. Compare current temperature to set target range
2. If temperature < minimum threshold:
   - Turn heater ON
3. If temperature ≥ target threshold:
   - Turn heater OFF
4. Continue monitoring at fixed intervals
5. Trigger alert if temperature exceeds safe limits

This ensures stable incubation temperature.


## Humidity & Ventilation Algorithm

1. Compare humidity reading to defined range
2. If humidity > maximum limit:
   - Activate ventilation fan
3. If humidity < minimum limit:
   - Reduce ventilation
4. Maintain airflow balance


## Egg Turning Algorithm

1. Track elapsed time using system timer
2. If turning interval reached:
   - Activate egg turning motor
   - Run motor for predefined duration
3. Stop motor
4. Reset turning timer
5. Update next turning countdown

The algorithm avoids blocking delays to allow other processes to run.


## Display Update Algorithm

1. Refresh display at fixed intervals
2. Show:
   - Temperature
   - Humidity
   - System status
   - Egg turning countdown
3. Display alert messages when active

Display updates are non-blocking and time-controlled.


## Alert Monitoring Algorithm

1. Continuously check system parameters:
   - Temperature
   - Humidity
   - Sensor validity
2. If any parameter exceeds safe limits:
   - Raise alert flag
   - Display alert message
3. Maintain alert until condition clears

Future versions may send alerts over Wi-Fi.


## Timing Management Algorithm

The system uses software timers to manage:

- Sensor sampling
- Egg turning intervals
- Display refresh
- Alert checks

All timers are based on system uptime counters to avoid blocking execution.


## Fail-Safe Algorithm

If a fault is detected:
1. Disable heating element
2. Enable ventilation
3. Display fault message
4. Maintain safe state until reset or intervention

This protects eggs and hardware from damage.


## Main Loop Summary

The main loop executes the following sequence repeatedly:

1. Acquire sensor data
2. Execute temperature control
3. Execute humidity control
4. Check egg turning timer
5. Update display
6. Check and handle alerts
7. Repeat continuously


## Conclusion

The HatchMate algorithm provides a structured, reliable approach to automated
egg incubation.  
By combining real-time sensing, decision logic, and safe actuation, the system
maintains optimal incubation conditions with minimal user intervention.


