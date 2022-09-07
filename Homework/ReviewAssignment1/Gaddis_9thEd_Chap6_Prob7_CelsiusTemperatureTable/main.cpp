/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 3, 2022
 * Purpose: converting Fahrenheit temperature to Celsius.
 */
//System Level Libraries
#include <iostream> //input-output library
#include <iomanip> //for setw()
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
const int LIMIT = 20;
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
float celsius(float ); //Convert Fahrenheit to Celsius

//Execution begins here!
int main(int argc, char** argv) {
//Initialize Random Seed once here!
    
    //Declare Variables
    int farenheit;
    float cTemp;
    //Initialize Variables
    
    //Display the outputs or map the input/known to the output
    cout << setw(17) << "Fahrenheit equals " << setw(7) << "Celsius" << endl;
    
    //Loop to call the Celsius function, and display a table of Fahrenheit temperature
    //(from 0 to 20) and their Celsius temperature equivalent
    for (int i = 0; i <= LIMIT; i++) {
        farenheit = i;
        cTemp = celsius(farenheit); // calling Celsius function
        cout << setprecision(2) << fixed << showpoint;
        cout << setw(8) << farenheit << "     =    " << setw(7) << cTemp <<endl;
    }
    
    //Exit the program
    return 0;
}
/*
 * This function converts Fahrenheit to Celsius.
 * @Param Fahrenheit is float
 * @Return celsiusTemp is a Celsius temperature
 */
float celsius(float Fahrenheit) {
    float celsiusTemp; //local variable
    celsiusTemp = (static_cast<float>(5)/9) * (Fahrenheit - 32); //Calculate Celsius temperature
    
    return celsiusTemp;
}
