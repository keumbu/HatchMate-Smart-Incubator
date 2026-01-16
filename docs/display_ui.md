# OLED Display UI Logic (Single OLED)

## OLED DISPLAY LOGIC (SINGLE OLED)

The HatchMate Smart Incubator uses a single 128×64 I2C OLED display to present real-time system information. The display cycles through multiple screens automatically, providing clear visibility of system status without user interaction.

## OLED SCREEN PAGES

The OLED uses multiple rotating screens, switching automatically every 5–8 seconds.

SCREEN 1 – MAIN STATUS (DEFAULT)
HATCHMATE
T: 37.5°C   H: 55%
Day: 07/21
Mode: INC   Wi-Fi ✓

Description:

Displays incubator name

Current temperature and humidity

Incubation day progress

Incubation mode and Wi‑Fi status

SCREEN 2 – ACTUATORS STATUS
ACTUATORS
HEATER: ON
FAN: OFF
HUMID: ON
TURNER: OFF

Description:

Shows current ON/OFF state of all actuators

SCREEN 3 – EGG TURNING STATUS
EGG TURNING
Status: ENABLED
Next turn: 01:20
Stop at Day 18

Description:

Indicates if egg turning is active

Countdown to next turning cycle

Automatic stop day

SCREEN 4 – HUMIDITY DETAIL
HUMIDITY
Current: 52%
Target: 55%
Mist: ON

Description:

Displays humidity control details

Shows humidifier state

SCREEN 5 – TEMPERATURE DETAIL
TEMPERATURE
Current: 37.5°C
Target: 37.5°C
State: STABLE

Description:

Shows temperature regulation status

Indicates system stability

SCREEN 6 – CONNECTIVITY STATUS
CONNECTIVITY
Wi-Fi: CONNECTED
Cloud: SYNC OK
Last send: 3m

Description:

Displays Wi‑Fi connection status

Cloud synchronization state

Time since last data upload

## OLED ROTATION ALGORITHM

The display rotation is managed automatically by the ESP32 firmware.

Rotation Rules:

Switch screens every 5 seconds

Pause (freeze) rotation when:

An alert condition is active

A user button is pressed (optional feature)

Logic Flow (Pseudocode):

IF alert_active == TRUE
    display ALERT_SCREEN
ELSE
    display current_screen
    every 5 seconds → next screen
ENDIF

Design Notes:

Alert screens always take priority

Rotation resumes automatically after alert clearance

OLED content is optimized for clarity and low power consumption
