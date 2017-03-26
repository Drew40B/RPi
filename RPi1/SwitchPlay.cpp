/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.cpp
 * Author: drew
 * 
 * Created on March 19, 2017, 7:06 AM
 */

#include <cstdlib>
#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <ctime>
#include "SwitchPlay.h"

using namespace std;

SwitchPlay::SwitchPlay() {
}

SwitchPlay::SwitchPlay(const SwitchPlay& orig) {
}

SwitchPlay::~SwitchPlay() {
}

void SwitchPlay::Test1() {
    std::cout << "Switch Test 1" << std::endl;

    int pin = 0;

    pinMode(pin, INPUT);

    for (;;) {
        int result = digitalRead(pin);

        std::cout << "Pin: " << pin << " is " << result << std::endl;


        delay(1000);

    }
}


void onPin(){
     int result = digitalRead(0);

     printf("On Pin: %d. \n",result);
     fflush(stdout);
    
     
}


void onRising(){
    
    time_t myTime;
  
    time(&myTime);
    
    printf("OnRising %d \n",myTime);
     fflush(stdout);
    
     
}

void onFalling(){
    
     time_t myTime;
  
    time(&myTime);
    printf("OnFalling %d \n",myTime);
     fflush(stdout);
    
     
}

void SwitchPlay::Wait() {
    int pin = 0;
    
   //  wiringPiISR(pin,INT_EDGE_BOTH,&onPin);
  //  wiringPiISR(pin,INT_EDGE_RISING,&onRising);
      wiringPiISR(pin,INT_EDGE_FALLING,&onFalling);
  
    
    printf("Waiting for switch press....\n");
  fflush (stdout) ;
  
  string key;
  getline(cin,key);
    
}

