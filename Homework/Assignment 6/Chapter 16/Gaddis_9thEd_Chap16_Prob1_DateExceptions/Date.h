/* 
 * File:   Date.h
 * Author: Khadiza Akter
 * Created on November 2, 2022, 3:55 PM
 * Purpose: Class Date specification.
 */

#ifndef DATE_H
#define DATE_H

//Declare class
class Date {
    private:
        int month;  //member variable for month
        int day;    //member variable for day
        int year;   //member variable for year
    public:
        //Exception class for InvalidDay
        class InvalidDay {};
        //Exception class for InvalidMonth
        class InvalidMonth {};
        //constructor
        Date(int, int, int);
        void printForm1()const;
        void printForm2()const;
        void printForm3()const;

};

#endif /* DATE_H */

