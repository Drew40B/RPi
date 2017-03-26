/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pin.h
 * Author: drew
 *
 * Created on March 22, 2017, 7:07 PM
 */

#ifndef PIN_H
#define PIN_H

class Pin {
public:
    
private:
     int _pin;
public:   
    Pin();
    Pin(int pinNumber,int mode);

    void High();
    void Low();
    int GetState();
    
    virtual ~Pin();

    
};

#endif /* PIN_H */

