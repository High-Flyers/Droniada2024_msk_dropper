#include "dropper.h"

#include <Servo.h>

#include "params.h"
#include "pins.h"

Servo _servo1, _servo2, _servo3, _servo4;

void armOne(Servo s, uint8_t n);

void Dropper::attach() {


    pinMode(SERVO_1, OUTPUT);
    pinMode(SERVO_2, OUTPUT);
    pinMode(SERVO_3, OUTPUT);
    pinMode(SERVO_4, OUTPUT);    
}

void Dropper::arm(){
    armOne(_servo1, SERVO_1);
    //log_i("Armed SwarmKiller: 1");
    armOne(_servo2, SERVO_2);
    //log_i("Armed SwarmKiller: 2");
    armOne(_servo3, SERVO_3);
    //log_i("Armed SwarmKiller: 3");
    armOne(_servo4, SERVO_4);
    //log_i("Armed SwarmKiller: 4");
    //log_i("All SwarmKillers armed !");
}

void Dropper::drop(uint8_t i) {

    switch (i) {
        case 1:
            _servo1.attach(SERVO_1);
            _servo1.writeMicroseconds(UNLOCKED_SERVO_US);
            //log_i("Dropped SwarmKiller: 1");
            delay(1000);
            _servo1.detach();
            break;
        case 2:
            _servo2.attach(SERVO_2);
            _servo2.writeMicroseconds(UNLOCKED_SERVO_US);
            //log_i("Dropped SwarmKiller: 2");
            delay(1000);
            _servo2.detach();
            break;
        case 3:
            _servo3.attach(SERVO_3);
            _servo3.writeMicroseconds(UNLOCKED_SERVO_US);
            //log_i("Dropped SwarmKiller: 3");
            delay(1000);
            _servo3.detach();
            break;
        case 4:
            _servo4.attach(SERVO_4);
            _servo4.writeMicroseconds(UNLOCKED_SERVO_US);
            //log_i("Dropped SwarmKiller: 4");
            delay(1000);
            _servo4.detach();
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}

void armOne(Servo s, uint8_t n){
    s.attach(n);
    s.writeMicroseconds(LOCKED_SERVO_US);
    delay(1000);
    s.detach();
}

