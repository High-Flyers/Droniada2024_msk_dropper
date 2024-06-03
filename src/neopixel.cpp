#include "neopixel.h"

Adafruit_NeoPixel strip1(LED_COUNT, NEOPIXEL1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(LED_COUNT, NEOPIXEL2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(LED_COUNT, NEOPIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(LED_COUNT, NEOPIXEL4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5(LED_COUNT, NEOPIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6(LED_COUNT, NEOPIXEL6, NEO_GRB + NEO_KHZ800);

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

void Neopixel::animate(){
    
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
