/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pin.cpp
 * Author: drew
 * 
 * Created on March 22, 2017, 7:07 PM
 */

#include <wiringPi.h>
#include "Pin.h"

Pin::Pin(){}

Pin::Pin(int pin,int mode): _pin(pin) {
    
    pinMode(pin,mode);
}



Pin::~Pin() {
}

void Pin::High(){
    digitalWrite(_pin,HIGH);
}

void Pin::Low(){
    digitalWrite(_pin,LOW);
}

int Pin::GetState(){
    return digitalRead(_pin);
}

void Pin::SetState(int State){
    digitalWrite(_pin,State);
}
