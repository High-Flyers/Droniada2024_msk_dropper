#include <Arduino.h>
#include "dropper.h"
#include "params.h"
#include "pins.h"
#include "neopixel.h"

uint8_t i = 0;
bool wait = 0;

void setup() {
    Serial.begin(9600);
    Dropper::attach();
    //w razie restartu - zablokuj
    Dropper::setAll(LOCKED_SERVO_US);
    //Serial.println("Begin");
    Neopixel::init();
    Neopixel::show(stripW1, LED_COUNT, 255, 0, 0);
    Neopixel::show(stripW2, LED_COUNT, 0, 255, 0);
    Neopixel::show(stripT, LED_COUNT, 0, 0, 0);

}

void loop() {
    //zlicza dlugosc pulsu PWM
    uint16_t _val = pulseIn(PWM_IN, HIGH);	
    //Serial.println(_val);
    //sprawdz czy nacisnieto guzik
    Dropper::check();

    if (_val > 1500 && _val < 2100 && !wait) {
        wait = !wait;
        Dropper::chooseServo(i, UNLOCKED_SERVO_US);
        //Serial.print("Dropped MSK: "); Serial.println(i);
        i++;
        if (i >= 4)
            i = 0;
    }

    if(_val > 800 && _val < 1200 && wait)
        wait = !wait;

    delay(50);
}

