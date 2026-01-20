#include <Arduino.h>
#include "utils.h"
#include "pins.h"

void beepShort(){
    digitalWrite(BUZZER_PIN,HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN,LOW);
}

void beepTriple(){
    for(int i=0;i<3;i++){
        beepShort();
        delay(150);
    }
}
