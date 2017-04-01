/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandLineParser.cpp
 * Author: drew
 * 
 * Created on March 23, 2017, 7:03 PM
 */
#include <string>
#include "CommandLineParser.h"
#include "Directions.h"
CommandLineParser::CommandLineParser(int argc, char** argv) {
    
    std::string str;
    
    _direction = Unknown;
    
    for(int x = 1; x< argc; x++ ){
        str =  argv[x];
        
        if (str == "Forward"){
            _direction = Forward;
        } else if (str == "Reverse"){
            _direction = Reverse;
        } else if (str == "Left"){
            _direction = Left;
        } else if (str == "Right"){
            _direction = Right;
        } else if (str == "Stop"){
            _direction = Stop;
        } else if (str == "Test"){
            _direction = Test;
        }
        
    }
}

CommandLineParser::CommandLineParser(const CommandLineParser& orig) {
}

CommandLineParser::~CommandLineParser() {
}

Directions CommandLineParser::GetDirection(){
 return _direction;   
}