#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>

// ================= BUZZER HELPERS =================
void beepShort();        // Short beep
void beepContinuous();   // Continuous beep
void beepMultiple(uint8_t times, uint16_t duration = 100); // Multiple beeps

// ================= TIME HELPERS =================
// Convert seconds to HH:MM format
String secondsToHHMM(unsigned long seconds);

#endif
