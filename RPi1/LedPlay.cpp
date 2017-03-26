/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LedPlay.cpp
 * Author: drew
 * 
 * Created on March 19, 2017, 6:44 AM
 */
#include <cstdlib>
#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "LedPlay.h"

LedPlay::LedPlay() {
}

LedPlay::LedPlay(const LedPlay& orig) {
}

LedPlay::~LedPlay() {
}

 int LedPlay::Test1(){
  
     

    int pin = 26;
    
    pinMode (pin, OUTPUT) ;
    bool on = true;
    for (int x =0; x<10;x++)
    {
    std::cout << "Flicker " << x << " On " << on <<std::endl;
        digitalWrite (pin, on) ;
        
        delay(1000);
        on = !on;
     }
  
    return 0;
}
