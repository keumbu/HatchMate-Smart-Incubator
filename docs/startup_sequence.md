# System Startup Sequence

1. Power ON system
2. Power LED turns ON
3. Initialize:
   - ESP32
   - Sensors
   - Relays
   - OLED display
   - LEDs
   - Buzzer
   - Time / RTC
4. Initialize Wi-Fi:
   - Wi-Fi LED blinks while connecting
   - Wi-Fi LED stays ON when connected
5. Send Wi-Fi message:
   - “HatchMate Incubator Started”
6. Set control parameters:
   - Target temperature = 37.5°C
   - Temperature tolerance = ±0.5°C
   - Day counter = 1
7. OLED main status screen displays:
   - Temperature
   - Humidity
   - Day
   - Wi-Fi status
8. Short buzzer beep indicates system ready

