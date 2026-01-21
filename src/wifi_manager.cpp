#include "wifi_manager.h"
#include <Arduino.h>
#include "pins.h"

void initWiFi(){ pinMode(WIFI_LED,OUTPUT); digitalWrite(WIFI_LED,HIGH); }

bool isWiFiConnected(){ return true; } // placeholder

void reconnectWiFi(){ Serial.println("Reconnecting Wi-Fi..."); }
void sendWiFiAlert(const char* message){ Serial.print("Wi-Fi Alert: "); Serial.println(message); }