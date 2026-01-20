#pragma once

// Temperature (°C)
#define TEMP_TARGET 37.5
#define TEMP_TOLERANCE 0.5
#define TEMP_HIGH_LIMIT 38.5
#define TEMP_LOW_LIMIT 35.0

// Humidity (%)
#define HUMIDITY_DAY_1_18 55
#define HUMIDITY_DAY_19_21 70

// Timing
#define SENSOR_READ_INTERVAL 2000
#define DISPLAY_ROTATE_INTERVAL 5000
#define DATA_SEND_INTERVAL 300000  // 5 minutes
