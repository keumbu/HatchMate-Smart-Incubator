#include "alerts.h"
#include "actuators.h"
#include "display.h"
#include "utils.h"
#include "config.h"

void checkAlerts(float temperature,float humidity,bool wifiStatus){
    if(temperature>TEMP_HIGH_LIMIT){ heaterOff(); fanOn(); digitalWrite(ALARM_LED,HIGH); beepContinuous(); showAlertScreen("HIGH TEMP"); return; }
    if(temperature<TEMP_LOW_LIMIT){ digitalWrite(ALARM_LED,HIGH); beepMultiple(2); showAlertScreen("LOW TEMP"); return; }
    if(humidity<HUMIDITY_DAY_1_18){ digitalWrite(ALARM_LED,HIGH); beepShort(); showAlertScreen("LOW HUMIDITY"); return; }
    if(!wifiStatus){ digitalWrite(WIFI_LED,HIGH); beepMultiple(2,300); showAlertScreen("Wi-Fi Lost"); return; }
    digitalWrite(ALARM_LED,LOW);
}

