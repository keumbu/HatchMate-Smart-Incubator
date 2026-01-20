#include <Arduino.h>
#include "sensors.h"

void setup() {
    Serial.begin(115200);
    initSensors();
}

void loop() {
    readSensors();
    Serial.print("Temp: ");
    Serial.print(getTemperature());
    Serial.print(" °C | Humidity: ");
    Serial.println(getHumidity());
    delay(2000);
}
