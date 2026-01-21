#include "display.h"
#include "sensors.h"
#include "utils.h"
#include "actuators.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128,64,&Wire,-1);

void initDisplay(){ display.begin(SSD1306_SWITCHCAPVCC,0x3C); display.clearDisplay(); }

void showStartupScreen(){ display.clearDisplay(); display.setTextSize(1); display.setCursor(0,0); display.print("HATCHMATE"); display.display(); delay(2000); }

void updateDisplay(){
    static unsigned long lastRotate=0; static uint8_t screenIndex=0;
    unsigned long now=millis();
    if(now - lastRotate>=OLED_ROTATION_INTERVAL){ screenIndex=(screenIndex+1)%6; lastRotate=now; }

    display.clearDisplay();
    switch(screenIndex){
        case 0: display.setCursor(0,0); display.print("T:"); display.print(getTemperature()); display.print(" C");
                display.setCursor(0,10); display.print("H:"); display.print(getHumidity()); display.print(" %"); break;
        case 1: display.setCursor(0,0); display.print("HEATER:"); display.print(digitalRead(HEATER_RELAY)?"ON":"OFF");
                display.setCursor(0,10); display.print("FAN:"); display.print(digitalRead(FAN_RELAY)?"ON":"OFF");
                display.setCursor(0,20); display.print("HUMID:"); display.print(digitalRead(HUMIDIFIER_RELAY)?"ON":"OFF");
                display.setCursor(0,30); display.print("TURNER:"); display.print(digitalRead(TURNER_RELAY)?"ON":"OFF"); break;
        case 2: display.setCursor(0,0); display.print("EGG TURNING\nNext:"); display.print(secondsToHHMM(EGG_TURN_INTERVAL)); display.print("\nStop Day 18"); break;
        case 3: display.setCursor(0,0); display.print("HUMIDITY\nCurrent:"); display.print(getHumidity()); display.print("%\nTarget:"); display.print(HUMIDITY_DAY_1_18); break;
        case 4: display.setCursor(0,0); display.print("TEMPERATURE\nCurrent:"); display.print(getTemperature()); display.print(" C\nTarget:"); display.print(TEMP_TARGET); break;
        case 5: display.setCursor(0,0); display.print("Wi-Fi: CONNECTED\nCloud: SYNC OK"); break;
    }
    display.display();
}

void showAlertScreen(const char* message){ display.clearDisplay(); display.setCursor(0,0); display.print("ALERT"); display.setCursor(0,15); display.print(message); display.display(); }
