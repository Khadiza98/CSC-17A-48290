/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 11:16 pM
 * Purpose: Write total template function that accepts an argument and 
 *          return an absolute value by using simple driven program
 */

//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//***********************************************************
//Definition of total function template definition. This keep
//record running total of entered values on various type.
//Accept argument of different type in different call
//and return total values of various type
//***********************************************************
template <class T>
T total(T numVal) {
    T sum = 0;	// accumulator of values
    T numInput;// stores the value entered by user
    int count; //loop counter variable
    for (int count = 0; count < numVal; count++) {
        cout << "Enter value " << (count + 1) << ": ";
        cin >> numInput;
        sum += numInput; // keeping track of total
    }
    return sum;
}

//Execution begin here!
int main() {
    //Declare variable
    int intVal; //holds number of values in int type
    float fVal; //holds number of values in float type
    int returnVal; //hold return value of total number

    cout << "Enter the number of values the function is to read for integer: ";
    cin >> intVal;
    returnVal = total(intVal);
    cout << "The total for int values is: " << returnVal  << endl;

    cout << "\nEnter the number of values the function is to read for float: ";
    cin >> fVal;
    returnVal = total(fVal);
    cout << "The total for double values is: " << returnVal << endl;
    
    //Exit the program
    return 0;
}