/* 
 * File:   Essay.cpp
 * Author: Khadiza Akter
 * Created on November 9, 2022, 8:07 PM
 * Purpose: GradedActivity class implementation
 */

#include "GradedActivity.h"

//*********************************************************
//Definition of GradedActivity. This member function
//determine letter grade and return it
//*********************************************************
char GradedActivity::getLetterGrade() const {
    char letterGrade; //to hold a grade in letter and return 
    letterGrade =(score > 89)? 'A':
                 (score > 79)? 'B':
                 (score > 69)? 'C':
                 (score > 59)? 'D': 'F';
    return letterGrade;
}
