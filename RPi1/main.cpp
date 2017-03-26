/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: drew
 *
 * Created on March 4, 2017, 6:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "LedPlay.h"
#include "SwitchPlay.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    std::cout << "Hello"<< std::endl;
    
     if (wiringPiSetup () == -1)
        exit (1) ;
    
    std::cout<< "GPIO setup complete." << std::endl;
    
    //LedPlay led = LedPlay();
    //led.Test1();
    
    SwitchPlay sw = SwitchPlay();
    sw.Wait();
    return 0;
}

