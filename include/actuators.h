#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <Arduino.h>

// ================= ACTUATOR INITIALIZATION =================
void initActuators();

// ================= HEATER =================
void heaterOn();
void heaterOff();

// ================= FAN =================
void fanOn();
void fanOff();

// ================= HUMIDIFIER =================
void humidifierOn();
void humidifierOff();

// ================= EGG TURNER =================
void turnerOn();
void turnerOff();

// ================= BUZZER =================
void beepShort();
void beepContinuous();

// ================= LEDS =================
void setAlarmLED(bool state);

#endif
