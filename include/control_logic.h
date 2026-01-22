#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

#include <Arduino.h>

// ================= CONTROL FUNCTIONS =================
void controlTemperature(float currentTemp);
void controlHumidity(float currentHumid);
void handleEggTurning(unsigned long currentMillis, unsigned long &lastTurnTime);

// Optional: main control loop (can be called from main.cpp)
void controlLoop(unsigned long currentMillis, unsigned long &lastTurnTime);

#endif

