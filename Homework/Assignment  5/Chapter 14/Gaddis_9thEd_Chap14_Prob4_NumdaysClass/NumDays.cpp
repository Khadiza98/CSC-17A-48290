/* 
 * File:   NumDays.cpp
 * Author: Khadiza Akter
 * Created on November 7, 2022, 9:45 PM
 * Purpose: Class NumDays implementation
 */

#include <cmath> //for fabs()
#include "NumDays.h"

//*********************************************************
// Definition of NumDays. This constructor accept parameter 
// for numWorkHour member variable, then call simplify
// function to calculate number of days
//*********************************************************
NumDays::NumDays(float workHours) {
    numWorkHours = workHours;
    //numOfDays = numWorkHours / 8;
    simplify();
    
}

//*********************************************************
// Definition of NumDays. This function converts number of 
// Work Hours to a number of days which assign
// to numOfDays member variable.
//*********************************************************
void NumDays::simplify() {
    numOfDays = numWorkHours / 8;
}
//*********************************************************
// Definition of operator+. Overloaded binary + operator 
//*********************************************************
NumDays NumDays::operator+(const NumDays &right) {
    NumDays temp;
    temp.numWorkHours = numWorkHours + right.numWorkHours;
    temp.numOfDays = numOfDays + right.numOfDays;
    
    return temp;
    
}
//*********************************************************
// Definition of operator-. Overloaded binary - operator 
//*********************************************************
NumDays NumDays::operator-(const NumDays &right) {
    NumDays temp;
    temp.numWorkHours = fabs(numWorkHours - right.numWorkHours);
    temp.numOfDays = fabs(numOfDays - right.numOfDays);
    
    return temp;
}
//****************************************************************
// Definition of operator++. This postfix operator overloaded 
// function increment number of hours stored in the object and 
// also recalculate number of days automatically
//****************************************************************
NumDays NumDays::operator++(int) {
    NumDays temp(numWorkHours);
    numWorkHours++;
    simplify();
    return temp;
}
//****************************************************************
// Definition of operator++. This prefix operator overloaded 
// function increment number of hours stored in the object and 
// also recalculate number of days automatically
//****************************************************************
NumDays NumDays::operator++() {
    ++numWorkHours;
    simplify();
    return *this;
}
//****************************************************************
// Definition of operator--. This prefix decrement overloaded 
// function decrement number of hours stored in the object and 
// also recalculate number of days automatically
//****************************************************************
NumDays NumDays::operator--() {
    --numWorkHours;
    simplify();
    return *this;
}
//****************************************************************
// Definition of operator--. This postfix decrement overloaded 
// function decrement number of hours stored in the object and 
// also recalculate number of days automatically
//****************************************************************
NumDays NumDays::operator--(int) {
    NumDays temp(numWorkHours);
    numWorkHours--;
    simplify();
    return temp;
}

