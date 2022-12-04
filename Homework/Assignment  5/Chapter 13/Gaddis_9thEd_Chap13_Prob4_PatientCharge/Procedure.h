/* 
 * File:   Procedure.h
 * Author: Khadiza Akter
 * Created on November 4, 2022, 12:37 PM
 * Purpose: Class Procedure specification
 */

#ifndef PROCEDURE_H
#define PROCEDURE_H
#include <string>
using namespace std;


class Procedure {
    private:
       string name; //Name of Procedure
       string date; //Date of Procedure
       float charge; //Charge for Procedure
       string namePractitioner;//Name of Practitioner
    public:
        //default constructor
        Procedure() { name = "";}
        //constructor
        Procedure(string, string, float, string); 
        //Mutator function
        void setNameProcedure(string nm) {name = nm;}
        void setDateProcedure(string dt) {date = dt;}
        void setChargeProcedure(float chrge) {charge = chrge;}
        void setNamePractitioner(string nm) {namePractitioner = nm;}
        //Accessor function
        string getNameProcedure() const {return name;}
        string getDateProcedure() const {return date;}
        float getChargeProcedure() const {return charge;}
        string getNamePractitioner() const {return namePractitioner;}
    
};

#endif /* PROCEDURE_H */

