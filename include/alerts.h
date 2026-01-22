#ifndef ALERTS_H
#define ALERTS_H

#include <Arduino.h>

// ================= ALERT FUNCTIONS =================

// Initialize alert system (if needed)
void initAlerts();

// Check all alerts: temperature, humidity, Wi-Fi
void checkAlerts(float currentTemp, float currentHumid, bool wifiConnected);

// Alert triggers
void highTemperatureAlert();
void lowTemperatureAlert();
void lowHumidityAlert();
void wifiFailureAlert();

// Reset alerts
void resetAlerts();

#endif


