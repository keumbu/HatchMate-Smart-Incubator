#ifndef SENSORS_H
#define SENSORS_H

void sensorsInit();
void sensorsUpdate();
float getTemperature();
float getHumidity();
bool sensorsHealthy();

#endif
