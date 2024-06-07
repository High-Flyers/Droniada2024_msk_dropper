#include "neopixel.h"

Adafruit_NeoPixel strip1(LED_COUNT, NEOPIXEL1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, NEOPIXEL2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(LED_COUNT, NEOPIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(LED_COUNT, NEOPIXEL4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5(LED_COUNT, NEOPIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6(LED_COUNT, NEOPIXEL6, NEO_GRB + NEO_KHZ800);

uint16_t hsv = 0;
auto color = Adafruit_NeoPixel::ColorHSV(hsv, 255, 255);

auto colorClear = Adafruit_NeoPixel::ColorHSV(0, 0, 0);

void Neopixel::init(){
    strip1.begin();           
    strip1.show();            
    strip1.setBrightness(50);

    strip2.begin();           
    strip2.show();            
    strip2.setBrightness(50);

    strip3.begin();           
    strip3.show();            
    strip3.setBrightness(50);

    strip4.begin();           
    strip4.show();            
    strip4.setBrightness(50);

    strip5.begin();           
    strip5.show();            
    strip5.setBrightness(50);

    strip6.begin();           
    strip6.show();            
    strip6.setBrightness(50);
}

void Neopixel::steady(){
    
    for(int i = 0; i < LED_COUNT; i++) { 
        strip1.setPixelColor(i, strip1.Color(255,   0,   0));        
        strip1.show(); 
        
        strip2.setPixelColor(i, strip2.Color(255,   0,   0));         
        strip2.show();
        
        strip3.setPixelColor(i, strip3.Color(0,   0,   255));         
        strip3.show();     

        strip4.setPixelColor(i, strip4.Color(0,   0,   255));        
        strip4.show(); 
        
        strip5.setPixelColor(i, strip5.Color(0,   0,   255));         
        strip5.show();
        
        strip6.setPixelColor(i, strip6.Color(0,   0,   255));         
        strip6.show();                        
        delay(50);                          
    }
}

void Neopixel::animate(const uint64_t timeMs) {
    
    static uint64_t prevTimeMs = timeMs;
    static uint8_t pixNum = 0;
    static uint8_t state = 0;

    if (timeMs - prevTimeMs < BLINK_DEL_MS) {
        return;
    }

    switch (state) {
        case 0:
            strip1.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip2.setBrightness(255);
            strip2.show();

            strip3.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip3.setBrightness(255);
            strip3.show();

            if (pixNum == LED_COUNT - 1) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;
            break;

        case 1:
            strip4.setPixelColor(pixNum, color);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(pixNum, color);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(pixNum, color);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;

            break;

        case 2:
            if (timeMs - prevTimeMs > 300) {
                strip1.clear();
                strip2.clear();
                strip3.clear();
                strip4.clear();
                strip5.clear();
                strip6.clear();

                strip1.show();
                strip2.show();
                strip3.show();
                strip4.show();
                strip5.show();
                strip6.show();

                prevTimeMs = timeMs;
                state++;
            }

            break;

        case 3:
            if (timeMs - prevTimeMs > 600) {
                prevTimeMs = timeMs;
                state = 0;
                hsv = (hsv + HSV_BUMP) % 65535;
                color = Adafruit_NeoPixel::ColorHSV(hsv, 255, 255);
            }

            break;
    }
}

void Neopixel::animate2(const uint64_t timeMs) {
    
    static uint64_t prevTimeMs = timeMs;
    static uint8_t pixNum = 0;
    static uint8_t state = 0;

    if (timeMs - prevTimeMs < BLINK_DEL_MS) {
        return;
    }

    switch (state) {
        case 0:
            strip1.setPixelColor(pixNum, color);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(pixNum, color);
            strip2.setBrightness(255);
            strip2.show();

            strip3.setPixelColor(pixNum, color);
            strip3.setBrightness(255);
            strip3.show();

            strip4.setPixelColor(pixNum, color);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(pixNum, color);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(pixNum, color);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                strip1.clear();
                strip2.clear();
                strip3.clear();
                strip4.clear();
                strip5.clear();
                strip6.clear();

                strip1.show();
                strip2.show();
                strip3.show();
                strip4.show();
                strip5.show();
                strip6.show();
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;

            break;

        case 1:
            strip1.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip2.setBrightness(255);
            strip2.show();

            strip3.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip3.setBrightness(255);
            strip3.show();

            strip4.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(LED_COUNT - 1 - pixNum, color);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;
            break;
            
        case 2:
            if (timeMs - prevTimeMs > 300) {
                strip1.clear();
                strip2.clear();
                strip3.clear();
                strip4.clear();
                strip5.clear();
                strip6.clear();

                strip1.show();
                strip2.show();
                strip3.show();
                strip4.show();
                strip5.show();
                strip6.show();

                prevTimeMs = timeMs;
                state++;
            }

            break;

        case 3:
            if (timeMs - prevTimeMs > 600) {
                prevTimeMs = timeMs;
                state = 0;
                hsv = (hsv + HSV_BUMP) % 65535;
                color = Adafruit_NeoPixel::ColorHSV(hsv, 255, 255);
            }

            break;
    }
}

void Neopixel::animate3(const uint64_t timeMs) {
    
    static uint64_t prevTimeMs = timeMs;
    static uint8_t pixNum = 0;
    static uint8_t state = 0;

    if (timeMs - prevTimeMs < BLINK_DEL_MS) {
        return;
    }

    switch (state) {
        case 0:
            strip1.setPixelColor(pixNum, color);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(pixNum, color);
            strip2.setBrightness(255);
            strip2.show();

            strip3.setPixelColor(pixNum, color);
            strip3.setBrightness(255);
            strip3.show();

            strip4.setPixelColor(pixNum, color);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(pixNum, color);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(pixNum, color);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;

            break;

        case 1:

            strip1.setPixelColor(pixNum, colorClear);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(pixNum, colorClear);
            strip2.setBrightness(255);
            strip2.show();
            
            strip3.setPixelColor(pixNum, colorClear);
            strip3.setBrightness(255);
            strip3.show();

            strip4.setPixelColor(pixNum, colorClear);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(pixNum, colorClear);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(pixNum, colorClear);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1 - 8) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;

        break;

        case 2:
            strip1.setPixelColor(LED_COUNT - 1 - 8 - pixNum, color);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(LED_COUNT - 1 -8 - pixNum, color);
            strip2.setBrightness(255);
            strip2.show();

            strip3.setPixelColor(LED_COUNT - 1 - 8 - pixNum, color);
            strip3.setBrightness(255);
            strip3.show();

            strip4.setPixelColor(LED_COUNT - 1 - 8 - pixNum, color);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(LED_COUNT - 1 - 8 - pixNum, color);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(LED_COUNT - 1 - 8 - pixNum, color);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1 - 8) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;
            break;
        
         case 3:

            strip1.setPixelColor(LED_COUNT - 1 - pixNum, colorClear);
            strip1.setBrightness(255);
            strip1.show();

            strip2.setPixelColor(LED_COUNT - 1 - pixNum, colorClear);
            strip2.setBrightness(255);
            strip2.show();
            
            strip3.setPixelColor(LED_COUNT - 1 - pixNum, colorClear);
            strip3.setBrightness(255);
            strip3.show();

            strip4.setPixelColor(LED_COUNT - 1 - pixNum, colorClear);
            strip4.setBrightness(255);
            strip4.show();

            strip5.setPixelColor(LED_COUNT - 1 - pixNum, colorClear);
            strip5.setBrightness(255);
            strip5.show();

            strip6.setPixelColor(LED_COUNT - 1 - pixNum, colorClear);
            strip6.setBrightness(255);
            strip6.show();

            if (pixNum == LED_COUNT - 1) {
                state++;
                prevTimeMs = timeMs;
                pixNum = 0;
                break;
            }

            pixNum++;
            prevTimeMs = timeMs;

        break;

        case 4:
            if (timeMs - prevTimeMs > 300) {
                strip1.clear();
                strip2.clear();
                strip3.clear();
                strip4.clear();
                strip5.clear();
                strip6.clear();

                strip1.show();
                strip2.show();
                strip3.show();
                strip4.show();
                strip5.show();
                strip6.show();

                prevTimeMs = timeMs;
                state++;
            }

            break;

        case 5:
            if (timeMs - prevTimeMs > 600) {
                prevTimeMs = timeMs;
                state = 0;
                hsv = (hsv + HSV_BUMP) % 65535;
                color = Adafruit_NeoPixel::ColorHSV(hsv, 255, 255);
            }

            break;
    }
}
