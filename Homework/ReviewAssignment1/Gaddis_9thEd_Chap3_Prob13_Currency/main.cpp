/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 1, 2022, 11:48 AM
 * Purpose: Convert U.S.dollar amount to Japanese yen and to euros. 
 */
//System Level Libraries
#include <iostream> //input-output library
#include <iomanip>  //setprecision(),setw() etc. libraray
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
const float YEN_PER_DOLLAR = 140.10, //based on 9/1/2022 currency report
            EUROS_PER_DOLLAR = 1.01;
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    
    //Declare Variable
    double usDollar,
           totalYen,
           totalEuros;
    
    
    //Initialize Variables
    cout << "Enter the U.S. dollar amount to convert YEN and EUROS:" << endl;
    cin >> usDollar;
    
    //Map the inputs/known to the outputs
    totalYen = usDollar * YEN_PER_DOLLAR;
    totalEuros = usDollar * EUROS_PER_DOLLAR;
    
    //Display the outputs
    cout << usDollar <<"$ equals "
         << setprecision(2) << fixed << showpoint << totalYen << " Yen and " 
         << totalEuros << " Euros" << endl;
    
    //Exit the program
    return 0;
}

