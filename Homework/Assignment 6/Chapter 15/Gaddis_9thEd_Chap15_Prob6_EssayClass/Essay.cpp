/* 
 * File:   Essay.cpp
 * Author: Khadiza Akter
 * Created on November 9, 2022, 8:07 PM
 * Purpose: Essay class implementation
 */

#include "Essay.h"

//*********************************************************
//Definition of set. This member function calculate total 
//numeric score for this class and call inherited function 
//setScore to set the numeric score to the score member
//*********************************************************
void Essay::set(float gram, float spell, float content, float cLength) {
    float numericScore; //to hold the numeric score
    //set the member variable
    grammar = gram;
    spelling = spell;
    this->content = content;
    correctLength = cLength;
    //calculate the numeric score for this class
    numericScore = grammar + spelling + this->content + correctLength;
    //call inherited function setScore 
    //to set the numeric score to the score member
    setScore(numericScore);
}

