/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 2, 2022
 * Purpose: Displaying number of days in a month.
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
    int monthInput,
        yearInput;
    
    //Initialize Variables
    cout << "Enter a month between 1 and 12: ";
    cin >> monthInput;
    cout << "Enter a year: ";
    cin >> yearInput;
    
    //Map the inputs/known to the outputs and display the outputs
    /*Switch statement evaluates a given expression(monthInput)
     * based on the evaluated value in case statement, and
     * executes the statements associated with it.
     */
    switch(monthInput) {
        case 1: cout << 31 << " days"; 
                break;
        case 2: if (  (yearInput%400==0 && yearInput%100==0)  //Check the year is a leap year, if so month 2 has 29 days
                      ||(yearInput%4==0 && yearInput%100!=0) ){ 
                      cout << 29 <<" days" << endl;
                }
                else { //If the year is not a leap year, month 2 has 28 days
                  cout << 28 <<" days" << endl;
                }
                break;
        case 3: cout << 31 << " days"; 
                break;
        case 4: cout << 30 << " days"; 
                break;
        case 5: cout << 31 << " days"; 
                break;
        case 6: cout << 30 << " days"; 
                break;
        case 7: cout << 31 << " days"; 
                break;
        case 8: cout << 31 << " days"; 
                break;
        case 9: cout << 30 << " days"; 
                break;
        case 10:cout << 31 << " days"; 
                break;
        case 11:cout << 30 << " days"; 
                break;
        case 12:cout << 31 << " days"; 
                break;
        default:cout << "Invalid month entered!"; //If switch expression doesn't match with the case, will execute it       
    }
    
    cout << endl; //Print a new line
    
    
    //Exit the program
    return 0;
}

