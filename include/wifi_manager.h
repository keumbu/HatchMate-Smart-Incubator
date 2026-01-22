#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>
#include <WiFi.h>

// Initialize Wi-Fi
void initWiFi();

// Check if Wi-Fi is connected
bool isWiFiConnected();

// Attempt reconnect if disconnected
void reconnectWiFi();

// Optional: send alert message (placeholder)
void sendWiFiAlert(const char* message);

#endif


