/* 
 * File:   Date.cpp
 * Author: Khadiza Akter
 * Created on November 2, 2022, 3:55 PM
 * Purpose: Class Date implementation
 */

#include "Date.h" //Need for Date class
#include <iostream> //input-output library
#include <string> //for strings
using namespace std;

//**********************************************
//Definition of Date. This is a constructor,
//accept argument for month, day and year.
//**********************************************
Date::Date(int d, int m, int y) {
    if (d >= 1 && d <= 31) day = d; 
    else  throw InvalidDay();
    
    if (m >= 1 && m <= 12) month = m; 
    else  throw InvalidMonth();
    
    year = y;
}

//**********************************************
//Definition of printForm1. This function print
//date in form -> 12/25/2018, and return none
//**********************************************
void Date::printForm1() const{
    cout << month << "/" << day << "/" << year << endl << endl; 
}
//***************************************************
//Definition of printForm2. This function print
//date in form -> December 25, 2018, and return none
//***************************************************
void Date::printForm2() const{
    string monthName;		// Holds the name of the month

    switch (month) {
        case 1: monthName = "January";
                break;
        case 2: monthName = "February";
                break;
        case 3: monthName = "March";
                break;
        case 4: monthName = "April";
                break;
        case 5: monthName = "May";
                break;
        case 6: monthName = "June";
                break;
        case 7: monthName = "July";
                break;
        case 8: monthName = "August";
                break;
        case 9: monthName = "September";
                break;
        case 10:monthName = "October";
                break;
        case 11:monthName = "November";
                break;
        case 12:monthName = "December";
                break;
    }

    cout << monthName << " " << day << ", " << year << endl << endl; 
}
//**************************************************
//Definition of printForm3. This function print
//date in form -> 25 December 2018, and return none
//**************************************************
void Date::printForm3() const{
    string monthName;		// Holds the name of the month

    switch (month) {
        case 1: monthName = "January";
                break;
        case 2: monthName = "February";
                break;
        case 3: monthName = "March";
                break;
        case 4: monthName = "April";
                break;
        case 5: monthName = "May";
                break;
        case 6: monthName = "June";
                break;
        case 7: monthName = "July";
                break;
        case 8: monthName = "August";
                break;
        case 9: monthName = "September";
                break;
        case 10:monthName = "October";
                break;
        case 11:monthName = "November";
                break;
        case 12:monthName = "December";
                break;
    }

    cout << day << " " << monthName << " " << year << endl << endl; 
}


