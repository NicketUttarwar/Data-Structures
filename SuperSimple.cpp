//
//  SuperSimple.cpp
//  SuperSimpleClass project
//
//  Created by Michael Haas on 12/27/12.
//  Copyright (c) 2012 Data Structures. All rights reserved.
//
//  This is the implementation file for the SuperSimple class

#include "SuperSimple.h"
#include <ctime>

SuperSimple::SuperSimple()
{
    // default constructor
    // if user does not specify name and age, default values are used
    name = "Eric Idle";
    age = 69;
}

SuperSimple::SuperSimple( string namein, int agein)
{
    name = namein;
    age = agein;
}

SuperSimple::~SuperSimple()
{
    cout << endl << "Object containing " << name << " destroyed." << endl;
}

string SuperSimple::getname()
{
    return name;
}

int SuperSimple::getage()
{
    return age;
}

int SuperSimple::ThisYear()
{
    // gets the current year from the system time
    
    int year;                               // result of this function
    time_t rawtime;                         // seconds since 1/1/1970
    struct tm * timeinfo;                   // usable time items
    
    time ( &rawtime );                      // get the system time
    timeinfo = localtime ( &rawtime );      // convert to local time
    
    year = timeinfo->tm_year + 1900;        // get the year
    return year;                            // return the year
}

int SuperSimple::BirthYear()
{
    // computes the year that the person was born
    
    int birthyear = ThisYear() - age;
    return birthyear;
}
