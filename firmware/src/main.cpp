#include <Arduino.h>
#include "sensors.h"
#include "actuators.h"
#include "display.h"
#include "alerts.h"
#include "control_logic.h"

void setup() {
    Serial.begin(115200);
    actuatorsInit();
    sensorsInit();
    displayInit();
    controlInit();
}

void loop() {
    sensorsUpdate();
    controlUpdate();
    alertsUpdate();
    displayUpdate();
}
