/* 
 * File:   main.cpp
 * Author: khadiza Akter
 * Created on November 2, 2022, 2:50 PM
 * Purpose: Demonstrate a Car class in a program that create object and call 
 *          the accelerator and brake function for five times and display it.
 */
//System Level Libraries
#include <iostream>
#include <string>

using namespace std;

//User Defined Libraries
#include "Car.h" // Needed for Car class


//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int yModel; //Hold the car's year model input
    string makeInput;  //Hold the make of car input
    int i;        //Counter variable
    
    cout << "Enter the car's year model: ";
    cin >> yModel;
    
    cin.ignore(); //to ignore one or more characters from the input buffer 
    cout << "Enter the car's make: ";
    getline(cin, makeInput);
    
    //Declare class 'Car' instance and initialize member variable using constructor
    Car car(yModel, makeInput);
    
    //Display the output
    cout << endl;
    cout << "=================================\n";
    cout << "Here are the information of car: " << endl;
    cout << "=================================\n";

    cout << "The car's year model: " << car.getYearModel() << endl;
    cout << "The make of the car: " << car.getCarMake() << endl << endl;
    //Accelerate the car 5 times and display its current speed each time
    for (i = 0; i < 5; i++) {
        car.accelerator();
        cout << "Accelerating #" << i+1 << " : Current speed of car -> " 
             << car.getSpeed() << endl;
    }
    cout << endl;
    
    // Brake 5 times and display its current speed each time
    for (i = 0; i < 5; i++) {
        car.brake();
        cout << "Braking #" << i+1 << " : Current speed of car -> " 
             << car.getSpeed() << endl;
    }
    //Exit the program
    return 0;
}

