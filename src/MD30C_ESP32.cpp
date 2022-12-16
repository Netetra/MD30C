#include"arduino.h"
#include <MD30C.h>

MD30C::MD30C(uint8_t channel, uint8_t pwm_pin, uint8_t dir_pin){
    this->channel = channel;
    this->pwm_pin = pwm_pin;
    this->dir_pin = dir_pin;
}

void MD30C::init(){
    ledcSetup(this->channel,12800,8); 
    ledcAttachPin(this->pwm_pin, this->channel);
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
}

void MD30C::forward(uint8_t pwm) {
    digitalWrite(this->dir_pin, LOW);
    ledcWrite(this->channel, pwm);
}

void MD30C::back(uint8_t pwm) {
    digitalWrite(this->dir_pin, HIGH);
    ledcWrite(this->channel, pwm);
}

void MD30C::stop() {
    digitalWrite(this->dir_pin, LOW);
    ledcWrite(this->channel, 0);
}