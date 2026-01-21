#ifndef CONFIG_H
#define CONFIG_H

// ================= SYSTEM CONSTANTS =================

// Temperature
#define TEMP_TARGET         37.5  // Target incubation temperature °C
#define TEMP_TOLERANCE      0.5   // ± tolerance
#define TEMP_HIGH_LIMIT     38.5  // High temp alert
#define TEMP_LOW_LIMIT      35.0  // Low temp alert

// Humidity
#define HUMIDITY_DAY_1_18   55.0  // %
#define HUMIDITY_DAY_19_21  70.0  // %

#define SENSOR_READ_INTERVAL 2000 // ms between sensor reads
#define EGG_TURN_INTERVAL   7200000 // 2 hours in ms

// OLED rotation
#define OLED_ROTATE_INTERVAL 5000 // 5 seconds

#endif



