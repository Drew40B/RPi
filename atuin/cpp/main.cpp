/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: drew
 *
 * Created on March 22, 2017, 6:53 PM
 */


#include <wiringPi.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdio.h>


#include "Pin.h"
#include "Cart.h"
#include "CommandLineParser.h"
using namespace std;




/*
 * 
 */
int main(int argc, char** argv) {

    printf(" Robot\r\n");

    if (wiringPiSetupGpio() == -1)
        exit(1);

    printf("GPIO setup complete.\r\n");

    CommandLineParser clp = CommandLineParser(argc,argv);
    Cart cart = Cart();
    
    cart.Stop();
    delay(250);
    
    Directions dir = clp.GetDirection();
   // dir = Test;
    
    switch(dir){
        case Forward:
            cart.Forward();
            printf("Forward \r\n");
            break;
        case Reverse:
            cart.Reverse();
            printf("Reverse \r\n");
            break;
        case Left:
            cart.Left();
            printf("Left \r\n");
            break;
        case Right:
            cart.Right();
            printf("Right \r\n");
            break;
        case Test :
             printf("Test \r\n");
            cart.Test();
            break;
         
        default:
            cart.Stop();
            printf("Stop\r\n");
    }
   
    /*
    int iDelay = 500;

    for (;;) {
        pinA1.High();
        delay(iDelay);
        pinA2.High();
        delay(iDelay);
        pinB1.High();
        delay(iDelay);
        pinB2.High();

        delay(iDelay);
        pinA1.Low();
        delay(iDelay);
        pinA2.Low();
        delay(iDelay);
        pinB1.Low();
        delay(iDelay);
        pinB2.Low();
        delay(iDelay);
    }
     * */
    
    return 0;
}

