#pragma once
#include <Arduino.h>
#include "params.h"
#include "pins.h"
#include "Adafruit_Neopixel.h"

namespace Neopixel {
    void init();
    void show(uint8_t s, uint8_t n, uint8_t r, uint8_t g, uint8_t b);
}