/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cart.h
 * Author: drew
 *
 * Created on March 23, 2017, 6:10 PM
 */

#ifndef CART_H
#define CART_H

#include "Pin.h"
#include <wiringPi.h>

class Cart {
private:
    Pin _a1;
    Pin _a2;
    Pin _b1;
    Pin _b2;

public:
    Cart();
    Cart(const Cart& orig);
    virtual ~Cart();

    void Stop();
    void Forward();
    void Reverse();
    void Left();
    void Right();

    void Test();

};

#endif /* CART_H */

