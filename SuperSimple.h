//
//  SuperSimple.h
//  SuperSimpleClass project
//
//  Created by Michael Haas on 12/27/12.
//  Copyright (c) 2012 Data Structures. All rights reserved.
//
//  This is the header file for the SuperSimple class
//  The SuperSimple class stores a name and age and calculates the birth year
//  That's all that it does.

#ifndef __SuperSimpleClass__SuperSimple__
#define __SuperSimpleClass__SuperSimple__

#include <iostream>
#include <string>

using namespace std;

class SuperSimple
{
private:
    string  name;
    int     age;
    
    int ThisYear();                             // determines current year
    
public:
    SuperSimple();                              // default constructor
    SuperSimple( string namein, int agein);     // overloaded constructor
    ~SuperSimple();                             // destructor
    
    // public methods
    int BirthYear();                            // calculates year born
    string getname();                           // gets the name
    int getage();                               // gets the age
};

#endif /* defined(__SuperSimpleClass__SuperSimple__) */
