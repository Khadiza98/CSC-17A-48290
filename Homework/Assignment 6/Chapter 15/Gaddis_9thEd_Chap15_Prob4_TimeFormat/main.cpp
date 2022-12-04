/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 10, 2022, 4:01 pm
 * Purpose: Demonstrate Time and MilTime class to display time as both standard 
            and military format by writing a complete program
 */

//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//User Defined Libraries
#include "MilTime.h"

//Function prototype
void printStandardFormat(const MilTime*); //Print time in Standard Format
void printMilitaryFormat(const MilTime*); //Print time in Military Format

//Execution begins here!
int main(int argc, char** argv) {   
    //Declare Variables
    int hours;
    int seconds;
    
    //Ask user to enter the time in military format
    do {
        cout << "Enter the hours in miliary format between(0 to 2359): ";
        cin >> hours;
    } while (hours < 0 || hours > 2359);
    
    do {
        cout << "Enter the seconds in miliary format between(0 to 59): ";
        cin >> seconds;
    } while (seconds < 0 || seconds > 59);
    
    //Dynamically create object of  MilTime class and initialize with user value
   MilTime *ptrObj = new MilTime(hours, seconds);
    
    //Display the outputs
   printStandardFormat(ptrObj);
   printMilitaryFormat(ptrObj);
    //Free the memory
    delete ptrObj;
    //Exit the program
    return 0;
} //End main function

//******************************************************
//Definition of printStandardFormat. This function 
// display the time in standard format.
//******************************************************
void printStandardFormat(const MilTime *ptrObj) {
	cout << "\nThe time in Standard format: -> ";
   if(ptrObj->getHour()>= 12) {
       cout << ptrObj->getStandHr();
       if( ptrObj->getMin()<=9) cout << ":0" << ptrObj->getMin(); 
       else                     cout << ":" << ptrObj->getMin(); 

       if (ptrObj->getSec()<=9) {
           cout << ":0" << ptrObj->getSec() << " pm" << endl;
       }
       else{
           cout << ":" << ptrObj->getSec() << " pm" << endl;
       }
   } //End if
   else{
       cout << ptrObj->getStandHr();
       if( ptrObj->getMin()<=9)
       {
         cout << ":0" << ptrObj->getMin(); 
       }
       else {
           cout << ":" << ptrObj->getMin(); 
       }
       if (ptrObj->getSec()<=9){
           cout << ":0" << ptrObj->getSec() << " am" << endl;
       }
       else{
           cout << ":" << ptrObj->getSec() << " am" << endl;
       }
   } //End else
   
} //End printStandardFormat function

//******************************************************
//Definition of printMilitaryFormat. This function 
// display the time in Military format.
//******************************************************
void printMilitaryFormat(const MilTime* ptrObj) {
    cout << "The time in military format: -> ";
    if (ptrObj->getHour() <= 9) cout <<"0" << ptrObj->getHour();
    else                        cout << ptrObj->getHour();
           
    if( ptrObj->getMin()<=9) cout << ":0" << ptrObj->getMin(); 
    else                     cout << ":" << ptrObj->getMin(); 
        
    if (ptrObj->getSec()<=9) cout << ":0" << ptrObj->getSec() << endl;
    else                     cout << ":" << ptrObj->getSec() << endl;
        
} //End printMilitaryFormat