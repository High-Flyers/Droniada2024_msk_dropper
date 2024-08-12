#include <Arduino.h>

#include "dropper.h"
//#include "pwm.h"
#include "params.h"
#include "pins.h"

uint8_t i = 0;

bool lastState = 0;
bool state = 0;

uint64_t currentMillis = 0;

void setup() {
    pinMode(PWM_IN, INPUT_PULLUP);
    Pwm::enable();
    Neopixel::init();
    Dropper::attach();
    Dropper::arm();
    Serial.begin(9600);
}

void loop() {
    
    currentMillis = millis();

    Neopixel::animate3(currentMillis);

    if (Pwm::isAvailable() && Pwm::checkTrigger()) {
        i++;
        Pwm::disable();
        Dropper::drop(i);
        //delay(3000);
        Pwm::enable();
    }
    
    delay(50);
}

