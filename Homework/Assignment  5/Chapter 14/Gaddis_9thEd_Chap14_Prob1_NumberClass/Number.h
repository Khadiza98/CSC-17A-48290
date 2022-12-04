/* 
 * File:   Number.h
 * Author: Khadiza Akter
 * Created on November 12, 2022, 2:19 PM
 * Purpose: class Number specification
 */

#ifndef NUMBER_H
#define NUMBER_H
#include <string>
using namespace std;

//Global constant
const int SIZE = 20; //size of the string


class Number {
    private:
        int number; //holds a whole number
        static string lessThan20[SIZE]; //to specify how to convert dollar to desire format
    public:
        //constructor
        Number(unsigned int num) {number = num;}
        //Accessor function
        void print() const;
        
};

#endif /* NUMBER_H */

