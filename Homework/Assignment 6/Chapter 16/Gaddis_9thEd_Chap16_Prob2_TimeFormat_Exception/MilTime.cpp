/* 
 * File:   MilTime.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 9:30 PM
 * Purpose: Implementation file for class MilTime
 */

#include "MilTime.h"
//***********************************************************
//Definition of MilTime. This constructor accepts two arguments
//for member variables, check for exception-> if don't throw 
// exception, call another member function to setTime
//***********************************************************
MilTime::MilTime(int hours, int seconds) {
    if (hours >= 0 && hours <= 2359) {
        milHours = hours;
    }
    else {
        throw BadHour();
    }
    if (seconds >= 0 && seconds <= 59) {
        milSeconds = seconds;
    }
    else {
        throw BadSeconds();
    }

    setTime(milHours, milSeconds);
}

//***********************************************************
//Definition of setTime. This function accepts two arguments
//for milHours, milSeconds.Then convert time in standard time
//and stored in the member variable of Time class
//******************************************************
void MilTime::setTime(int hours, int seconds) {       
    milHours = hours/100;
    milSeconds = seconds;
    hour = hours / 100;
    if(hour > 12){
        hour = hour - 12;
    }
    min = hours % 100;
    sec = milSeconds;
         
}

