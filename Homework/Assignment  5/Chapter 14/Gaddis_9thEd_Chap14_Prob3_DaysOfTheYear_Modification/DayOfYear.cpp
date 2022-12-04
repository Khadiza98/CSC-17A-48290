/* 
 * File:   DayOfYear.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 10:11 AM
 * Purpose: Implementation of DayOfYear class
 */

#include "DayOfYear.h"
#include <string>
#include <iostream>
using namespace std;

//definition of static member variable, initialize with name of 12 month
string DayOfYear::monthName[SIZE] = {"January", "February", "March", "April", "May"
                                        , "June", "July", "August", "September",
                                        "October", "November", "December"};
//definition of static member variable 
int DayOfYear::dayArray[SIZE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

//****************************************************************
// Definition of operator++. This postfix operator overloaded 
// function modify the DayofYear class object so it represent the 
// next day, and it has a dump parameter so that compile can
// recognize that is post fix operator overloaded
//****************************************************************
DayOfYear DayOfYear::operator++(int) {
   DayOfYear temp(monthN, numDaysOfmonth); 
   for (int i = 0; i < SIZE; i++) {
        if (monthN == monthName[i] ) {
            numDaysOfmonth++;
			if ( i == (SIZE - 1)) {
                if (numDaysOfmonth > dayArray[i]) {
                    numDaysOfmonth = 1;
                    monthN = monthName[0];
                }
            }
            else if (numDaysOfmonth > dayArray[i]) {
                numDaysOfmonth = 1;
                monthN = monthName[i+1];
            }
			 else {
                monthN = monthName[i];
            }
            
            break;
        }
        
   }
   
   return temp;
}
//****************************************************************
// Definition of operator++. This prefix operator overloaded 
// function modify the DayofYear class object so it represent the 
// next day, e.g; January 1 -> January 2
//****************************************************************
DayOfYear DayOfYear::operator++() {
    
    for (int i = 0; i < SIZE; i++) {
        if (monthN == monthName[i]) {
            ++numDaysOfmonth;
            if (i == (SIZE - 1)) {
                if (numDaysOfmonth > dayArray[i]) {
                    numDaysOfmonth = 1;
                    monthN = monthName[0];
                }
            }
            else if (numDaysOfmonth > dayArray[i]) {
                numDaysOfmonth = 1;
                monthN = monthName[i + 1];
            }
            else {
                monthN = monthName[i];
            }
            break;
        }
        
    }
    return *this;
}

//********************************************************************
// Definition of operator--. This postfix decrement operator overloaded 
// function modify the DayofYear class object so it represent the 
// previous day.
//********************************************************************
DayOfYear DayOfYear::operator--(int) {
   DayOfYear temp(monthN, numDaysOfmonth);
   for (int i = 0; i < SIZE; i++) {
        if (monthN == monthName[i] ) {
            numDaysOfmonth--;
			if ( i == 0) {
                if (numDaysOfmonth == 0) {
                    numDaysOfmonth =  dayArray[SIZE-1];
                    monthN = monthName[SIZE-1];
                }
            }
            else if (numDaysOfmonth == 0) {
                numDaysOfmonth = dayArray[i-1];
                monthN = monthName[i-1];
            }
            else {
                monthN = monthName[i];
            }
			break;
        }
        
   }
 
   return temp;
}
//********************************************************************
// Definition of operator--. This prefix decrement operator overloaded 
// function modify the DayofYear class object so it represent the 
// previous day.
//********************************************************************
DayOfYear DayOfYear::operator--() { 
    for (int i = 0; i < SIZE; i++) {
        if (monthN == monthName[i]) {
            --numDaysOfmonth;
            if (i == 0) {
                if (numDaysOfmonth ==0) {
                    numDaysOfmonth =  dayArray[SIZE-1];
                    monthN = monthName[SIZE-1];
                }
            }
            else if (numDaysOfmonth == 0) {
                numDaysOfmonth = dayArray[i-1];
                monthN = monthName[i-1];
            }
             else {
                monthN = monthName[i];
            }
            
            break;
        }
        
    }
	
    return *this;
}
//*****************************************************************
// Definition of DayOfYear. This constructor takes 2 parameter, 
// string represent month and an int number represent day of month.
//*****************************************************************
DayOfYear::DayOfYear(string month, int num) {
    numDaysOfmonth = num;
    monthN = month; 
    bool iscorrect = false;
    for (int i = 0; i < SIZE; i++) {
        if ((monthN == monthName[i]) && (numDaysOfmonth > 0 
            && numDaysOfmonth <= dayArray[i])) {
            iscorrect = true;
            break;
        } 
    }
    if(!iscorrect){
        
        cout << "Day is outside of the range for the given month!!!\n";
        iscorrect = true;
        exit(0); //terminate the program
        
    }
    
}

