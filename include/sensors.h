#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// ================= SENSOR FUNCTIONS =================

// Initialize sensors
void initSensors();

// Read all sensor values (temperature & humidity)
void readSensors();

// Get latest temperature value
float getTemperature();

// Get latest humidity value
float getHumidity();

#endif

