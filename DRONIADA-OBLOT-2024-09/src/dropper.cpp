#include "dropper.h"
#include "params.h"
#include "pins.h"

Servo _servo1, _servo2, _servo3, _servo4;
bool mskState [4] = {0, 0, 0, 0}; 

void Dropper::moveOne(Servo s, uint8_t n, uint16_t POSITION){
    //s.attach(n);
    s.writeMicroseconds(POSITION);
    delay(1000);
    //s.detach();
}

void Dropper::attach() {
    pinMode(SERVO_1, OUTPUT);
    pinMode(SERVO_2, OUTPUT);
    pinMode(SERVO_3, OUTPUT);
    pinMode(SERVO_4, OUTPUT);   

    _servo1.attach(SERVO_1);
    _servo2.attach(SERVO_2);
    _servo3.attach(SERVO_3);
    _servo4.attach(SERVO_4);
    //pinMode(SW_1, INPUT_PULLUP);
    //pinMode(SW_2, INPUT_PULLUP); 
    //pinMode(SW_3, INPUT_PULLUP);  
    pinMode(SW_4, INPUT); 
}

void Dropper::openAll(){
    moveOne(_servo1, SERVO_1, UNLOCKED_SERVO_US);
    moveOne(_servo2, SERVO_2, UNLOCKED_SERVO_US);
    moveOne(_servo3, SERVO_3, UNLOCKED_SERVO_US);
    moveOne(_servo4, SERVO_4, UNLOCKED_SERVO_US);
    //Serial.println("All SwarmKillers armed !");
}

void Dropper::dropMsk(uint8_t i) {
    switch (i) {
        case 0:
            moveOne(_servo1, SERVO_1, UNLOCKED_SERVO_US);
            break;
        case 1:
            moveOne(_servo2, SERVO_2, UNLOCKED_SERVO_US);
            break;
        case 2:
            moveOne(_servo3, SERVO_3, UNLOCKED_SERVO_US);
            break;
        case 3:
            moveOne(_servo4, SERVO_4, UNLOCKED_SERVO_US);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

void Dropper::closeMsk(uint8_t i) {
    switch (i) {
        case 0:
            moveOne(_servo1, SERVO_1, LOCKED_SERVO_US);
            break;
        case 1:
            moveOne(_servo2, SERVO_2, LOCKED_SERVO_US);
            break;
        case 2:
            moveOne(_servo3, SERVO_3, LOCKED_SERVO_US);
            break;
        case 3:
            moveOne(_servo4, SERVO_4, LOCKED_SERVO_US);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

int d = 0;
bool state = 0, lastState = 0;

void Dropper::check(){
    state = digitalRead(SW_4);
    if(state == 0 && lastState == 1){
        closeMsk(d);
        d++;
    }
    lastState = state;
    /*
    for(int i = 0; i < 4; i++){
        if(mskState[i] != digitalRead(mapSW[i])){
            mskState[i] = !mskState[i];
            if(mskState[i])
                closeMsk(i);
            else    
                dropMsk(i);
        }
    }
    */
}

