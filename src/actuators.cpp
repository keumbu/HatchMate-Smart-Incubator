#include "actuators.h"
#include "pins.h"
#include <Arduino.h>

void initActuators() {
    pinMode(HEATER_RELAY, OUTPUT);
    pinMode(FAN_RELAY, OUTPUT);
    pinMode(HUMIDIFIER_RELAY, OUTPUT);
    pinMode(TURNER_RELAY, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(ALARM_LED, OUTPUT);
    pinMode(WIFI_LED, OUTPUT);
}

void heaterOn() { digitalWrite(HEATER_RELAY, HIGH); }
void heaterOff() { digitalWrite(HEATER_RELAY, LOW); }
void fanOn() { digitalWrite(FAN_RELAY, HIGH); }
void fanOff() { digitalWrite(FAN_RELAY, LOW); }
void humidifierOn() { digitalWrite(HUMIDIFIER_RELAY, HIGH); }
void humidifierOff() { digitalWrite(HUMIDIFIER_RELAY, LOW); }
void turnerOn() { digitalWrite(TURNER_RELAY, HIGH); }
void turnerOff() { digitalWrite(TURNER_RELAY, LOW); }
