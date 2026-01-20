#include <Arduino.h>
#include "actuators.h"
#include "pins.h"

void actuatorsInit() {
    pinMode(HEATER_RELAY, OUTPUT);
    pinMode(FAN_RELAY, OUTPUT);
    pinMode(HUMIDIFIER_RELAY, OUTPUT);
    pinMode(TURNER_RELAY, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(ALARM_LED, OUTPUT);
    actuatorsAllOff();
}

void actuatorsAllOff() {
    digitalWrite(HEATER_RELAY, LOW);
    digitalWrite(FAN_RELAY, LOW);
    digitalWrite(HUMIDIFIER_RELAY, LOW);
    digitalWrite(TURNER_RELAY, LOW);
}

void heaterOn(){ digitalWrite(HEATER_RELAY, HIGH); }
void heaterOff(){ digitalWrite(HEATER_RELAY, LOW); }
void fanOn(){ digitalWrite(FAN_RELAY, HIGH); }
void fanOff(){ digitalWrite(FAN_RELAY, LOW); }
void humidifierOn(){ digitalWrite(HUMIDIFIER_RELAY, HIGH); }
void humidifierOff(){ digitalWrite(HUMIDIFIER_RELAY, LOW); }
void turnerOn(){ digitalWrite(TURNER_RELAY, HIGH); }
void turnerOff(){ digitalWrite(TURNER_RELAY, LOW); }
