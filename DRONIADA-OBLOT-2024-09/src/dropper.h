#pragma once

#include <Arduino.h>

namespace Dropper {
    void attach();
    void arm();
    void drop(uint8_t i);
}