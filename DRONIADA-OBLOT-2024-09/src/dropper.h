#pragma once
#include <Arduino.h>
#include <Servo.h>
#include "params.h"

namespace Dropper {
    void attach();
    void setAll(uint16_t POSITION);
    void check();
    void setServo(Servo s, uint16_t POSITION);
    void chooseServo(uint8_t i, uint16_t POSITION);
}