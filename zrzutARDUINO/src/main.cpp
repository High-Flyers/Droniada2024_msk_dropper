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
    //Pwm::enable();
    Dropper::attach();
    Dropper::arm();
    Serial.begin(9600);
}

void loop() {
    
    currentMillis = millis();

    state = digitalRead(PWM_IN);

    if(state == 0 && lastState == 1){
        i++;
        Dropper::drop(i);
    }

    Serial.println(i);
    Serial.println(state);
    Serial.println(lastState);
    Serial.println("--------");
    
    lastState = state;

    /*
    if (Pwm::isAvailable() && Pwm::checkTrigger()) {
        i++;
        Pwm::disable();
        Dropper::drop(i);
        //delay(3000);
        Pwm::enable();
    }
    */
    delay(50);
}