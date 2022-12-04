/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 5, 2022, 4.49 PM
 * Purpose: Demonstrates a NumDays class that purpose is store  a value of work
 *           hours and convert it to a number of days by writing a driver program 
 */
//System level libraries
#include <iostream>
using namespace std;

//User defined libraries
#include "NumDays.h"

//Execution begin here!
int main(int argc, char** argv) {
    //Declare variable
    float wHoursInput; //Holds number of work hours input
    NumDays third;     //This instances hold sum and difference of two objects
    NumDays fourth; //This instances holds postfix and prefix return value of third object
    
    //ask user to enter number of work hours
    cout << "Enter a number of work hours: ";
    cin >> wHoursInput;
    NumDays first(wHoursInput);
    cout << "Number of work hours -> " << first.getNumWorkHours() 
         << ", Number of days -> " << first.getNumOfDays() << endl;
    
    cout << "Enter another number of work hours: ";
    cin >> wHoursInput;
    NumDays second(wHoursInput);
    cout << "Number of work hours -> " << second.getNumWorkHours() 
         << ", Number of days -> " << second.getNumOfDays() << endl;      
    
    //Assign first+second to third
    third = first + second;
    cout << "\nDemonstrating the operator+, the sum of two object's "
            "hours members: -> " << third.getNumWorkHours() <<" hours, " <<
            third.getNumOfDays() << " days " << endl;
    //Assign first-second to third
    third = first - second;
    cout << "Demonstrating the operator-, the difference of two object's "
            "hours members: -> " << third.getNumWorkHours() <<" hours, " <<
            third.getNumOfDays() << " days " << endl;
    
    cout << "\nNow based on third object, " << third.getNumWorkHours() 
         <<" hours, " << third.getNumOfDays() << " days :" << endl;
    //Use postfix and prefix operator++
    cout << "\ndemonstrating ++prefix operator, the number of work "
            "hours and days:" << endl;
    fourth = ++third;
    cout << "Fourth: " << fourth.getNumWorkHours() << " hours " 
         << fourth.getNumOfDays() << " days.  ";
    cout << "Third: " << third.getNumWorkHours() << " hours "
         << third.getNumOfDays() << " days" << endl;


    cout << "\ndemonstrating postfix++ operator, the number of work"
            " hours and days:" << endl;
    fourth = third++;
    cout << "Fourth: " << fourth.getNumWorkHours() << " hours " 
         << fourth.getNumOfDays() << " days.  ";
    cout << "Third: " << third.getNumWorkHours() << " hours "
         << third.getNumOfDays() << " days" << endl;

    
    //Use postfix and prefix operator--
    cout << "\ndemonstrating --prefix operator, the number of work "
            "hours and days:" << endl;
    fourth = --third;
    cout << "Fourth: " << fourth.getNumWorkHours() << " hours " 
         << fourth.getNumOfDays() << " days.  ";
    cout << "Third: " << third.getNumWorkHours() << " hours "
         << third.getNumOfDays() << " days" << endl;

    cout << "\ndemonstrating postfix-- operator, the number of work "
            "hours and days:" << endl;
    fourth = third--;
    cout << "Fourth: " << fourth.getNumWorkHours() << " hours " 
         << fourth.getNumOfDays() << " days.  ";
    cout << "Third: " << third.getNumWorkHours() << " hours " 
         << third.getNumOfDays() << " days" << endl;
    
    return 0;
}

