#include "dropper.h"

#include <ESP32Servo.h>

#include "params.h"
#include "pins.h"

Servo _servo1, _servo2, _servo3, _servo4;

uint8_t _getBeaconNumber();

void Dropper::attach() {
    pinMode(BEACON_1_DETECT, INPUT_PULLDOWN);
    pinMode(BEACON_2_DETECT, INPUT_PULLDOWN);
    pinMode(BEACON_3_DETECT, INPUT_PULLDOWN);
    pinMode(BEACON_4_DETECT, INPUT_PULLDOWN);

    _servo1.setPeriodHertz(50);
    _servo2.setPeriodHertz(50);
    _servo3.setPeriodHertz(50);
    _servo4.setPeriodHertz(50);

    pinMode(SERVO_1, OUTPUT);
    pinMode(SERVO_2, OUTPUT);
    pinMode(SERVO_3, OUTPUT);
    pinMode(SERVO_4, OUTPUT);
}

void Dropper::drop() {
    uint8_t availableBeacon = _getBeaconNumber();

    switch (availableBeacon) {
        case 1:
            _servo1.attach(SERVO_1);
            _servo1.writeMicroseconds(UNLOCKED_SERVO_US);
            log_i("Dropped beacon: 1");
            vTaskDelay(DROP_TIMEOUT / portTICK_PERIOD_MS);
            _servo1.detach();
            break;
        case 2:
            _servo2.attach(SERVO_2);
            _servo2.writeMicroseconds(UNLOCKED_SERVO_US);
            log_i("Dropped beacon: 2");
            vTaskDelay(DROP_TIMEOUT / portTICK_PERIOD_MS);
            _servo2.detach();
            break;
        case 3:
            _servo3.attach(SERVO_3);
            _servo3.writeMicroseconds(UNLOCKED_SERVO_US);
            log_i("Dropped beacon: 3");
            vTaskDelay(DROP_TIMEOUT / portTICK_PERIOD_MS);
            _servo3.detach();
            break;
        case 4:
            _servo4.attach(SERVO_4);
            _servo4.writeMicroseconds(UNLOCKED_SERVO_US);
            log_i("Dropped beacon: 4");
            vTaskDelay(DROP_TIMEOUT / portTICK_PERIOD_MS);
            _servo4.detach();
            break;
        default:
            log_e("No beacons present. Cannot drop...");
            break;
    }
}

uint8_t _getBeaconNumber() {
    if (digitalRead(BEACON_1_DETECT) == HIGH) {
        return 1;
    }
    if (digitalRead(BEACON_2_DETECT) == HIGH) {
        return 2;
    }
    if (digitalRead(BEACON_3_DETECT) == HIGH) {
        return 3;
    }
    if (digitalRead(BEACON_4_DETECT) == HIGH) {
        return 4;
    }

    return 0;
}