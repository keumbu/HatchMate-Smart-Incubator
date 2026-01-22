#include "wifi_manager.h"

void setup() {
    Serial.begin(115200);
    initWiFi();   // Initialize Wi-Fi
    initActuators();
    initSensors();
    initDisplay();
    showStartupScreen();
    beepShort();
}

void loop() {
    readSensors();
    
    controlTemperature(getTemperature());
    controlHumidity(getHumidity());
    handleEggTurning(millis(), lastTurnTime);

    checkAlerts(getTemperature(), getHumidity(), isWiFiConnected());

    // Reconnect Wi-Fi if lost
    if (!isWiFiConnected()) {
        reconnectWiFi();
    }

    updateDisplay(); // Show Wi-Fi status on OLED
}
