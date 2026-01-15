# Hardware Design

## Controller
- ESP32 (Wi-Fi enabled)

## Sensors
- Temperature sensor: DS18B20 / DHT22
- Humidity sensor: DHT22 / SHT20

## Actuators
- Heater (AC bulbs via relay)
- Fan (12V DC via relay)
- Humidifier / mist maker (via relay)
- Egg turner motor (via relay)

## User Interface
- Single OLED display (128×64, I2C)
- Push buttons:
  - Menu
  - Up
  - Down
  - Enter

## Alerts & Indicators
- Buzzer
- LEDs:
  - Power LED
  - Heater LED
  - Fan LED
  - Humidifier LED
  - Egg Turner LED
  - Alarm LED
  - Wi-Fi Status LED

## Connectivity
- Wi-Fi (ESP32 built-in)
- IoT dashboard / mobile app (Arduino IoT Cloud / Blynk / MQTT)

## Power System
- 12V DC adapter
- 5V voltage regulator for ESP32, OLED, and relay modules

