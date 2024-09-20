#include <Arduino.h>
#include "dropper.h"
#include "params.h"
//#include "pins.h"

uint8_t i = 0;
bool wait = 0;

void setup() {
    Serial.begin(9600);
    Dropper::attach();
    Dropper::openAll();
    Serial.println("Begin");
}

void loop() {
    uint16_t _val = pulseIn(3, HIGH);	
    Serial.println(_val);

    if (_val > 1500 && _val < 2100 && !wait) {
        wait = !wait;
        Dropper::drop(i);
        Serial.print("Dropped MSK: "); Serial.println(i);
        i++;
        //delay(3000);
    }

    if(_val > 800 && _val < 1200 && wait)
        wait = !wait;

    delay(50);
}

