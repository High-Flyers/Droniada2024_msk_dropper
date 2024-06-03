#pragma once

#include <Adafruit_NeoPixel.h>
#include "params.h"
#include "pins.h"

namespace Neopixel{
    void init();
    void animate();
    void update(const uint64_t timeMs);
}   