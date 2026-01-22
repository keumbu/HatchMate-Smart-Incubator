#include "utils.h"
#include "pins.h"

// ================= BUZZER =================
void beepShort() {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
}

void beepContinuous() {
    digitalWrite(BUZZER_PIN, HIGH);
}

void beepMultiple(uint8_t times, uint16_t duration) {
    for (uint8_t i = 0; i < times; i++) {
        digitalWrite(BUZZER_PIN, HIGH);
        delay(duration);
        digitalWrite(BUZZER_PIN, LOW);
        delay(duration);
    }
}

// ================= TIME HELPERS =================
String secondsToHHMM(unsigned long seconds) {
    unsigned long hours = seconds / 3600;
    unsigned long minutes = (seconds % 3600) / 60;

    char buffer[6];
    sprintf(buffer, "%02lu:%02lu", hours, minutes);
    return String(buffer);
}
