#include "dropper.h"
#include "params.h"
#include "pins.h"

Servo _servo1, _servo2, _servo3, _servo4;
bool mskState [4] = {0, 0, 0, 0}; 
uint8_t d = 0;
bool state = 0, lastState = 0;
uint8_t mapServo[4] = {5, 6, 10, 11};
uint8_t mapSW[4] = {7, 8, 9, 12};

void Dropper::setServo(Servo s, uint8_t n, uint16_t POSITION){
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
    setServo(_servo1, SERVO_1, UNLOCKED_SERVO_US);
    setServo(_servo2, SERVO_2, UNLOCKED_SERVO_US);
    setServo(_servo3, SERVO_3, UNLOCKED_SERVO_US);
    setServo(_servo4, SERVO_4, UNLOCKED_SERVO_US);
}

void Dropper::dropMsk(uint8_t i) {
    switch (i) {
        case 0:
            setServo(_servo1, SERVO_1, UNLOCKED_SERVO_US);
            break;
        case 1:
            setServo(_servo2, SERVO_2, UNLOCKED_SERVO_US);
            break;
        case 2:
            setServo(_servo3, SERVO_3, UNLOCKED_SERVO_US);
            break;
        case 3:
            setServo(_servo4, SERVO_4, UNLOCKED_SERVO_US);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

void Dropper::closeMsk(uint8_t i) {
    switch (i) {
        case 0:
            setServo(_servo1, SERVO_1, LOCKED_SERVO_US);
            break;
        case 1:
            setServo(_servo2, SERVO_2, LOCKED_SERVO_US);
            break;
        case 2:
            setServo(_servo3, SERVO_3, LOCKED_SERVO_US);
            break;
        case 3:
            setServo(_servo4, SERVO_4, LOCKED_SERVO_US);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

void Dropper::check(){
    state = digitalRead(SW_4);
    if(state == 0 && lastState == 1){
        closeMsk(d);
        d++;
        if(d >= 4)
            d = 0;
    }
    lastState = state;
    //krancowki ?
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

