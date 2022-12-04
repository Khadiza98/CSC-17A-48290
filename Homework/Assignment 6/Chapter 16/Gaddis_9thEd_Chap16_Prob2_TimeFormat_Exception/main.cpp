/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 4:01 pm
 * Purpose: Modify Time and MilTime class using exception to display time 
            as both standard and military format by writing a complete program
 */

//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//User Defined Libraries
#include "MilTime.h"

//Function prototype
void printStandardFormat(const MilTime&); //Print time in Standard Format
void printMilitaryFormat(const MilTime&); //Print time in Military Format

//Execution begins here!
int main(int argc, char** argv) {   
    //Declare Variables
    int hours;
    int seconds;
    
    //Ask user to enter the time in military format
    cout << "Enter the hours in miliary format between(0 to 2359): ";
    cin >> hours;

    cout << "Enter the seconds in miliary format between(0 to 59): ";
    cin >> seconds;
    
    try {
        //create object of  MilTime class and initialize with user value
        MilTime Obj(hours, seconds);
        //Display the outputs
        printStandardFormat(Obj);
        printMilitaryFormat(Obj);
    }
    catch(MilTime::BadHour) {
        cout << "\nError: Invalid hour (" << hours << ") is passed to the class\n";
    }
    catch(MilTime::BadSeconds) {
        cout << "\nError: Invalid seconds (" << seconds 
             << ") is passed to the class\n";
    }
    //Exit the program
    return 0;
} //End main function

//******************************************************
//Definition of printStandardFormat. This function 
// display the time in standard format.
//******************************************************
void printStandardFormat(const MilTime &Obj) {
	cout << "\nThe time in Standard format: -> ";
   if(Obj.getHour()>= 12) {
       cout << Obj.getStandHr();
       if( Obj.getMin()<=9) cout << ":0" << Obj.getMin(); 
       else                     cout << ":" << Obj.getMin(); 

       if (Obj.getSec()<=9) {
           cout << ":0" << Obj.getSec() << " pm" << endl;
       }
       else{
           cout << ":" << Obj.getSec() << " pm" << endl;
       }
   } //End if
   else{
       cout << Obj.getStandHr();
       if( Obj.getMin()<=9)
       {
         cout << ":0" << Obj.getMin(); 
       }
       else {
           cout << ":" << Obj.getMin(); 
       }
       if (Obj.getSec()<=9){
           cout << ":0" << Obj.getSec() << " am" << endl;
       }
       else{
           cout << ":" << Obj.getSec() << " am" << endl;
       }
   } //End else
   
} //End printStandardFormat function

//******************************************************
//Definition of printMilitaryFormat. This function 
// display the time in Military format.
//******************************************************
void printMilitaryFormat(const MilTime &Obj) {
    cout << "The time in military format: -> ";
    if (Obj.getHour() <= 9) cout <<"0" << Obj.getHour();
    else                        cout << Obj.getHour();
           
    if( Obj.getMin()<=9) cout << ":0" << Obj.getMin(); 
    else                     cout << ":" << Obj.getMin(); 
        
    if (Obj.getSec()<=9) cout << ":0" << Obj.getSec() << endl;
    else                     cout << ":" << Obj.getSec() << endl;
        
} //End printMilitaryFormat