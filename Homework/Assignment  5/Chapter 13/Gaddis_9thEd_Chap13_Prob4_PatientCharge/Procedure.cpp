/* 
 * File:   Patient.cpp
 * Author: khadiza Akter
 * Created on November 4, 2022, 12:33 PM
 * Purpose: Class Procedure implementation
 */
#include <string>
#include "Procedure.h"
using namespace std;

//************************************************************
//Definition of Procedure. This constructor accepts arguments
//for each member variable. 
//************************************************************
Procedure::Procedure(string n, string d, float chrg, string namePract) {
    name = n;
    date = d;
    charge = chrg;
    namePractitioner = namePract;
}

