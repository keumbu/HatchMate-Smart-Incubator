// config.h
#ifndef CONFIG_H
#define CONFIG_H

// ================= TEMPERATURE =================
#define TEMP_TARGET          37.5    // Target incubation temperature (°C)
#define TEMP_TOLERANCE       0.5     // ± tolerance
#define TEMP_HIGH_LIMIT      38.5    // High temp alert
#define TEMP_LOW_LIMIT       35.0    // Low temp alert

// ================= HUMIDITY =================
#define HUMIDITY_DAY_1_18    55      // % for first 18 days
#define HUMIDITY_DAY_19_21   70      // % for last 3 days

// ================= EGG TURNING =================
#define EGG_TURN_INTERVAL    7200000UL // 2 hours in milliseconds

// ================= SENSOR READ =================
#define SENSOR_READ_INTERVAL 2000UL    // 2 seconds

// ================= DISPLAY =================
#define OLED_ROTATE_INTERVAL 5000UL    // 5 seconds per screen

// ================= BUZZER =================
#define BUZZER_SHORT_DELAY   100       // ms for short beep

#endif
