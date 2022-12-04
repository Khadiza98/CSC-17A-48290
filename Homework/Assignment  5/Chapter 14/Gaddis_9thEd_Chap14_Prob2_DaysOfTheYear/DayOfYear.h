/* 
 * File:   DayOfYear.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 10:11 AM
 * Purpose: Specification of DayOfYear class
 */


#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H
#include <string>
using namespace std;

//Global constant
const int SIZE = 12; //Size of string array

//class declaration
class DayOfYear {
    private:
        int numDaysOfYear; //holds days of year
        static string monthName[SIZE]; //to specify how to convert day of the year to month-day format
    public:
        //constructor
        DayOfYear(unsigned int days) {numDaysOfYear = days;}
        //Accessor function
        void print() const;
        
};
#endif /* DAYOFYEAR_H */

