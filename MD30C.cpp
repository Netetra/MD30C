#include"arduino.h"
#include <MD30C.h>

MD30C::MD30C(uint8_t dir_pin, uint8_t pwm_pin){
    this->dir_pin = dir_pin;
    this->pwm_pin = pwm_pin;
}

void MD30C::init(){
    pinMode(this->dir_pin,OUTPUT);
}

void MD30C::rotation(MODE mode,uint8_t pwm){
    switch (mode) {
        case MODE::FORWARD:
            forward(pwm);
        case MODE::BACK:
            back(pwm);
        case MODE::STOP:
            stop();
    }
    analogWrite(this->pwm_pin, pwm);
}

void MD30C::forward(uint_t pwm) {
    digitalWrite(this->dir_pin, LOW);
    analogWrite(this->pwm_pin, pwm);
}

void MD30C::back(uint_t pwm) {
    digitalWrite(this->dir_pin, HIGH);
    analogWrite(this->pwm_pin, pwm);
}

void MD30C::stop() {
    digitalWrite(this->dir_pin, LOW);
    analogWrite(this->pwm_pin, 0);
}