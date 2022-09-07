/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 1, 2022
 * Purpose: Predict the size of a population of organism.
 */
//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    
    //Declare Variables
    int startNum,
        numOfDays;
    double avgIncrease,
          sizeOfPopulation;
    
    //Initialize Variables
    cout << "Enter the starting number of organism greater than or equal 2: ";
    cin >> startNum;
    while (startNum < 2) { //Loop to check the validation of input
        cout << "Invalid: Enter a number greater than or equal 2: ";
        cin >> startNum;
    }
  
    cout << "Enter a number of average population daily increase >or= 0: ";
    cin >> avgIncrease;
    while (avgIncrease < 0) { //Loop to check the validation of input
        cout << "Invalid: Enter a number greater than or equal 0: ";
        cin >> startNum;
    }
    cout << "Enter the number of days to multiply >or= 1: ";
    cin >> numOfDays;
    while (numOfDays < 1) { //Loop to check the validation of input
        cout << "Error: Enter a number greater than or equal 1: ";
        cin >> numOfDays;
    }
    
    //Map the inputs/known to the outputs and display the outputs
    cout << endl; //Print a new line
    sizeOfPopulation = startNum; //Assign startNum into sizeOfPopulation
    
    for (int i = 1; i <= numOfDays; i++) { //Loop through number of days to display population size for each day
        sizeOfPopulation += (sizeOfPopulation * avgIncrease) / 100; //calculate population size 
        cout << "The size of population for days " << i << " : "
             << sizeOfPopulation << endl;
    }
    
    //Exit the program
    return 0;
}

