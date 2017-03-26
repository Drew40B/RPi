/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Switch.h
 * Author: drew
 *
 * Created on March 19, 2017, 7:06 AM
 */

#ifndef SWITCH_H
#define SWITCH_H

class SwitchPlay {
public:
    SwitchPlay();
    SwitchPlay(const SwitchPlay& orig);
    void Test1();
    void Wait();
    
 virtual ~SwitchPlay();
    
  
    
private:
    int count;
};

#endif /* SWITCH_H */

