#include "neopixel.h"

auto color = Adafruit_NeoPixel::Color(0, 0, 0);	

void Neopixel::init(Adafruit_NeoPixel strip){
    strip.begin();           
    strip.show();            
    strip.setBrightness(50);
}

void Neopixel::show(Adafruit_NeoPixel strip, uint8_t n, uint8_t r, uint8_t g, uint8_t b){
    color = Adafruit_NeoPixel::Color(r, g, b);

    for (int i = 0; i < n; i++) {
            strip.setPixelColor(i, color);
            delay(10);        
    }

    strip.setBrightness(255);
    strip.show();
}