#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

// Initialize sensors
void initSensors();

// Read all sensor values
void readSensors();

// Get latest temperature
float getTemperature();

// Get latest humidity
float getHumidity();

#endif

