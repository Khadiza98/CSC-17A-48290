/* 
 * File:   main.cpp
 * Author: khadiza Akter
 * Created on November 2, 2022, 2:50 PM
 * Purpose: Demonstrate a Date class by writing a complete program 
 *          implementing it.
 */
//System Level Libraries
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
    do {
        cout << "Enter the month between 1 to 12: ";
        cin >> userMonth;
    } while(userMonth < 1 || userMonth > 12); //check input validation

    do {
        cout << "Enter the day between 1 to 31: ";
        cin >> userDay;
    } while(userDay < 1 || userDay > 31); //check input validation
    
    cout << "Enter the year: ";
    cin >> userYear;
    
    //Dynamically create class 'Date' instance and initialize
    //member variable using constructor
    Date *date = new Date(userMonth, userDay, userYear); 
    
    //Display the outputs
    cout << "\nThe date is:" << endl << endl;
    date->printForm1();
    date->printForm2();
    date->printForm3();
    
    //free the memory
    delete date;
    //Exit the program
    return 0;
}

