/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CommandLineParser.h
 * Author: drew
 *
 * Created on March 23, 2017, 7:03 PM
 */

#include "Directions.h"

#ifndef COMMANDLINEPARSER_H
#define COMMANDLINEPARSER_H

class CommandLineParser {
public:
    CommandLineParser(int argc, char** argv);
    CommandLineParser(const CommandLineParser& orig);
    virtual ~CommandLineParser();
    
    Directions GetDirection();
    
private:
   Directions _direction; 
};

#endif /* COMMANDLINEPARSER_H */

