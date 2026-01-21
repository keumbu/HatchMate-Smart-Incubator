#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

void beepShort();
void beepContinuous();
void beepMultiple(uint8_t times, uint16_t duration = 100);
String secondsToHHMM(unsigned long seconds);

#endif

