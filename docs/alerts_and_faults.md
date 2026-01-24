# Alerts & Faults

## Overview

This document describes the alert and fault-handling mechanisms implemented
in the HatchMate smart incubator.  
Alerts are used to notify the user of abnormal conditions, while faults trigger
protective actions to prevent damage to eggs and hardware.


## Objectives of Alert & Fault System

The alert and fault system aims to:
- Detect abnormal operating conditions
- Protect eggs from unsafe environments
- Prevent hardware damage
- Provide clear user feedback
- Enable future remote notifications


## Alert vs Fault Classification

### Alerts

Alerts indicate abnormal conditions that require attention but do not
immediately stop system operation.

Examples:
- Temperature slightly out of range
- Humidity outside recommended limits
- Wi-Fi disconnected (future feature)


### Faults

Faults represent critical conditions that require immediate protective action.

Examples:
- Sensor failure
- Extreme temperature
- System initialization failure
- Power instability

Faults force the system into a safe state.


## Temperature Alerts & Faults

### High Temperature Alert
- Trigger condition: Temperature > target range
- Action:
  - Heater OFF
  - Ventilation ON
  - Alert displayed

### Over-Temperature Fault
- Trigger condition: Temperature > maximum safe limit
- Action:
  - Heater disabled
  - Ventilation forced ON
  - Fault message displayed
  - System remains in safe mode


### Low Temperature Alert
- Trigger condition: Temperature < target range
- Action:
  - Heater ON
  - Alert displayed

### Under-Temperature Fault
- Trigger condition: Temperature < minimum safe limit
- Action:
  - Heater disabled
  - Fault displayed


## Humidity Alerts

### High Humidity Alert
- Trigger condition: Humidity > maximum limit
- Action:
  - Increase ventilation
  - Display warning

### Low Humidity Alert
- Trigger condition: Humidity < minimum limit
- Action:
  - Reduce ventilation
  - Display warning

Humidity alerts do not immediately stop operation.


## Sensor Fault Detection

### Temperature Sensor Fault
- No response from sensor
- Invalid or out-of-range readings

### Humidity Sensor Fault
- Communication failure
- Invalid data

**Action for Sensor Faults:**
1. Disable heating element
2. Enable ventilation
3. Display sensor fault message
4. Prevent normal operation


## Actuator Faults (Future Detection)

Planned detection methods:
- Feedback from motor driver
- Relay status verification
- Current monitoring

In case of actuator failure:
- Disable affected subsystem
- Raise fault alert


## Startup Faults

Faults detected during startup include:
- Sensor initialization failure
- Display initialization failure
- Parameter loading error

Startup faults prevent transition to normal operation.


## Fault Recovery Strategy

- Alerts clear automatically when conditions return to normal
- Faults require:
  - System reset
  - User intervention
  - Component replacement (if required)

Fault states are latched to prevent unsafe oscillations.


## User Notification Methods

Current:
- OLED display messages
- Visual status indicators

Future:
- Wi-Fi notifications
- Mobile alerts
- Cloud logging


## Fail-Safe Behavior Summary

When a fault is detected:
1. Heating is disabled
2. Ventilation is enabled
3. Egg turning is paused
4. User is notified
5. System remains in safe mode


## Design Considerations

- Fault detection prioritized over normal control
- Safety overrides performance
- Alerts do not interfere with real-time operation
- Expandable fault detection architecture


## Conclusion

The alert and fault-handling system ensures safe and reliable operation of the
HatchMate incubator.  
By actively monitoring system health and responding appropriately, the system
protects both the incubation process and the hardware.
