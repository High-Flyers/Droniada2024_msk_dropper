#include <Arduino.h>

#include "dropper.h"
#include "pwm.h"
#include "params.h"
#include "neopixel.h"

//#include "soc/soc.h"
//#include "soc/rtc_cntl_reg.h"

uint8_t i = 0;

uint64_t currentMillis = 0;

void setup() {
    //WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
    Pwm::enable();
    Dropper::attach();
    Dropper::arm();
    Neopixel::init();
    /*
    Serial.begin(9600);
    while (!Serial) {
    }
    */
}

void loop() {
    
    currentMillis = millis();

    //Neopixel::steady();
    Neopixel::animate(currentMillis);
    //Neopixel::animate2(currentMillis);

    if (Pwm::isAvailable() && Pwm::checkTrigger()) {
        i++;
        Pwm::disable();
        Dropper::drop(i);
        //delay(3000);
        Pwm::enable();
    }
    
    delay(50);
}