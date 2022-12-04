/* 
 * File:   MilTime.cpp
 * Author: Khadiza Akter
 * Created on November 10, 2022, 9:30 PM
 * Purpose: Specification file for class Time
 */

#ifndef TIME_H
#define TIME_H

//base class declaration
class Time {
    protected:
        int hour; //holds number of hour
        int min;  //holds number of min
        int sec;  //holds number of sec
    public:
        //Default constructor
        Time() {hour = 0; min = 0; sec = 0;}
        //Constructor
        Time(int h, int m, int s) {hour = h; min = m; sec = s;}
        //Accessor functions
        int getHour() const {return hour;}
        int getSec() const {return sec;}
        int getMin() const {return min;}
    
};
#endif /* TIME_H */

