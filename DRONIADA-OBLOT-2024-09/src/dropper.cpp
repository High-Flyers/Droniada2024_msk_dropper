#include "dropper.h"
#include "params.h"
#include "pins.h"

Servo _servo1, _servo2, _servo3, _servo4;
bool mskState [4] = {0, 0, 0, 0}; 

void Dropper::openOne(Servo s, uint8_t n){
    s.attach(n);
    s.writeMicroseconds(UNLOCKED_SERVO_US);
    delay(1000);
    s.detach();
}

void Dropper::closeOne(Servo s, uint8_t n){
    s.attach(n);
    s.writeMicroseconds(LOCKED_SERVO_US);
    delay(1000);
    s.detach();
}

void Dropper::attach() {
    pinMode(SERVO_1, OUTPUT);
    pinMode(SERVO_2, OUTPUT);
    pinMode(SERVO_3, OUTPUT);
    pinMode(SERVO_4, OUTPUT);   

    pinMode(SW_1, INPUT_PULLUP);
    pinMode(SW_2, INPUT_PULLUP); 
    pinMode(SW_3, INPUT_PULLUP);  
    pinMode(SW_4, INPUT_PULLUP); 
}

void Dropper::openAll(){
    openOne(_servo1, SERVO_1);
    openOne(_servo2, SERVO_2);
    openOne(_servo3, SERVO_3);
    openOne(_servo4, SERVO_4);
    //Serial.println("All SwarmKillers armed !");
}

void Dropper::drop(uint8_t i) {
    switch (i) {
        case 0:
            openOne(_servo1, SERVO_1);
            break;
        case 1:
            openOne(_servo2, SERVO_2);
            break;
        case 2:
            openOne(_servo3, SERVO_3);
            break;
        case 3:
            openOne(_servo4, SERVO_4);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

void Dropper::closeMsk(uint8_t i) {
    switch (i) {
        case 1:
            closeOne(_servo1, SERVO_1);
            break;
        case 2:
            closeOne(_servo2, SERVO_2);
            break;
        case 3:
            closeOne(_servo3, SERVO_3);
            break;
        case 4:
            closeOne(_servo4, SERVO_4);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

void Dropper::check(){
    for(int i = 0; i < 4; i++){
        if(mskState[i] != digitalRead(mapSW[i])){
            mskState[i] = !mskState[i];
            if(mskState[i])
                closeMsk(i);
            else    
                openMsk(i);
        }
    }
}

