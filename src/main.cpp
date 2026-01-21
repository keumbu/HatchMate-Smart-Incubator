#include <Arduino.h>
#include "sensors.h"
#include "actuators.h"
#include "display.h"
#include "wifi_manager.h"
#include "alerts.h"
#include "control_logic.h"
#include "utils.h"

int CURRENT_DAY = 7; 
unsigned long lastTurnTime = 0;

void setup(){
    Serial.begin(115200);
    initActuators();
    initSensors();
    initDisplay();
    initWiFi();
    showStartupScreen();
    beepShort();
}

void loop(){
    readSensors();
    controlTemperature(getTemperature());
    controlHumidity(getHumidity(), CURRENT_DAY);
    handleEggTurning(lastTurnTime, CURRENT_DAY);
    checkAlerts(getTemperature(), getHumidity(), isWiFiConnected());
    updateDisplay();
}
