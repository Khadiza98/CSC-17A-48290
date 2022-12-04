/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 4, 2022, 4.49 PM
 * Purpose: Demonstrates a DayOfYear class by writing a main program that ask user
 *          to enter day of the year to convert day of the year to month-day format
 */

//System level libraries
#include <iostream>
#include <string>
using namespace std;

//User defined library
#include "DayOfYear.h"

//Execution begins here!
int main(int argc, char** argv) {
    //declare variable
    int daysInput; //Hold an input int number as days of the year
    
    //Ask user to enter integer number as days of the year
    do{
        cout << "Enter days of the year between 1 to 365: ";
        cin >> daysInput;
        if(daysInput < 1 || daysInput > 365) cout << "Invalid input!! ";
    } while (daysInput < 1 || daysInput > 365);
    
    //declare a instance and initialize data to member variable using constructor
    DayOfYear day(daysInput);
    
    //display the days into month-day format
    day.print();
    
    return 0;
}

