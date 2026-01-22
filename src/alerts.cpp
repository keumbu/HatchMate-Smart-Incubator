#include "alerts.h"
#include "actuators.h"
#include "display.h"
#include "config.h"
#include "wifi_manager.h"

// ================= GLOBAL ALERT STATE =================
static bool alertActive = false;

// ================= INITIALIZATION =================
void initAlerts() {
    alertActive = false;
}

// ================= CHECK ALL ALERTS =================
void checkAlerts(float currentTemp, float currentHumid, bool wifiConnected) {

    // High temperature
    if (currentTemp > TEMP_HIGH_LIMIT) {
        highTemperatureAlert();
        return;
    }

    // Low temperature
    if (currentTemp < TEMP_LOW_LIMIT) {
        lowTemperatureAlert();
        return;
    }

    // Low humidity
    if (currentHumid < HUMIDITY_MIN_LIMIT) {
        lowHumidityAlert();
        return;
    }

    // Wi-Fi failure
    if (!wifiConnected) {
        wifiFailureAlert();
        return;
    }

    // No alerts active
    resetAlerts();
}

// ================= ALERT DEFINITIONS =================

void highTemperatureAlert() {
    alertActive = true;
    heaterOff();
    fanOn();
    setAlarmLED(true);
    beepContinuous();
    showAlertScreen("HIGH TEMP");  // OLED
    sendWiFiAlert("HIGH TEMPERATURE WARNING");  // Optional Wi-Fi
}

void lowTemperatureAlert() {
    alertActive = true;
    heaterOn();
    fanOff();
    setAlarmLED(true);
    beepShort();
    showAlertScreen("LOW TEMP");
    sendWiFiAlert("LOW TEMPERATURE WARNING");
}

void lowHumidityAlert() {
    alertActive = true;
    humidifierOn();
    setAlarmLED(true);
    beepShort();
    showAlertScreen("LOW HUMIDITY");
    sendWiFiAlert("LOW HUMIDITY WARNING");
}

void wifiFailureAlert() {
    alertActive = true;
    setAlarmLED(true);
    beepShort();
    showAlertScreen("Wi-Fi LOST");
}

// ================= RESET ALERTS =================
void resetAlerts() {
    alertActive = false;
    setAlarmLED(false);
    beepShort();
}
