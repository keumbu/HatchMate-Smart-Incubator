#include "control_logic.h"
#include "sensors.h"
#include "actuators.h"
#include "config.h"
#include "display.h"
#include "utils.h"
#include <Arduino.h>

// Timing variables
unsigned long lastEggTurn = 0;
unsigned long dayStartMillis = 0;
int dayCounter = 1;

// Hatching mode flag
bool hatchingMode = false;

void updateDayCounter() {
    // Each day = 24 hours for simulation you can adjust
    if(millis() - dayStartMillis > 86400000) { // 24*60*60*1000 ms
        dayCounter++;
        dayStartMillis = millis();
    }
}

void controlTemperature() {
    float temp = getTemperature();
    if(temp < TEMP_TARGET - TEMP_TOLERANCE) {
        heaterOn();
        fanOff();
    } else if(temp > TEMP_TARGET + TEMP_TOLERANCE) {
        heaterOff();
        fanOn();
    }
}

void controlHumidity() {
    float hum = getHumidity();
    float targetHum = (dayCounter <= 18) ? HUMIDITY_DAY_1_18 : HUMIDITY_DAY_19_21;

    if(hum < targetHum) {
        humidifierOn();
    } else {
        humidifierOff();
    }
}

void handleEggTurning() {
    if(hatchingMode) return; // Do not turn eggs in hatching mode

    if(millis() - lastEggTurn > EGG_TURN_INTERVAL) {
        turnerOn();
        delay(5000); // 5s turn
        turnerOff();
        lastEggTurn = millis();
    }
}

void checkHatchingMode() {
    if(dayCounter >= 21 && !hatchingMode) {
        hatchingMode = true;
        turnerOff();
        heaterOff();
        humidifierOn(); // maintain 70% humidity
        showAlertScreen("HATCHING MODE");
        beepShort(); beepShort(); beepShort();
    }
}
