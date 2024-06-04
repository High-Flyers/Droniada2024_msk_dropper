#pragma once

#include <Adafruit_NeoPixel.h>
#include "params.h"
#include "pins.h"

namespace Neopixel{
    void init();
    void steady();
    void animate(const uint64_t timeMs);
    void animate2(const uint64_t timeMs);
}   