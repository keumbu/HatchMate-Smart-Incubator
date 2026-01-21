#include "control_logic.h"
#include "actuators.h"
#include "config.h"
#include "utils.h"

void handleEggTurning(unsigned long &lastTurnTime,int currentDay){
    unsigned long now = millis();
    if(currentDay>DAY_STOP_EGG_TURN){ turnerOff(); return; }
    if(now - lastTurnTime >= EGG_TURN_INTERVAL*1000UL){
        turnerOn(); delay(TURNER_DURATION_MS); turnerOff();
        lastTurnTime = now;
    }
}

void controlTemperature(float temperature){
    if(temperature < (TEMP_TARGET-TEMP_TOLERANCE)){ heaterOn(); fanOff(); }
    else if(temperature > (TEMP_TARGET+TEMP_TOLERANCE)){ heaterOff(); fanOn(); }
    else{ heaterOff(); fanOff(); }
}

void controlHumidity(float humidity,int day){
    if(day<=18){
        if(humidity<HUMIDITY_DAY_1_18) humidifierOn(); else humidifierOff();
    }else{
        if(humidity<HUMIDITY_DAY_19_21) humidifierOn(); else humidifierOff();
    }
}
