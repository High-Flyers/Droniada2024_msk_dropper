#pragma once
#include <Arduino.h>
#include <Servo.h>
#include "params.h"

namespace Dropper {
    void attach();
    void openAll();
    void check();
    void dropMsk(uint8_t i);
    void setServo(Servo s, uint8_t n, uint16_t POSITION);
    void closeMsk(uint8_t i);
}