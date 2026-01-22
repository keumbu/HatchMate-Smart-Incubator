#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

// Initialize OLED display
void initDisplay();

// Show startup screen
void showStartupScreen();

// Update main rotating screens
void updateDisplay();

// Show alert screen with custom message
void showAlertScreen(const char* message);

// Optional: override screen during alert
void freezeDisplay();
void resumeDisplay();

#endif
