#include <OneWire.h>
#include <DallasTemperature.h>
#include "sensors.h"
#include "pins.h"
#include "config.h"

static OneWire oneWire(ONE_WIRE_BUS);
static DallasTemperature tempSensor(&oneWire);

static float temperature = 0;
static float humidity = 55;
static unsigned long lastRead = 0;

void sensorsInit() {
    tempSensor.begin();
}

void sensorsUpdate() {
    if (millis() - lastRead >= SENSOR_READ_INTERVAL) {
        tempSensor.requestTemperatures();
        temperature = tempSensor.getTempCByIndex(0);
        humidity = humidity; // replace when DHT/SHT added
        lastRead = millis();
    }
}

float getTemperature() { return temperature; }
float getHumidity() { return humidity; }

bool sensorsHealthy() {
    return temperature != DEVICE_DISCONNECTED_C;
}
