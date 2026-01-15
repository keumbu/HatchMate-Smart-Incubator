# Main Control Loop (Continuous)

## Sensor Acquisition
• Read temperature
• Read humidity
• Validate sensor data
• Update OLED variable
• Send periodic data to dashboard(every 5 minutes)

## Temperature Control
• If temperature < 37.0°C
◦ Heater ON
◦ Heater LED ON
◦ Fan OFF

• If temperature > 38.0°C
◦ Heater OFF
◦ Fan ON
◦ Fan LED ON

• Else :
◦ Maintain current state

## Humidity Control
• If Day ≤ 18 → Target = 50-55%
• If Day ≥ 19 → Target = 65-70%
• If humidity < target
◦ Humidifier ON
◦ Humidifier LED ON

• Else
◦ Humidifier OFF

## Egg Turning Control

• Start after first 24 hours

• If Day ≤ 18 AND turn interval reached:
◦ Egg turner ON (5-10 sec)
◦ Egg turner LED ON
◦ Egg turner OFF
◦ Reset timer
◦ Send Wi-Fi alert: “Egg Turned”

• If Day ≥ 19:
◦ Egg turning DISABLED
◦ Display: “LOCKDOWN MODE”

## Day Counter
• Every 24 hours:
◦ Day = Day + 1
◦ OLED update
◦ Short buzzer beep
◦ Wi-Fi alert: “Incubation Day x Started”
