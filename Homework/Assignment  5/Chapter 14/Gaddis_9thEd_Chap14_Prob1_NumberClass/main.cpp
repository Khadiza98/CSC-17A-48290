/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 4, 2022, 1:03 PM
 * Purpose: Demonstrates a Number class by writing a main program that ask user
 *          to enter a number in proper range and print out it in English 
 *          description.
 */
//System level libraries
#include <iostream>
#include <string>
using namespace std;

//user defined library
#include "Number.h"

//Execution begins here!
int main(int argc, char** argv) {
    //declare variable
    int numInput; //Hold a int number by user
    
    //Ask user to enter integer number to translate into english
    do{
        cout << "Enter an integer number between 0 to 9999: ";
        cin >> numInput;
    } while (numInput < 0 || numInput > 9999);
    
    //declare a instance and initialize data to member variable using constructor
    Number number(numInput);
    
    //display the number into English description
    number.print();
    return 0;
}

