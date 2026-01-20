#include <Arduino.h>
#include "sensors.h"
#include "actuators.h"
#include "display.h"
#include "wifi_manager.h"
#include "alerts.h"
#include "control_logic.h"
#include "utils.h"

void setup() {
    Serial.begin(115200);

    initActuators();
    initSensors();
    initDisplay();
    initWiFi();

    showStartupScreen();
    beepShort();
}

void loop() {
    readSensors();
    updateDayCounter();
    controlTemperature();
    controlHumidity();
    handleEggTurning();
    checkHatchingMode();
    checkAlerts();
    updateDisplay();
    delay(500);
}
