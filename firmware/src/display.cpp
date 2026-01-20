#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "display.h"
#include "sensors.h"
#include "alerts.h"

static Adafruit_SSD1306 oled(128,64,&Wire,-1);
static uint8_t screen = 0;
static unsigned long lastRotate = 0;

void displayInit() {
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    oled.clearDisplay();
}

void displayUpdate() {
    if (isAlertActive()) return;

    if (millis() - lastRotate >= 5000) {
        screen = (screen + 1) % 6;
        lastRotate = millis();
    }

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setCursor(0,0);

    if(screen==0){
        oled.print("HATCHMATE\n");
        oled.print("T:"); oled.print(getTemperature());
        oled.print(" H:"); oled.print(getHumidity());
    }
    else if(screen==1){
        oled.print("ACTUATORS");
    }
    else if(screen==2){
        oled.print("EGG TURNING");
    }
    else if(screen==3){
        oled.print("HUMIDITY");
    }
    else if(screen==4){
        oled.print("TEMPERATURE");
    }
    else{
        oled.print("WIFI STATUS");
    }

    oled.display();
}

void displayShowAlert(const char* msg) {
    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.print("ALERT\n");
    oled.print(msg);
    oled.display();
}
