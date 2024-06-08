#include <Arduino.h>

#include "pwm.h"
#include "params.h"
#include "neopixel.h"

uint8_t i = 0;

uint64_t currentMillis = 0;

void setup() {
    Pwm::enable();
    Neopixel::init();
}

void loop() {
    
    currentMillis = millis();

    Neopixel::animate3(currentMillis);
    digitalWrite(SIG, HIGH);
    
    if (Pwm::isAvailable() && Pwm::checkTrigger()) {
        digitalWrite(SIG, LOW);
        delay(1000);
    }
    
    delay(50);
}