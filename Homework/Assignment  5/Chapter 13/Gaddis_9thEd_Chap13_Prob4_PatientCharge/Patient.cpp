/* 
 * File:   Patient.cpp
 * Author: khadiza Akter
 * Created on November 4, 2022, 12:33 PM
 * Purpose: Class Patient implementation
 */
#include <string>
#include "Patient.h"
using namespace std;

//************************************************************
//Definition of Patient. This constructor accepts arguments
//for each member variable 
//************************************************************
Patient::Patient(string fName, string midN, string lName, string adres, string c, 
    string st, string zip, string ph, string nECont, string phECont ) {
    firstName = fName;
    midName = midN;
    lastName = lName;
    address = adres;
    city = c;
    state = st;
    zipcode =  zip;
    phoneNo = ph;
    nameEmerContact = nECont;
    phoneNoEmerContact = phECont;
    
}

