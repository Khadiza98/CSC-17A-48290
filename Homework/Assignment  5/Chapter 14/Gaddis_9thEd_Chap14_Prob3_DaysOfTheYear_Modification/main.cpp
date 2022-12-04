/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 5, 2022, 4.49 PM
 * Purpose: Modify a DayOfYear class by writing a main program that ask user
 *          to enter day of the month and name of month, check day are in range or 
            not based on given month, and also use postfix and prefix operator overloaded function.      
 */
//System level libraries
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//User defined library
#include "DayOfYear.h"

//Execution begin here!
int main(int argc, char** argv) {
    //declare variable
    int daysInput; //Hold an input int number as days of the month
    string month; //hold input for name of month
    string fChar;  //to hold first char of month name in uppercase letter

    //Ask user to enter integer number as days of the month and name of month
    cout << "Enter month of the year(e.g; January, February): ";
    cin >> month;
    if(month.length() > 0) { //check to make first letter of month name upper case
       fChar =  toupper(month.at(0));
     
       month =  fChar + (month.substr(1, (month.length()-1)));
    }
    do{
        cout << "Enter days of the given month: ";
        cin >> daysInput;
    } while (daysInput < 0 || daysInput > 31);

    //declare instance and initialize data to member variable using constructor
    DayOfYear first;
    DayOfYear second(month, daysInput);

    
    //Use the prefix and postfix operator++
    cout << "\ndemonstrating ++prefix operator, the next day and month:" << endl;
    first = ++second;
    cout << "First: " << first.getmonthName() << " " << first.getDayofMonth() << ".  ";
    cout << "Second: " << second.getmonthName() << " " << second.getDayofMonth() << endl;

    cout << "\ndemonstrating postfix++ operator, the next day and month:" << endl;
    first = second++;
    cout << "First: " << first.getmonthName() << " " << first.getDayofMonth() << "  ";
    cout << "Second: " << second.getmonthName() << " " << second.getDayofMonth() << endl;
    //declare DayOfYear instances to use the prefix and postfix decrement operator--
    DayOfYear third;
    DayOfYear fourth(month, daysInput);
    cout << "\ndemonstrating --prefix operator, the previous day and month:" << endl;
    third = --fourth;
    cout << "Third: " << third.getmonthName() << " " << third.getDayofMonth() << "  ";
    cout << "Fourth: " << fourth.getmonthName() << " " << fourth.getDayofMonth() << endl;
    cout << "\ndemonstrating postfix-- operator, the previous day and month:" << endl;
    third = fourth--;
    cout << "Third: " << third.getmonthName() << " " << third.getDayofMonth() << "  ";
    cout << "Fourth: " << fourth.getmonthName() << " " << fourth.getDayofMonth() << endl;
    return 0;
}

