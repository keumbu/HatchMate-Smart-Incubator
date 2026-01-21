#include "sensors.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include "pins.h"
#include "config.h"

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature tempSensor(&oneWire);

float temperature = 0.0;
float humidity = 0.0;
unsigned long lastSensorRead = 0;

void initSensors() { tempSensor.begin(); }

void readSensors() {
    if (millis() - lastSensorRead >= SENSOR_READ_INTERVAL) {
        tempSensor.requestTemperatures();
        temperature = tempSensor.getTempCByIndex(0);
        humidity = 55.0;
        lastSensorRead = millis();
    }
}

float getTemperature() { return temperature; }
float getHumidity() { return humidity; }
