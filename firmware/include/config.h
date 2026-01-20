#ifndef CONFIG_H
#define CONFIG_H

// ---- Incubation Parameters ----
#define TEMP_TARGET           37.5
#define TEMP_TOLERANCE        0.5
#define TEMP_HIGH_LIMIT       38.5
#define TEMP_LOW_LIMIT        35.0

#define HUMIDITY_DAY_1_18     55
#define HUMIDITY_DAY_19_21    70
#define HUMIDITY_LOW_LIMIT   45

#define INCUBATION_DAYS       21

// ---- Timings (ms) ----
#define SENSOR_READ_INTERVAL  2000
#define DISPLAY_ROTATE_TIME   5000
#define EGG_TURN_INTERVAL     7200000UL   // 2 hours

#endif
