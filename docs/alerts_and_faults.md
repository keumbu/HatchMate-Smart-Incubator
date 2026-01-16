# Alert, Buzzer & safety Logic 

The HatchMate Smart Incubator includes a robust safety and alert system to protect eggs and notify the user of abnormal conditions. Alerts are presented through OLED messages, LEDs, buzzer patterns, and Wi‑Fi notifications. Critical alerts take priority over normal display rotation.

## High Temperature Alert

Trigger Condition:

Temperature > 38.5°C

System Response:

Heater OFF

Fan ON (forced cooling)

Alarm LED BLINKING

Buzzer CONTINUOUS tone

OLED switches to Alert Screen

OLED Alert Screen:

HIGH TEMP
39.8°C
Cooling...

Remote Notification:

Wi‑Fi / Cloud alert message:

“HIGH TEMPERATURE WARNING”

Safety Note:

Cooling remains active until temperature returns to safe range

## Low Temperature Alert

Trigger Condition:

Temperature < 35.0°C

System Response:

Alarm LED BLINKING

Buzzer INTERMITTENT beeps

OLED displays low temperature alert

OLED Alert Screen:

LOW TEMP
34.6°C
Heating...

Remote Notification:

Wi‑Fi / Cloud alert message:

“LOW TEMPERATURE WARNING”

## Low Humidity 

Trigger Condition:

Humidity below minimum threshold for current incubation day

System Response:

Alarm LED BLINKING

Buzzer SHORT periodic beep

OLED displays humidity alert

OLED Alert Screen:

LOW HUMIDITY
45%
Misting...

Remote Notification:

Wi‑Fi / Cloud alert message:

“LOW HUMIDITY WARNING”

## Wi‑Fi Failure Alert

Trigger Condition:

Wi‑Fi disconnected or lost

System Response:

Wi‑Fi LED FAST BLINKING

Buzzer DOUBLE deep beep (non‑continuous)

OLED displays Wi‑Fi status message

OLED Status Screen:

Wi‑Fi LOST
Offline Mode

Operational Behavior:

Incubator continues NORMAL autonomous operation

All temperature, humidity, and egg turning controls remain active

Data synchronization resumes automatically once Wi‑Fi reconnects

## Alert Priority Rules

Alert screens override normal OLED rotation

Only one alert is displayed at a time

Priority order:

High Temperature

Low Temperature

Low Humidity

Wi‑Fi Failure

## Buzzer Pattern 

Condition	Buzzer Pattern
High Temperature	Continuous tone
Low Temperature	Intermittent beep
Low Humidity	Short periodic beep
Wi‑Fi Failure	Double deep beep

Design Philosophy:

Safety‑critical alerts are loud and persistent

Non‑critical alerts are informative but non‑disruptive

The incubator never stops control operations due to Wi‑Fi failure
