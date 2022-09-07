/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 1, 2022, 11:48 AM
 * Purpose: converting Celsius temperature to Fahrenheit.
 */
//System Level Libraries
#include <iostream> //input-output library
#include <iomanip> //setw()
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
//Initialize Random Seed once here!
    
    //Declare Variables
    float celsiusTemp, 
          fahrenheitTemp;
    
    
    //Initialize Variables
    cout << "Enter the Celsius Temperature to convert Fahrenheit:" << endl; 
    cin >> celsiusTemp;
    
    //Map the inputs/known to the outputs
    fahrenheitTemp = (static_cast<float>(9) / 5) * celsiusTemp + 32;
    
    //Display the outputs
    cout << setw(14) << "Celsius equals " << setw(10) << "Fahrenheit" << endl;
    cout << celsiusTemp << "\t  = \t " << fahrenheitTemp << endl;
    
    //Exit the program
    return 0;
}

