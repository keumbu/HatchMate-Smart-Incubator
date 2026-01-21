#include "sensors.h"
#include "pins.h"
#include "config.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// ================= GLOBAL OBJECTS =================
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature tempSensor(&oneWire);

// ================= GLOBAL VARIABLES =================
static float temperature = 0.0;
static float humidity = 0.0;
static unsigned long lastSensorRead = 0;

// ================= FUNCTION DEFINITIONS =================

// Initialize sensors
void initSensors() {
    tempSensor.begin();
    // Optionally add DHT22 init here if used
}

// Read temperature & humidity
void readSensors() {
    if (millis() - lastSensorRead >= SENSOR_READ_INTERVAL) {
        // Read temperature from DS18B20
        tempSensor.requestTemperatures();
        temperature = tempSensor.getTempCByIndex(0);

        // Placeholder humidity (replace with DHT22/SHT logic later)
        humidity = 55.0;

        lastSensorRead = millis();
    }
}

// Return last read temperature
float getTemperature() {
    return temperature;
}

// Return last read humidity
float getHumidity() {
    return humidity;
}
