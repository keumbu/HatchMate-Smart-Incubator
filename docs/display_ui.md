# Display UI

## Overview

This document describes the user interface displayed on the OLED screen of the
HatchMate smart incubator.  
The display provides real-time feedback on system status, incubation conditions,
and alerts, enabling the user to monitor the incubator at a glance.

The interface is designed to be simple, clear, and readable under various
lighting conditions.


## Display Hardware

- OLED display (I2C)
- Resolution: typically 128 × 64 pixels
- Low power consumption
- High contrast for easy readability

The display communicates with the ESP32 via the I2C protocol.


## UI Design Objectives

The display interface is designed to:
- Present critical information clearly
- Minimize clutter
- Provide immediate alert visibility
- Operate reliably with periodic refresh
- Avoid distracting animations


## Default Display Screen

The default screen shows the primary incubation parameters:

- Current temperature (°C)
- Current humidity (%RH)
- System status (Normal / Alert / Fault)
- Egg turning countdown timer

This screen is shown during normal operation.


## Screen Layout Example

| Temp: 37.5 C |
| Hum: 52 % |
| Status: NORMAL |
| Turn in: 01:35 |



## Startup Screen

During system initialization, the display shows:

- Project name
- Firmware version (optional)
- Startup status message

Example:

HatchMate
Initializing...


This confirms successful power-on to the user.


## Alert Display Screen

When an alert is active:
- Alert message overrides normal status
- Parameter causing alert is highlighted
- Alert remains visible until condition clears

Example:

ALERT!
High Temperature



## Fault Display Screen

When a fault is detected:
- Fault message is displayed prominently
- Normal data display is suspended
- System remains in safe state

Example:

FAULT!
Temp Sensor Error


Fault messages require user intervention.


## Screen Update Strategy

- Display updates occur at fixed intervals
- Non-blocking timing is used
- Only changed values are refreshed when possible

This reduces flicker and improves readability.


## UI State Transitions

The display operates in the following states:
1. Startup
2. Normal operation
3. Alert
4. Fault

State transitions are controlled by system logic and fault detection.


## Icon & Symbol Usage (Optional)

Future UI enhancements may include:
- Status icons
- Wi-Fi connection indicator
- Warning symbols

Icons improve usability without adding text clutter.


## Localization & Customization (Future)

The UI design supports:
- Multiple languages
- Unit customization
- User-defined display preferences


## Summary

The HatchMate display UI provides a clear and effective interface between the
user and the incubator system.  
By presenting essential information in a structured manner, the UI enhances
usability, safety, and system transparency.
