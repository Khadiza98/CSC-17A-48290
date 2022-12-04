/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 9, 2022, 10:29 AM
 * Purpose:Demonstrate a relationship between Employee and ProductionWorker class
 *          by writing a main program that use an object of ProductionWorker
 *          class.
 */


#include <iostream>
#include <string>

using namespace std;

//user defined libraries
#include "ProductionWorker.h"

//Execution begins here
int main(int argc, char** argv) {
    //Declare variable
    string emName; //holds input for employee name
    string emNumber; //holds input for employee phone number
    string hDate; //holds input for employee hire date
    int eShift; //to hold input for employee shift, for day shift 1, for night shift 2
    float hpayRate; //holds input for employee hourly pay rate
    
    //Ask user to enter information
    cout << "Enter the information of a employee: " << endl;
    cout << "Name: ";
    getline(cin, emName);
    cout << "Employee Number: ";
    getline(cin, emNumber);
    cout << "Hire date: ";
    getline(cin, hDate);
    do {
        cout << "Shift(1 -> day, 2 -> night): ";
        cin >> eShift;
    } while(eShift < 1 || eShift > 2);
    cout << "Hourly pay rate: $";
    cin >> hpayRate;
    
    //Dynamically create ProductionWorker object and initialize member variables 
    ProductionWorker *data;
    data = new ProductionWorker(emName, emNumber, hDate, eShift, hpayRate);
    
    //display the data stored in objects
    cout << "\n=======================================\n";
    cout << "Display the information of a employee: " << endl;
    cout << "=======================================\n";
    cout << "Name:\t\t " << data->getName() << endl;
    cout << "Employee Number: " << data->getNumber() << endl;
    cout << "Hire date: \t " << data->getHireDate() << endl;
    cout << "Shift:\t\t ";
    if (data->getShift() == 1)  cout << "Day shift" << endl;
    else                       cout << "Night shift" << endl;
    cout << "Hourly pay rate: $" << data->getHPayRate() << endl;
    
    //free the memory
    delete data;
    //Exit the program
    return 0;
}

