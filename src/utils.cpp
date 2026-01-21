#include "utils.h"
#include "pins.h"
#include <Arduino.h>

void beepShort() { digitalWrite(BUZZER_PIN,HIGH); delay(100); digitalWrite(BUZZER_PIN,LOW); }
void beepContinuous() { digitalWrite(BUZZER_PIN,HIGH); }
void beepMultiple(uint8_t times, uint16_t duration){
    for(uint8_t i=0;i<times;i++){
        digitalWrite(BUZZER_PIN,HIGH); delay(duration);
        digitalWrite(BUZZER_PIN,LOW); delay(duration);
    }
}
String secondsToHHMM(unsigned long seconds){
    unsigned long h = seconds/3600;
    unsigned long m = (seconds%3600)/60;
    char buf[6]; sprintf(buf,"%02lu:%02lu",h,m);
    return String(buf);
}
