# Testing & Calibration

## Overview

This document describes the testing and calibration procedures used to verify
the correct operation of the HatchMate smart incubator.  
Systematic testing ensures reliability, accuracy, and safety during real-world
incubation.


## Testing Objectives

The testing process aims to:
- Validate correct hardware operation
- Verify sensor accuracy
- Confirm control logic behavior
- Ensure safe response to faults
- Evaluate system stability over time


## Test Environment

Testing was performed under controlled conditions using:
- Regulated 12V DC power supply
- Known temperature reference sources
- Ambient room conditions
- Simulated fault scenarios


## Hardware Verification Tests

### Power Supply Test
- Verify correct 12V output
- Confirm stable 5V and 3.3V regulation
- Check for voltage drops under load

**Pass criteria:** Stable voltage within tolerance.


### Relay & Actuator Test
- Manually toggle relays via firmware
- Verify heater, fan, and motor activation
- Observe isolation between control and load circuits

**Pass criteria:** Correct switching without MCU reset or noise issues.


## Sensor Testing

### Temperature Sensor Test
1. Compare sensor readings with a reference thermometer
2. Observe readings at different temperatures
3. Check for stable and repeatable output

**Pass criteria:** Reading within acceptable error margin.


### Humidity Sensor Test
1. Compare sensor output with known humidity conditions
2. Monitor response to moisture changes

**Pass criteria:** Consistent and responsive readings.


## Sensor Calibration

### Temperature Calibration
- Offset values applied in firmware
- Calibration performed at typical incubation temperature

### Humidity Calibration
- Adjustment factors applied based on reference comparison

Calibration constants are stored in firmware and applied during runtime.


## Functional Testing

### Temperature Control Test
- Set target temperature
- Observe heater ON/OFF behavior
- Verify stable temperature maintenance


### Humidity Control Test
- Observe ventilation response to humidity changes
- Verify alerts when limits are exceeded


### Egg Turning Test
- Verify turning interval accuracy
- Confirm motor activation duration
- Ensure turning stops during final incubation phase


## Display & UI Testing

- Verify correct data display
- Check alert and fault message visibility
- Observe display refresh stability


## Fault Injection Testing

Simulated faults include:
- Sensor disconnection
- Over-temperature condition
- Startup failure

**Expected behavior:**
- Heating disabled
- Ventilation enabled
- Fault message displayed
- System enters safe state


## Long-Duration Stability Test

- System operated continuously for extended periods
- Observed for:
  - Sensor drift
  - Unexpected resets
  - Control instability

**Pass criteria:** Stable operation without faults.


## Calibration Validation

After calibration:
- Re-test sensor accuracy
- Confirm improved consistency
- Verify no negative impact on control logic


## Test Results Summary

| Test Category | Result |
|--------------|--------|
| Power & Hardware | Pass |
| Sensor Accuracy | Pass |
| Control Logic | Pass |
| Safety & Fault Handling | Pass |
| Display Functionality | Pass |


## Conclusion

Comprehensive testing and calibration confirm that the HatchMate incubator
operates reliably, safely, and within defined parameters.  
These procedures provide confidence in the system’s performance under real
incubation conditions.

