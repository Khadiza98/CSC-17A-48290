/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 12, 2022, 8:24 pM
 * Purpose: Write templates for two functions minimum and maximum by design a 
 *          simple driven program that demonstrates templates with various data type
 */
//System Level Libraries
#include <iostream> //input-output library
#include <iomanip>

using namespace std;


//************************************************
//Definition of minimum. this function template 
//accept 2 arguments of various type and 
// can return various type value.
//************************************************
template <class T>
T minimum(T value1, T value2) {
    if(value1 > value2) return value2;
    else                return value1;
}
template <class T>
T maximum(T value1, T value2) {
    if(value1 > value2) return value1;
    else                return value2;
}
//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int firstInt, secondInt;   //To hold two integer input 
    char firstChar, secondChar;  //To hold two char input
    string str1, str2;          //To hold two string input
    
    
    //Ask user to enter two value of various type and  compare in templates 
    cout << "Enter two integers to compare: ";
    cin >> firstInt >> secondInt;
    cout << "Minimum value: -> " << minimum(firstInt, secondInt) << endl;
    cout << "Maximum value: -> " << maximum(firstInt, secondInt) << endl;
    
    cout << "\nEnter two characters to compare: ";
    cin >> firstChar >> secondChar;
    cout << "Minimum value: -> " << minimum(firstChar, secondChar) << endl;
    cout << "Maximum value: -> " << maximum(firstChar, secondChar) << endl;
    
    cout << "\nEnter two string to compare: ";
    cin >> str1 >> str2;
    cout << "Minimum value: -> " << minimum(str1, str2) << endl;
    cout << "Maximum value: -> " << maximum(str1, str2) << endl;
    
    
    //Exit the program
    return 0;
}