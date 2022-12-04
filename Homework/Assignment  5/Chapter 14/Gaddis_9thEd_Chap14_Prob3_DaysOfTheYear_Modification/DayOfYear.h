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
        int numDaysOfmonth; //holds days of month
        static string monthName[SIZE]; //to specify how to convert day of the year to month-day format
        static int dayArray[SIZE]; //to hold the days length in a month
        string monthN; // hold a month name
    public:
        //constructor
        DayOfYear() {
            numDaysOfmonth = 1;
            monthN = "January";
        }
        //constructor
        DayOfYear(string, int);
        //Mutator function
        void setDayofMonth(int num) { numDaysOfmonth = num; }
        void setmonthName(string name) { monthN = name;}
        //Accessor function
        int getDayofMonth() const {return numDaysOfmonth;}
        string getmonthName() const { return monthN; }
        //Prefix and postfix operator overloaded
        DayOfYear operator++(int); 
        DayOfYear operator++();
        DayOfYear operator--(int);
        DayOfYear operator--();
           
};

#endif /* DAYOFYEAR_H */

