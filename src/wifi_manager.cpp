#include "wifi_manager.h"
#include "pins.h"
#include "config.h"

// ================= INIT =================
void initWiFi() {
    pinMode(WIFI_LED, OUTPUT);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_CONNECT_TIMEOUT) {
        digitalWrite(WIFI_LED, millis() % 500 < 250); // Blink while connecting
        delay(100);
    }

    if (WiFi.status() == WL_CONNECTED) {
        digitalWrite(WIFI_LED, HIGH); // Solid LED when connected
    } else {
        digitalWrite(WIFI_LED, LOW); // LED off if failed
    }
}

// ================= CHECK STATUS =================
bool isWiFiConnected() {
    return WiFi.status() == WL_CONNECTED;
}

// ================= RECONNECT =================
void reconnectWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        WiFi.disconnect();
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

        unsigned long startAttemptTime = millis();
        while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_CONNECT_TIMEOUT) {
            digitalWrite(WIFI_LED, millis() % 500 < 250); // Blink while reconnecting
            delay(100);
        }

        if (WiFi.status() == WL_CONNECTED) {
            digitalWrite(WIFI_LED, HIGH);
        } else {
            digitalWrite(WIFI_LED, LOW);
        }
    }
}

// ================= SEND ALERT =================
void sendWiFiAlert(const char* message) {
    // Placeholder: integrate with your IoT platform (Arduino IoT Cloud, Blynk, MQTT, etc.)
    Serial.print("Wi-Fi Alert: ");
    Serial.println(message);
}
