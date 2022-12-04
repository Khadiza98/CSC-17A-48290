/* 
 * File:   NumDays.cpp
 * Author: Khadiza Akter
 * Created on November 7, 2022, 9:45 PM
 * Purpose: Class NumDays specification
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

//class declaration
class NumDays {
    private:
        float numWorkHours; //holds number of work hours
        float numOfDays; //holds number of days based on work hours
        void simplify(); //private member function to simplify the calculation
    public:
        //constructor
        NumDays(float workHours = 0);
		
        //Mutator function
        void setNumWorkHours(float numWH) { numWorkHours = numWH;}
	void setNumOfDays(float numDays) { numOfDays = numDays;}
        //Accessor function
        float getNumWorkHours() const {return numWorkHours;}
        float getNumOfDays() const {return numOfDays;}
        //Prefix and postfix operator overloaded
        NumDays operator++(int); 
        NumDays operator++();
        NumDays operator--(int);
        NumDays operator--();
        //+ and - operator overloaded
        NumDays operator+(const NumDays &); 
        NumDays operator-(const NumDays &);
           
};

#endif /* NUMDAYS_H */

