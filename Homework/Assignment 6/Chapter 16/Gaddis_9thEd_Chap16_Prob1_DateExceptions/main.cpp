/* 
 * File:   main.cpp
 * Author: khadiza Akter
 * Created on November 2, 2022, 2:50 PM
 * Purpose: Modify Date class using exception classes by writing a complete program 
 *          implementing it.
 */
//System Level Libraries
#include <cstdlib>
#include <iostream>

using namespace std;

//User Defined Libraries
#include "Date.h" // Needed for Date class

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int userMonth; //To store month input
    int userDay;   //To store day input
    int userYear;  //To store user input
    
    
    //Initialize variable
    cout << "Enter the day between 1 to 31: ";
    cin >> userDay;
    
    cout << "Enter the month between 1 to 12: ";
    cin >> userMonth;
    
    cout << "Enter the year: ";
    cin >> userYear;
    
    
    try {
        //create class 'Date' instance and initialize
        //member variable using constructor
        Date date(userDay, userMonth, userYear); 
        //Display the outputs
        cout << "\nThe date is:" << endl << endl;
        date.printForm1();
        date.printForm2();
        date.printForm3();
    }
    catch(Date::InvalidDay) {
        cout << "Error: invalid input -> [" << userDay 
             << "] entered for the date's day\n";
    }
    catch(Date::InvalidMonth) {
        cout << "Error: invalid input -> [" << userMonth 
             << "] entered for the date's month\n";
    }
    
    //Exit the program
    return 0;
}

