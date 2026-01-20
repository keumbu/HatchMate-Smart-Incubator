#include <Arduino.h>
#include "alerts.h"
#include "sensors.h"
#include "actuators.h"
#include "display.h"
#include "utils.h"
#include "config.h"
#include "pins.h"
#include "wifi_manager.h"

bool alert_state = false;

bool alertActive() { return alert_state; }

void checkAlerts() {
    float temp = getTemperature();
    float hum = getHumidity();

    if(temp > TEMP_HIGH_LIMIT) {
        alert_state = true;
        heaterOff();
        fanOn();
        digitalWrite(ALARM_LED,HIGH);
        showAlertScreen("HIGH TEMP");
        beepContinuous();
    } else if(temp < TEMP_LOW_LIMIT) {
        alert_state = true;
        digitalWrite(ALARM_LED,HIGH);
        showAlertScreen("LOW TEMP");
        beepShort();
    } else if(hum < HUMIDITY_DAY_1_18) {
        alert_state = true;
        digitalWrite(ALARM_LED,HIGH);
        showAlertScreen("LOW HUMIDITY");
        beepShort();
    } else if(!isWiFiConnected()) {
        alert_state = true;
        digitalWrite(WIFI_LED, HIGH); // fast blink placeholder
        showAlertScreen("Wi-Fi Lost");
        beepShort(); beepShort();
    } else {
        alert_state = false;
        digitalWrite(ALARM_LED, LOW);
        digitalWrite(WIFI_LED, HIGH);
    }
}
