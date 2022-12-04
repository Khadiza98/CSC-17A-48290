/* 
 * File:   MilTime.cpp
 * Author: Khadiza Akter
 * Created on November 10, 2022, 9:30 PM
 * Purpose: Specification file for class MilTime
 */

#ifndef MILTIME_H
#define MILTIME_H
#include "Time.h"

//Derived class from the time class
class MilTime:public Time {
    private:
        int milHours; //contain the hour in 24-format
        int milSeconds; //contain the seconds in standard format
        
    public:
        //constructor, accepts two argument for member variable
        // call another member function setTime
        MilTime(int hours, int seconds) {
            milHours = hours;
            milSeconds = seconds;
            setTime(milHours, milSeconds);
        }
        void setTime(int, int); //Mutator function
         //Accessor function 
        int getHour() const {return milHours;}
        int getStandHr() const {return hour;}
    
};

#endif /* MILTIME_H */

