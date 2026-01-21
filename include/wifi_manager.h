#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

bool isWiFiConnected();
void initWiFi();
void reconnectWiFi();
void sendWiFiAlert(const char* message);

#endif

