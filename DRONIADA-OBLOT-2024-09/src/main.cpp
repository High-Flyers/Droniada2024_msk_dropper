#include <Arduino.h>

#include "dropper.h"
#include "pwm.h"
#include "params.h"

void setup() {
    Pwm::enable();
    Dropper::attach();

    Serial.begin(9600);
    while (!Serial) {
    }
}

void loop() {
    if (Pwm::isAvailable() && Pwm::checkTrigger()) {
        Pwm::disable();
        Dropper::drop();
        delay(3000);
        Pwm::enable();
    }
}