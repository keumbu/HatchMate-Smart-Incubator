#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

void controlTemperature(float temperature);
void controlHumidity(float humidity, int day);
void handleEggTurning(unsigned long &lastTurnTime, int currentDay);

#endif

