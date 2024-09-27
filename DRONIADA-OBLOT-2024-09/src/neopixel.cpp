#include "neopixel.h"

auto color = Adafruit_NeoPixel::Color(0, 0, 0);	

Adafruit_NeoPixel stripW1(LED_COUNT, NEOPIXELW1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripW2(LED_COUNT, NEOPIXELW2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripT(LED_COUNT, NEOPIXELT, NEO_GRB + NEO_KHZ800);

void Neopixel::init(){
    stripW1.begin();           
    stripW1.show();            
    stripW1.setBrightness(50);

    stripW2.begin();           
    stripW2.show();            
    stripW2.setBrightness(50);

    stripT.begin();           
    stripT.show();            
    stripT.setBrightness(50);
}

void Neopixel::show(uint8_t s, uint8_t n, uint8_t r, uint8_t g, uint8_t b){
    color = Adafruit_NeoPixel::Color(r, g, b);
    if(s == 0){
        for (int i = 0; i < n; i++) {
                stripW1.setPixelColor(i, color);
                delay(10);        
        }
        stripW1.setBrightness(255);
        stripW1.show();
    }

    else if(s == 1){
        for (int i = 0; i < n; i++) {
                stripW2.setPixelColor(i, color);
                delay(10);        
        }
        stripW2.setBrightness(255);
        stripW2.show();
    }

    else if(s == 2){
        for (int i = 0; i < n; i++) {
                stripT.setPixelColor(i, color);
                delay(10);        
        }
        stripT.setBrightness(255);
        stripT.show();
    }
}