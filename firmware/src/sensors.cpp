#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include "sensors.h"
#include "pins.h"
#include "config.h"

// ================= INTERNAL OBJECTS =================
static OneWire oneWire(ONE_WIRE_BUS);
static DallasTemperature tempSensor(&oneWire);

// ================= INTERNAL VARIABLES =================
static float temperature = 0.0;
static float humidity = 0.0;
static unsigned long lastRead = 0;

// ================= FUNCTIONS =================
void initSensors() {
    tempSensor.begin();
}

void readSensors() {
    if (millis() - lastRead >= SENSOR_READ_INTERVAL) {
        tempSensor.requestTemperatures();
        temperature = tempSensor.getTempCByIndex(0);

        // Placeholder (replace later with DHT/SHT sensor)
        humidity = 55.0;

        lastRead = millis();
    }
}

float getTemperature() {
    return temperature;
}

float getHumidity() {
    return humidity;
}
