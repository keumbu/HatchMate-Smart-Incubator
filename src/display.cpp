#includ#include "display.h"
#include "pins.h"
#include "config.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>

// ================= GLOBAL OBJECTS =================
Adafruit_SSD1306 display(128, 64, &Wire, -1);

// ================= GLOBAL VARIABLES =================
static unsigned long lastScreenSwitch = 0;
static uint8_t currentScreen = 0;
static bool displayFrozen = false;

// ================= INITIALIZATION =================
void initDisplay() {
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.display();
}

// ================= STARTUP SCREEN =================
void showStartupScreen() {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(10, 20);
    display.print("HATCHMATE");
    display.display();
    delay(2000);
}

// ================= ALERT CONTROL =================
void freezeDisplay() { displayFrozen = true; }
void resumeDisplay() { displayFrozen = false; }

// ================= DISPLAY UPDATE =================
void updateDisplay() {
    if (displayFrozen) return;

    unsigned long currentMillis = millis();
    if (currentMillis - lastScreenSwitch >= SCREEN_ROTATION_INTERVAL) {
        currentScreen++;
        if (currentScreen > 5) currentScreen = 0; // 6 screens total
        lastScreenSwitch = currentMillis;
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);

    switch (currentScreen) {

        // SCREEN 1: MAIN STATUS
        case 0:
            display.print("HATCHMATE\n");
            display.print("T: "); display.print(getTemperature()); display.print("C\n");
            display.print("H: "); display.print(getHumidity()); display.print("%\n");
            display.print("Day: "); display.print(CURRENT_DAY); display.print("/21\n");
            display.print("Mode: INC  Wi-Fi "); 
            // Add Wi-Fi check here
            break;

        // SCREEN 2: ACTUATOR STATUS
        case 1:
            display.print("HEATER: "); display.print(digitalRead(HEATER_RELAY) ? "ON" : "OFF"); display.print("\n");
            display.print("FAN: "); display.print(digitalRead(FAN_RELAY) ? "ON" : "OFF"); display.print("\n");
            display.print("HUMID: "); display.print(digitalRead(HUMIDIFIER_RELAY) ? "ON" : "OFF"); display.print("\n");
            display.print("TURNER: "); display.print(digitalRead(TURNER_RELAY) ? "ON" : "OFF"); display.print("\n");
            break;

        // SCREEN 3: EGG TURNING
        case 2:
            display.print("EGG TURNING\n");
            display.print("Status: ENABLED\n");
            display.print("Next turn: "); display.print("01:20\n"); // Replace with timer
            display.print("Stop at Day 18\n");
            break;

        // SCREEN 4: HUMIDITY DETAIL
        case 3:
            display.print("HUMIDITY\n");
            display.print("Current: "); display.print(getHumidity()); display.print("%\n");
            display.print("Target: "); display.print(HUMIDITY_DAY_1_18); display.print("%\n");
            display.print("Mist: "); display.print(digitalRead(HUMIDIFIER_RELAY) ? "ON" : "OFF\n");
            break;

        // SCREEN 5: TEMPERATURE DETAIL
        case 4:
            display.print("TEMPERATURE\n");
            display.print("Current: "); display.print(getTemperature()); display.print("C\n");
            display.print("Target: "); display.print(TEMP_TARGET); display.print("C\n");
            display.print("State: "); 
            if (digitalRead(HEATER_RELAY)) display.print("HEATING\n");
            else if (digitalRead(FAN_RELAY)) display.print("COOLING\n");
            else display.print("STABLE\n");
            break;

        // SCREEN 6: CONNECTIVITY
        case 5:
            display.print("Wi-Fi: "); display.print(isWiFiConnected() ? "CONNECTED" : "DISCONNECTED\n");
            display.print("Cloud: SYNC OK\n");
            display.print("Last send: "); display.print("3m\n"); // Placeholder
            break;
    }

    display.display();
}

// ================= ALERT SCREEN =================
void showAlertScreen(const char* message) {
    freezeDisplay();
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("ALERT\n");
    display.print(message);
    display.display();
}
/ ================= DISPLAY UPDATE =================
void updateDisplay() {
    if (displayFrozen) return;

    unsigned long currentMillis = millis();
    if (currentMillis - lastScreenSwitch >= SCREEN_ROTATION_INTERVAL) {
        currentScreen++;
        if (currentScreen > 5) currentScreen = 0; // 6 screens total
        lastScreenSwitch = currentMillis;
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);

    switch (currentScreen) {

        // SCREEN 1: MAIN STATUS
        case 0:
            display.print("HATCHMATE\n");
            display.print("T: "); display.print(getTemperature()); display.print("C\n");
            display.print("H: "); display.print(getHumidity()); display.print("%\n");
            display.print("Day: "); display.print(CURRENT_DAY); display.print("/21\n");
            display.print("Mode: INC  Wi-Fi "); 
            // Add Wi-Fi check here
            break;

        // SCREEN 2: ACTUATOR STATUS
        case 1:
            display.print("HEATER: "); display.print(digitalRead(HEATER_RELAY) ? "ON" : "OFF"); display.print("\n");
            display.print("FAN: "); display.print(digitalRead(FAN_RELAY) ? "ON" : "OFF"); display.print("\n");
            display.print("HUMID: "); display.print(digitalRead(HUMIDIFIER_RELAY) ? "ON" : "OFF"); display.print("\n");
            display.print("TURNER: "); display.print(digitalRead(TURNER_RELAY) ? "ON" : "OFF"); display.print("\n");
            break;

        // SCREEN 3: EGG TURNING
        case 2:
            display.print("EGG TURNING\n");
            display.print("Status: ENABLED\n");
            display.print("Next turn: "); display.print("01:20\n"); // Replace with timer
            display.print("Stop at Day 18\n");
            break;

        // SCREEN 4: HUMIDITY DETAIL
        case 3:
            display.print("HUMIDITY\n");
            display.print("Current: "); display.print(getHumidity()); display.print("%\n");
            display.print("Target: "); display.print(HUMIDITY_DAY_1_18); display.print("%\n");
            display.print("Mist: "); display.print(digitalRead(HUMIDIFIER_RELAY) ? "ON" : "OFF\n");
            break;

        // SCREEN 5: TEMPERATURE DETAIL
        case 4:
            display.print("TEMPERATURE\n");
            display.print("Current: "); display.print(getTemperature()); display.print("C\n");
            display.print("Target: "); display.print(TEMP_TARGET); display.print("C\n");
            display.print("State: "); 
            if (digitalRead(HEATER_RELAY)) display.print("HEATING\n");
            else if (digitalRead(FAN_RELAY)) display.print("COOLING\n");
            else display.print("STABLE\n");
            break;

        // SCREEN 6: CONNECTIVITY
        case 5:
            display.print("Wi-Fi: "); display.print(isWiFiConnected() ? "CONNECTED" : "DISCONNECTED\n");
            display.print("Cloud: SYNC OK\n");
            display.print("Last send: "); display.print("3m\n"); // Placeholder
            break;
    }

    display.display();
}

// ================= ALERT SCREEN =================
void showAlertScreen(const char* message) {
    freezeDisplay();
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("ALERT\n");
    display.print(message);
    display.display();
}
