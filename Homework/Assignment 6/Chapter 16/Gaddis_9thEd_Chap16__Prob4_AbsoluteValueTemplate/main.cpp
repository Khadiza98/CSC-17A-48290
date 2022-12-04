
/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 11, 2022, 11:16 pM
 * Purpose: Write absolute value template function that accepts an argument and 
 *          return an absolute value by using simple driven program
 */

//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//Function template for absolute value
template <class T>
T absoluteValue(T value) {
    if (value < 0) return (value + (-value * 2));
    return value;
}

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    float num;   //To hold a number 
      
    //Ask user to enter a value to get it's absolute number 
    cout << "Enter a number to get an absolute value of that number: ";
    cin >> num;
    cout << "\n***********************************\n";
    cout << "The absolute value of " << num << " is " << absoluteValue(num);
    cout << "\n***********************************\n";

    //Exit the program
    return 0;
}