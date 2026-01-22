#include "actuators.h"
#include "pins.h"

// ================= INITIALIZATION =================
void initActuators() {
    // Relays
    pinMode(HEATER_RELAY, OUTPUT);
    pinMode(FAN_RELAY, OUTPUT);
    pinMode(HUMIDIFIER_RELAY, OUTPUT);
    pinMode(TURNER_RELAY, OUTPUT);

    // LEDs
    pinMode(ALARM_LED, OUTPUT);
    
    // Buzzer
    pinMode(BUZZER_PIN, OUTPUT);

    // Optional: turn all OFF at startup
    heaterOff();
    fanOff();
    humidifierOff();
    turnerOff();
    setAlarmLED(false);
}

// ================= HEATER =================
void heaterOn()  { digitalWrite(HEATER_RELAY, HIGH); }
void heaterOff() { digitalWrite(HEATER_RELAY, LOW); }

// ================= FAN =================
void fanOn()  { digitalWrite(FAN_RELAY, HIGH); }
void fanOff() { digitalWrite(FAN_RELAY, LOW); }

// ================= HUMIDIFIER =================
void humidifierOn()  { digitalWrite(HUMIDIFIER_RELAY, HIGH); }
void humidifierOff() { digitalWrite(HUMIDIFIER_RELAY, LOW); }

// ================= EGG TURNER =================
void turnerOn()  { digitalWrite(TURNER_RELAY, HIGH); }
void turnerOff() { digitalWrite(TURNER_RELAY, LOW); }

// ================= BUZZER =================
void beepShort() {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
}

void beepContinuous() {
    digitalWrite(BUZZER_PIN, HIGH);
}

// ================= LED =================
void setAlarmLED(bool state) {
    digitalWrite(ALARM_LED, state ? HIGH : LOW);
}

