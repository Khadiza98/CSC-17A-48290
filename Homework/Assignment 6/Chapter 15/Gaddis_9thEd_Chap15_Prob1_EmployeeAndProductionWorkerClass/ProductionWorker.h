/* 
 * File:   ProductionWorker.h
 * Author: Khadiza Akter
 * Created on November 9, 2022, 2:44 PM
 * Purpose: Specification file for class ProductionWorker
 */

#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
#include <string>
using namespace std;

//This a derived class from base class Employee
class ProductionWorker: public Employee {
    private:
        int shift; //Holds an integer value representing shift that workers works
        float hPayRate; //holds hourly pay rate 
     public:
        //when this ProductionWorker constructor execute, it will first call
        // Employee class default constructor
         ProductionWorker(): Employee(){
             shift = 1;
             hPayRate = 0;
         }
         //constructor
         ProductionWorker(string nm, string phoneNo, string hDate, 
         int sft, float rate): Employee(nm, phoneNo, hDate){
             shift = sft;
             hPayRate = rate;
         }
         //Mutator function
         void setShift(int shft) {shift = shft;}
         void setHPayRate(float rate) {hPayRate = rate;}
         //Accessor function
         int getShift() const {return shift;}
         float getHPayRate() const {return hPayRate;}

};

#endif /* PRODUCTIONWORKER_H */

