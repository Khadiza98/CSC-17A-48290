/* 
 * File:   Number.h
 * Author: Khadiza Akter
 * Created on November 12, 2022, 2:19 PM
 * Purpose: class Number implementation
 */

#include <iostream>
#include <string>
using namespace std;

#include "Number.h"

//definition of static member variable 
string Number::lessThan20[SIZE] = {"zero", "one", "two", "three", "four", "five"
                                    , "six", "seven", "eight", "nine", "ten",
                                   "eleven", "twelve", "thirteen", "fourteen",
                                   "fifteen", "sixteen", "seventeen", "eighteen"
                                   , "nineteen"};
//*************************************************************
// Definition of print. This function print English description
// of integer number.
//*************************************************************
void Number::print() const {
    string amountInText = "";
    //Determine 1000's, 100's, 10's, 1's
    unsigned char n1000s, n100s, n10s, n1s;
    n1000s = number / 1000;   //Shift 3 places to the left
    n100s = number % 1000 / 100;//Remainder of division of 1000 then shift 2 left
    n10s = number % 100 / 10;   //Remainder of division of 100 then shift 1 left
    n1s = number % 10;        //Remainder of division by 10

    //Output the number of 1000's in text
    //Using the Switch Statement
    switch (n1000s) {
    case 9: amountInText += "NINE THOUSAND ";
        break;
    case 8: amountInText += "EIGHT THOUSAND ";
        break;
    case 7: amountInText += "SEVEN THOUSAND ";
        break;
    case 6: amountInText += "SIX THOUSAND ";
        break;
    case 5: amountInText += "FIVE THOUSAND ";
        break;
    case 4: amountInText += "FOUR THOUSAND ";
        break;
    case 3: amountInText += "THREE THOUSAND ";
        break;
    case 2: amountInText += "TWO THOUSAND ";
        break;
    case 1: amountInText += "ONE THOUSAND ";
        break;
    }

    //Output the number of 100's
    //Using the Ternary Operator
    n100s == 9 ? amountInText += "NINE HUNDRED " :
        n100s == 8 ? amountInText += "EIGHT HUNDRED " :
        n100s == 7 ? amountInText += "SEVEN HUNDRED " :
        n100s == 6 ? amountInText += "SIX HUNDRED " :
        n100s == 5 ? amountInText += "FIVE HUNDRED " :
        n100s == 4 ? amountInText += "FOUR HUNDRED " :
        n100s == 3 ? amountInText += "THREE HUNDRED " :
        n100s == 2 ? amountInText += "TWO HUNDRED " :
        n100s == 1 ? amountInText += "ONE HUNDRED " : "";

    //Output the number of 10's
    //Using Independent If Statements
    if (n10s == 9)amountInText += "NINETY ";
    if (n10s == 8)amountInText += "EIGHTY ";
    if (n10s == 7)amountInText += "SEVENTY ";
    if (n10s == 6)amountInText += "SIXTY ";
    if (n10s == 5)amountInText += "FIFTY ";
    if (n10s == 4)amountInText += "FOURTY ";
    if (n10s == 3)amountInText += "THIRTY ";
    if (n10s == 2)amountInText += "TWENTY ";
    if (n10s == 1) {
        if (n1s == 9) amountInText += lessThan20[19];
        else if (n1s == 8) amountInText += lessThan20[18];
        else if (n1s == 7) amountInText += lessThan20[17];
        else if (n1s == 6) amountInText += lessThan20[16];
        else if (n1s == 5) amountInText += lessThan20[15];
        else if (n1s == 4) amountInText += lessThan20[14];
        else if (n1s == 3) amountInText += lessThan20[13];
        else if (n1s == 2) amountInText += lessThan20[12];
        else if (n1s == 1) amountInText += lessThan20[11];
        else
        {
            amountInText += lessThan20[10];
        }
    }

    //Output the number of 1's
    //Using Dependent If Statements
    if (n10s != 1)
    {
        if (n1s == 9) amountInText += lessThan20[9];
        else if (n1s == 8)amountInText += lessThan20[8];
        else if (n1s == 7)amountInText += lessThan20[7];
        else if (n1s == 6)amountInText += lessThan20[6];
        else if (n1s == 5)amountInText += lessThan20[5];
        else if (n1s == 4)amountInText += lessThan20[4];
        else if (n1s == 3)amountInText += lessThan20[3];
        else if (n1s == 2)amountInText += lessThan20[2];
        else if (n1s == 1)amountInText += lessThan20[1];
        /*else
        {
            amountInText += lessThan20[0];
        }
         * */
    }
    if (number == 0) amountInText = lessThan20[0];
    
    string temp = ""; //to hold the amountInText in lower case letter
    //loop to convert upper case to lower case letter
    for (int i = 0; i < amountInText.length(); i++) {
        temp += tolower(amountInText[i]); 
    }
    
    cout << "\nENGLISH DESCRIPTION OF '" << number << "' IS: "
         << temp <<endl;
    
}
