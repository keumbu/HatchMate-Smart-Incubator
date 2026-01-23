# Control Logic

## Overview

The control logic is responsible for maintaining optimal incubation conditions by
continuously monitoring sensor data and controlling actuators in real time.

The system operates without blocking delays and uses time-based scheduling to
ensure stable temperature, humidity, ventilation, and egg turning.


## Main Control Objectives

- Maintain incubation temperature within safe limits
- Regulate humidity and airflow
- Automatically turn eggs at fixed intervals
- Detect abnormal conditions and raise alerts
- Provide real-time feedback via OLED display


## Control Inputs

The control logic receives input from the following sources:

- Temperature sensor (DS18B20)
- Humidity sensor
- System timers (millis-based)
- User-defined incubation thresholds
- Wi-Fi status 


## Control Outputs

Based on sensor readings and timing conditions, the system controls:

- Heating element (bulb)
- Ventilation fan
- Egg turning motor
- OLED display updates
- Alert indicators


## Temperature Control Logic

1. Read temperature value from sensor
2. Compare temperature with set limits:
   - If temperature < minimum threshold → Heater ON
   - If temperature ≥ target threshold → Heater OFF
3. Continue monitoring at regular intervals
4. Trigger alert if temperature exceeds safe range

This logic ensures stable incubation without rapid switching.


## Humidity & Ventilation Control

1. Read humidity sensor value
2. If humidity exceeds maximum limit:
   - Activate ventilation fan
3. If humidity drops below minimum limit:
   - Reduce ventilation
4. Maintain airflow balance to avoid sudden changes


## Egg Turning Logic

- Eggs are turned automatically at fixed time intervals (e.g. every 4 hours)
- A non-blocking timer using `millis()` is used
- Countdown time is calculated and displayed on the OLED

Steps:
1. Check elapsed time since last egg turn
2. If interval reached:
   - Activate motor for a predefined duration
   - Reset egg turning timer
3. Update countdown display using formatted time (HH:MM)


## Alert Handling Logic

Alerts are triggered when system parameters exceed safe limits:

- High temperature
- Low temperature
- Humidity out of range
- Sensor failure
- System fault 

Each alert:
- Is detected in the control logic
- Is displayed visually on the OLED
- Can be extended to Wi-Fi notifications


## Timing Strategy

The system avoids `delay()` to ensure responsiveness.

Timers are used for:
- Sensor sampling
- Egg turning intervals
- Display refresh
- Alert checks

This allows all subsystems to operate concurrently.


## Fail-Safe Behavior

In case of:
- Sensor disconnection
- Invalid readings
- Unexpected states

The system:
- Disables heating
- Enables ventilation
- Raises an alert
- Maintains safe conditions until intervention


## Summary

The control logic acts as the central decision-making unit of the incubator.
By combining sensor data, timing mechanisms, and actuator control, the system
achieves reliable, automated incubation with room for future expansion.
