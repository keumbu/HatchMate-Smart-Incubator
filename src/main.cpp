#include "wifi_manager.h"
#include "actuators.h"
#include "sensors.h"
#include "display.cpp"
#include "control_logic.cpp"
#include "utils.h"
#include "config.h"
#include "alerts.cpp"
void setup() {
    Serial.begin(115200);
    initWiFi();   // Initialize Wi-Fi
    initActuators();
    initSensors();
    initDisplay();
    showStartupScreen();
    beepShort();
}
unsigned long lastTurnTime = 0;

void loop() {
    readSensors();
    
    controlTemperature(getTemperature());
    controlHumidity(getHumidity());
    handleEggTurning(millis(), lastTurnTime);
    println 

    checkAlerts(getTemperature(), getHumidity(), isWiFiConnected());

    // Reconnect Wi-Fi if lost
    if (!isWiFiConnected()) {
        reconnectWiFi();
    }

    updateDisplay(); // Show Wi-Fi status on OLED
}
