/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cart.cpp
 * Author: drew
 * 
 * Created on March 23, 2017, 6:10 PM
 */

#include "Cart.h"
#include "Pin.h"

Cart::Cart(): _a1(5,OUTPUT),_a2(6,OUTPUT), _b1(13,OUTPUT),_b2(19,OUTPUT) {

}

Cart::Cart(const Cart& orig) {
}

Cart::~Cart() {
}

void Cart::Stop() {
    _a1.Low();
    _a2.Low();
    _b1.Low();
    _b2.Low();
}

void Cart::Forward() {
    _a1.High();
    _a2.Low();
    _b1.High();
    _b2.Low();
}


void Cart::Reverse() {
    _a1.Low();
    _a2.High();
    _b1.Low();
    _b2.High();
}

void Cart::Right() {
    _a1.SetState(1);
    _a2.SetState(1);
    _b1.SetState(1);
    _b2.SetState(0);
}


void Cart::Left() {
    _a1.SetState(1);
    _a2.SetState(0);
    _b1.SetState(1);
    _b2.SetState(1);
}

void Cart::Test() {
    int iDelay = 2000;
    
    
  
    Stop();
    Forward();
    delay(iDelay);
    Stop();
    Reverse();
    delay(iDelay);
    Stop();
    Left();
    delay(iDelay);
    Stop();
    Right();
    delay(iDelay);
    Stop();
  
}

