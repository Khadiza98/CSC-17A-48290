/* 
 * File:   Employee.h
 * Author: Khadiza Akter
 * Created on November 9, 2022, 2:44 PM
 * Purpose: Specification file for class Employee
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

//Employee class declaration, this is a base class
class Employee {
    private:
        string name; //holds employee name
        string number; //holds employee phone number
        string hireDate; //holds employee hire date
    public:
        //default constructor
        Employee() {
            name = "";
            number = "";
            hireDate = "";      
        }
        //constructorThis constructor accepts arguments for each member variable
        //Employee(string, string, string);
        Employee(string nameE, string phoneNo, string hDate) {
            name = nameE;
            number = phoneNo;
            hireDate =  hDate;
        }
        //Mutator function
        void setName(string nm) {name = nm;}
        void setNumber(string phoneNo) {number = phoneNo;}
        void setHireDate(string hDate) {hireDate = hDate;}
        //Accessor function
        string getName()const {return name;}
        string getNumber()const {return number;}
        string getHireDate()const {return hireDate;}
          
};

#endif /* EMPLOYEE_H */

