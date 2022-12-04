/* 
 * File:   DayOfYear.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 10:11 AM
 * Purpose: Implementation of DayOfYear class
 */

#include "DayOfYear.h"
#include <iostream>
#include <string>
using namespace std;

//definition of static member variable 
string DayOfYear::monthName[SIZE] = {"January", "February", "March", "April", "May"
                                    , "June", "July", "August", "September",
                                   "October", "November", "December"};

//*************************************************************
// Definition of print. This function print the day of
// the year to month-day format,e.g; day 2-> January 2
//*************************************************************
void DayOfYear::print() const {
    //Declare variable
    int dayNum[SIZE+1] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
    int month; 
    int days;
    
    //loop through the  size to get the day of
    // the year to month-day format,e.g; day 2-> January 2
    cout << "\nDay " << numDaysOfYear << " in month-day format is: -> ";
    for(int i=0; i<SIZE; i++){
        if(numDaysOfYear > dayNum[i] && numDaysOfYear <= dayNum[i+1]) {
            cout << monthName[i] << " " << numDaysOfYear - dayNum[i] << endl;
              
        }
        
    }
}

