#include <Arduino.h>
#include "control_logic.h"
#include "sensors.h"
#include "actuators.h"
#include "config.h"

static unsigned long lastTurn = 0;
static uint8_t day = 1;

void controlInit() {
    lastTurn = millis();
}

void controlUpdate() {
    float t = getTemperature();
    float h = getHumidity();

    if (t < TEMP_TARGET - TEMP_TOLERANCE) {
        heaterOn(); fanOff();
    } else if (t > TEMP_TARGET + TEMP_TOLERANCE) {
        heaterOff(); fanOn();
    }

    if (day <= 18) {
        if (h < HUMIDITY_DAY_1_18) humidifierOn();
        else humidifierOff();

        if (millis() - lastTurn >= EGG_TURN_INTERVAL) {
            turnerOn();
            delay(3000);
            turnerOff();
            lastTurn = millis();
        }
    }
    else {
        humidifierOn();  // hatching mode
        turnerOff();
    }
}
