#include <Arduino.h>
#include "alerts.h"
#include "sensors.h"
#include "actuators.h"
#include "display.h"
#include "config.h"

static bool alertActiveFlag = false;

void alertsUpdate() {
    float t = getTemperature();
    float h = getHumidity();

    if (t > TEMP_HIGH_LIMIT) {
        alertActiveFlag = true;
        heaterOff();
        fanOn();
        digitalWrite(ALARM_LED, HIGH);
        displayShowAlert("HIGH TEMP");
    }
    else if (t < TEMP_LOW_LIMIT) {
        alertActiveFlag = true;
        displayShowAlert("LOW TEMP");
    }
    else if (h < HUMIDITY_LOW_LIMIT) {
        alertActiveFlag = true;
        displayShowAlert("LOW HUMIDITY");
    }
    else {
        alertActiveFlag = false;
        digitalWrite(ALARM_LED, LOW);
    }
}

bool isAlertActive() {
    return alertActiveFlag;
}

