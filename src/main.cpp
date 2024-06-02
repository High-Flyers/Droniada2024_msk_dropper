#include <Arduino.h>

#include "dropper.h"
#include "pwm.h"
#include "params.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

uint8_t i = 0;

void setup() {
    //WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
    Pwm::enable();
    Dropper::attach();
    Dropper::arm();
    /*
    Serial.begin(9600);
    while (!Serial) {
    }
    */
}

void loop() {
    
    if (Pwm::isAvailable() && Pwm::checkTrigger()) {
        i++;
        Pwm::disable();
        Dropper::drop(i);
        delay(3000);
        Pwm::enable();
    }
    
}