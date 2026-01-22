#include "control_logic.h"
#include "config.h"
#include "sensors.h"
#include "actuators.h"

// ================= TEMPERATURE CONTROL =================
void controlTemperature(float currentTemp) {
    if (currentTemp < (TEMP_TARGET - TEMP_TOLERANCE)) {
        heaterOn();
        fanOff();
    } 
    else if (currentTemp > (TEMP_TARGET + TEMP_TOLERANCE)) {
        heaterOff();
        fanOn();
    } 
    else {
        // Maintain current state
        heaterOff();
        fanOff();
    }
}

// ================= HUMIDITY CONTROL =================
void controlHumidity(float currentHumid) {
    // Day 1-18: normal humidity
    if (currentHumid < HUMIDITY_DAY_1_18) {
        humidifierOn();
    } else {
        humidifierOff();
    }

    // For day 19-21, you can add logic in main.cpp to change target
}

// ================= EGG TURNING CONTROL =================
void handleEggTurning(unsigned long currentMillis, unsigned long &lastTurnTime) {
    if (currentMillis - lastTurnTime >= EGG_TURN_INTERVAL) {
        turnerOn();
        delay(5000); // Turn eggs for 5 seconds (adjust if needed)
        turnerOff();
        lastTurnTime = currentMillis;
    }
}

// ================= OPTIONAL CONTROL LOOP =================
void controlLoop(unsigned long currentMillis, unsigned long &lastTurnTime) {
    float temp = getTemperature();
    float humid = getHumidity();

    controlTemperature(temp);
    controlHumidity(humid);
    handleEggTurning(currentMillis, lastTurnTime);
}

