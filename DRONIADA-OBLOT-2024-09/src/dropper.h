#pragma once
#include <Arduino.h>
#include <Servo.h>
#include "params.h"

namespace Dropper {
    void attach();
    void openAll();
    void check();
    void drop(uint8_t i);
    void openOne(Servo s, uint8_t n);
    void closeOne(Servo s, uint8_t n);
    void Dropper::closeMsk(uint8_t i);
}