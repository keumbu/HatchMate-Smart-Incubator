# Incubation Parameters

## Overview

This document defines the environmental parameters required for successful
egg incubation and how they are applied within the HatchMate smart incubator.

Proper control of temperature, humidity, ventilation, and egg turning is
critical to achieving high hatch rates and healthy chicks.


## Incubation Phases

Egg incubation is divided into distinct phases, each requiring specific
environmental conditions.

Typical incubation phases:
1. Early incubation
2. Mid incubation
3. Final incubation (lockdown)

Parameter values may vary slightly depending on egg type.


## Temperature Parameters

### Target Temperature

- Recommended incubation temperature: **37.5°C**
- Acceptable operating range: **37.2°C – 37.8°C**

### Safety Limits

- Minimum safe temperature: **36.5°C**
- Maximum safe temperature: **39.0°C**

Deviation beyond safety limits triggers alerts and fail-safe actions.


## Humidity Parameters

### Recommended Humidity Levels

- Early to mid incubation: **45% – 55% RH**
- Final incubation (last 3 days): **65% – 70% RH**

Humidity control helps prevent dehydration or excess moisture within the eggs.


## Egg Turning Parameters

- Turning interval: **Every 4 hours**
- Turning angle: **Approximately 45° per side**
- Turning stops during final incubation phase

Regular turning prevents embryo adhesion to the shell.


## Ventilation Parameters

- Continuous low-level airflow
- Increased ventilation if:
  - Temperature rises above target
  - Humidity exceeds set limits

Proper ventilation ensures adequate oxygen supply and heat distribution.


## Parameter Storage & Configuration

Parameters may be:
- Defined as constants in firmware
- Stored in non-volatile memory
- Updated through user interface or Wi-Fi (future feature)

This allows flexibility for different incubation requirements.


## Parameter Validation

Before applying parameters:
- Values are checked for valid ranges
- Conflicting settings are prevented
- Safety thresholds override user-defined values

This prevents misconfiguration.


## Species Customization (Future)

The system is designed to support different egg types:

| Species | Temp (°C) | Humidity (%) | Turning Interval |
|-------|----------|--------------|------------------|
| Chicken | 37.5 | 45–55 | 4 hours |
| Duck | 37.2 | 50–60 | 4 hours |
| Quail | 37.7 | 45–55 | 3 hours |


## Integration with Control Logic

Incubation parameters are used by:
- Temperature control algorithm
- Humidity and ventilation logic
- Egg turning scheduler
- Alert and fault detection logic

Any parameter change immediately affects system behavior.


## Summary

Well-defined incubation parameters are essential for reliable and repeatable
hatching results.  
The HatchMate system applies these parameters systematically while maintaining
safety, flexibility, and expandability.
