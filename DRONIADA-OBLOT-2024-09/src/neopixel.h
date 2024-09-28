#pragma once
#include <Arduino.h>
#include "params.h"
#include "pins.h"
#include "Adafruit_Neopixel.h"

namespace Neopixel {
    void init(Adafruit_NeoPixel strip);
    void show(Adafruit_NeoPixel strip, uint8_t n, uint8_t r, uint8_t g, uint8_t b);
}