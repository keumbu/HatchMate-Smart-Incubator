# Startup Sequence

## Overview

This document describes the sequence of operations performed by the HatchMate
smart incubator immediately after power is applied.  
A controlled startup sequence ensures system stability, safety, and correct
initialization of all hardware and software components.


## Startup Objectives

The startup sequence aims to:
- Initialize all hardware interfaces
- Ensure actuators are in safe default states
- Validate sensor availability
- Prepare the system for continuous operation
- Provide visual feedback to the user


## Power-On Event

1. DC power is applied to the system
2. Voltage regulators stabilize output levels
3. ESP32 resets and begins firmware execution

During this phase, all actuators remain inactive.


## Microcontroller Initialization

1. ESP32 bootloader executes
2. System clock and core services are initialized
3. GPIO pins are configured:
   - Sensor inputs
   - Relay outputs
   - Display interface pins

Default pin states are applied to prevent unintended switching.


## Peripheral Initialization

### Sensor Initialization

1. Temperature sensor interface is initialized
2. Humidity sensor interface is initialized
3. Initial sensor readings are taken
4. Sensor availability is verified

If a sensor fails to respond, an alert condition is raised.


### Display Initialization

1. OLED display interface is initialized
2. Display buffer is cleared
3. Startup message is shown
4. System status indicators are displayed

This confirms successful boot to the user.


### Actuator Initialization

1. Heating element relay set to OFF
2. Ventilation fan set to OFF
3. Egg turning motor set to OFF

All actuators remain disabled until control logic begins.


## Parameter Loading

1. Default incubation parameters are loaded:
   - Temperature limits
   - Humidity limits
   - Egg turning interval
2. Parameters may later be:
   - Hardcoded
   - Loaded from memory
   - Updated via user interface or Wi-Fi (future)


## System Self-Check

1. Verify sensor readings are within plausible ranges
2. Confirm relay control signals respond correctly
3. Check system timers and counters
4. Validate display update functionality

Any detected fault places the system into a safe state.


## Transition to Normal Operation

1. Startup sequence completes successfully
2. Control logic loop is enabled
3. Continuous monitoring begins
4. OLED switches from startup screen to live data display

The system now operates autonomously.


## Fault Handling During Startup

If a critical fault is detected:
1. Disable heating element
2. Enable ventilation if necessary
3. Display error message
4. Prevent transition to normal operation

Manual intervention may be required before restart.


## Startup Sequence Summary

1. Power applied
2. ESP32 boots
3. Hardware initialized
4. Sensors validated
5. Actuators set to safe states
6. Parameters loaded
7. Self-check performed
8. System enters normal operation


## Conclusion

A well-defined startup sequence ensures safe and reliable operation of the
HatchMate incubator.  
By validating hardware and software components at power-on, the system minimizes
the risk of faults during incubation.

