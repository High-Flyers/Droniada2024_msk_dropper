#include "dropper.h"
#include "params.h"
#include "pins.h"

Servo _servo1, _servo2, _servo3, _servo4;

uint8_t d = 0;
uint8_t mapServo[4] = {5, 6, 10, 11};
uint8_t mapSW[4] = {7, 8, 9, 12};

bool mskState [4] = {0, 0, 0, 0}; 
bool state = 0, lastState = 0, mission = 0;

//bez detachowania - zeby trzymalo MSK w komorze
void Dropper::setServo(Servo s, uint16_t POSITION){
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

    //krancowki
    //pinMode(SW_1, INPUT_PULLUP);
    //pinMode(SW_2, INPUT_PULLUP); 
    //pinMode(SW_3, INPUT_PULLUP); 
    //guzik 
    pinMode(SW_4, INPUT); 
}

void Dropper::setAll(uint16_t POSITION){
    setServo(_servo1, POSITION);
    setServo(_servo2, POSITION);
    setServo(_servo3, POSITION);
    setServo(_servo4, POSITION);
}

void Dropper::chooseServo(uint8_t i, uint16_t POSITION) {
    switch (i) {
        case 0:
            setServo(_servo1, POSITION);
            break;
        case 1:
            setServo(_servo2, POSITION);
            break;
        case 2:
            setServo(_servo3, POSITION);
            break;
        case 3:
            setServo(_servo4, POSITION);
            break;
        default:
            //log_e("No SwarmKillers present. Cannot drop...");
            break;
    }
}


void Dropper::check(){
    
    //jesli zamknieto wszystkie MSK - wyjdz z funkcji
    if (mission) return;

    state = digitalRead(SW_4);

    //RISING_EDGE
    if (state == 0 && lastState == 1) {
        //1 nacisniecie - odblokuj komory
        if (d == 0) {
            setAll(UNLOCKED_SERVO_US);
        }
        //zamykaj po kolei 4 komory 
        else {
            chooseServo(d - 1, LOCKED_SERVO_US);
            //po zamknieciu wszystkich komor - zablokuj funkcje
            if (d >= 4)
                mission = 1;
        }
        d++;
    }
    Serial.println("D: "); Serial.print(d);
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

