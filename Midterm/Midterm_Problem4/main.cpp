/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 20, 2022, 11:48 AM
 * Purpose: Demonstrate encrypt and decrypt 4 digits number.
 */
 //System Level Libraries
#include <iostream> //input-output library
#include <iomanip> //format library
#include <string>
using namespace std;


//Function Prototypes
void menu(); // Display menu
string inputValidityCheck(string &); // Check input validity
string encryptNumber(string);        // encrypt a number
string decryptNumber(string inDigit);// decrypt a number

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    string inputDigit = "";//used to store digit input and initialized with default value
    string enDigit;        //to store encrypt or decrypt Number
    string deDigit;        //to store decrypt or decrypt Number
    char choice;           //to store the input as menu choice
    
    do {
        menu(); // Call menu function to display the menu
        cin >> choice;   
        //Map the Inputs to the Outputs
        cin.ignore();
        switch (choice) {
            case '1':
                cout << "Please input 4-digits number 0 to 7 for encryption: " << endl;
                inputDigit = inputValidityCheck(inputDigit); // Call function for input validity check
                enDigit = encryptNumber(inputDigit); // Encrypt the number
                cout << "The encrypted number is: " << enDigit << endl; // Print the encrypt Number
                break;
                
            case '2':
                cout << "Please input 4-digits number 0 to 7 for decryption: " << endl;
                inputDigit = inputValidityCheck(inputDigit); 
                deDigit = decryptNumber(inputDigit); // Decrypt the number
                cout <<"The decryption digit is: " << deDigit << endl;// Print the Decrypt number
                break;
                
            default: cout<<"Exiting Menu!!!"<<endl;
        }    
    }while(choice>='1' && choice<='2');

    //Exit the program
    return 0;
}

//*************************************************************
//Definition of menu.This display menu item                   *                                                                     
//*************************************************************
void menu() {
    cout << "\nPlease choose an item what you would like to do:" << endl;
    cout << "1: Encrypt a number" << endl;
    cout << "2: Decrypt a number" << endl << endl;
}
//***************************************************************************
//Definition of inputValidityCheck.Use a string @param as pass by reference.*                                  
//This check input validity and return a string inputDigit.                 *                                   
//***************************************************************************
string inputValidityCheck(string &inputDigit) {
    bool correctDigit;  //set to check valid digit input
    while (true) {
        correctDigit = true;
        getline(cin, inputDigit);
        if (inputDigit.length() != 4) {
            cout << "Please input 4-digit number between 0 to 7:\n";
            continue;
        }
        else {
            for (int i = 0; i < inputDigit.length(); i++) {
                if (inputDigit[i] < '0' || inputDigit[i] > '7') { // Input validation check
                    cout << "Please input 4-digit number between 0 to 7:\n";
                    correctDigit = false;
                    break;
                }
            }
        }
        if (!correctDigit) continue;
        break;
    }
    return inputDigit;
}
//*************************************************************
//Definition of encryptNumber.Use a string variable as @param *                                  
//Encrypt a 4 digit number and return encrypted value         *                                   
//*************************************************************
string encryptNumber(string inDigit) {
    string encryptNum; // Use to hold encrypted number
    encryptNum= to_string (((inDigit[2]-'0')+6)%8) +
                to_string(((inDigit[3] - '0') + 6) % 8) +
                to_string(((inDigit[0] - '0') + 6) % 8) +
                to_string(((inDigit[1] - '0') + 6) % 8); // Decrypted the result using (digit + 6)%8
    return encryptNum;
}
//*************************************************************
//Definition of decryptNumber.Use a string variable as @param *                                  
//Decrypt a 4 digit number and return decrypted value         *                                   
//*************************************************************
string decryptNumber(string inDigit) {
    string decryptNum="";
    if ((inDigit[2] - '0') <= 5) 
        decryptNum += to_string((1 * 8 + (inDigit[2] - '0') - 6));  // The quotient is 1; divisor 8; reminder inDigit[2]   
    else 
       decryptNum += to_string((0 * 8 + (inDigit[2] - '0') - 6));  // Otherwise quotient is 0 and rule is: value = quotient * divisor(8) + reminder -6
    
    if ((inDigit[3] - '0') <= 5)
        decryptNum += to_string((1 * 8 + (inDigit[3] - '0') - 6));
    else 
        decryptNum += to_string((0 * 8 + (inDigit[3] - '0') - 6));
    
    if ((inDigit[0] - '0') <= 5)
        decryptNum += to_string((1 * 8 + (inDigit[0] - '0') - 6));
    else 
        decryptNum += to_string((0 * 8 + (inDigit[0] - '0') - 6));
   
    if ((inDigit[1] - '0') <= 5)
        decryptNum += to_string((1 * 8 + (inDigit[1] - '0') - 6));
    else 
        decryptNum += to_string((0 * 8 + (inDigit[1] - '0') - 6));
    // Return decrypted number
     return decryptNum;
}
