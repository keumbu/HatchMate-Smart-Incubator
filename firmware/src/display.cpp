#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "display.h"
#include "sensors.h"
#include "control_logic.h"
#include "pins.h"
#include "alerts.h"

extern bool alert_state;
extern int dayCounter;

Adafruit_SSD1306 display(128,64,&Wire,-1);

// Rotation variables
unsigned long lastRotate = 0;
int screenIndex = 0;

void initDisplay() {
    display.begin(SSD1306_SWITCHCAPVCC,0x3C);
    display.clearDisplay();
}

void showStartupScreen() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0,0);
    display.print("HATCHMATE");
    display.display();
    delay(2000);
}

void updateDisplay() {
    if(alert_state) return;
    rotateScreens();
}

void showAlertScreen(const char* message) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0,0);
    display.print("ALERT");
    display.setCursor(0,15);
    display.print(message);
    display.display();
}

void rotateScreens() {
    if(millis() - lastRotate < DISPLAY_ROTATE_INTERVAL) return;
    lastRotate = millis();

    display.clearDisplay();
    display.setTextSize(1);

    switch(screenIndex) {
        case 0:
            display.setCursor(0,0);
            display.print("MAIN STATUS");
            display.setCursor(0,10);
            display.print("T: "); display.print(getTemperature()); display.print(" C");
            display.setCursor(0,20);
            display.print("H: "); display.print(getHumidity()); display.print(" %");
            display.setCursor(0,30);
            display.print("Day: "); display.print(dayCounter);
            break;
        case 1:
            display.setCursor(0,0);
            display.print("ACTUATORS");
            display.setCursor(0,10);
            display.print("HEATER: "); display.print(digitalRead(HEATER_RELAY)?"ON":"OFF");
            display.setCursor(0,20);
            display.print("FAN: "); display.print(digitalRead(FAN_RELAY)?"ON":"OFF");
            display.setCursor(0,30);
            display.print("HUMID: "); display.print(digitalRead(HUMIDIFIER_RELAY)?"ON":"OFF");
            display.setCursor(0,40);
            display.print("TURNER: "); display.print(digitalRead(TURNER_RELAY)?"ON":"OFF");
            break;
        case 2:
            display.setCursor(0,0);
            display.print("EGG TURNING");
            display.setCursor(0,10);
            display.print("Next turn: TBD");
            display.setCursor(0,20);
            display.print("Status: "); display.print(digitalRead(TURNER_RELAY)?"ON":"OFF");
            break;
        case 3:
            display.setCursor(0,0);
            display.print("HUMIDITY DETAIL");
            display.setCursor(0,10);
            display.print("Current: "); display.print(getHumidity());
            display.setCursor(0,20);
            display.print("Target: "); 
            display.print(dayCounter<=18?HUMIDITY_DAY_1_18:HUMIDITY_DAY_19_21);
            break;
        case 4:
            display.setCursor(0,0);
            display.print("TEMP DETAIL");
            display.setCursor(0,10);
            display.print("Current: "); display.print(getTemperature());
            display.setCursor(0,20);
            display.print("Target: "); display.print(TEMP_TARGET);
            break;
        case 5:
            display.setCursor(0,0);
            display.print("CONNECTIVITY");
            display.setCursor(0,10);
            display.print("WiFi: "); display.print(isWiFiConnected()?"CONNECTED":"LOST");
            break;
    }

    display.display();
    screenIndex = (screenIndex+1)%6;
}
