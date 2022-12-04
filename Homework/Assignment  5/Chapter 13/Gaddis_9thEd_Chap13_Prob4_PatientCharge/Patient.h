/* 
 * File:   Procedure.h
 * Author: Khadiza Akter
 * Created on November 4, 2022, 12:37 PM
 * Purpose: Class Patient specification
 */


#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient {
    private:
        string firstName;  //First name of patient
        string lastName;   //last name of patient
        string midName;  //Mid name of patient
        string address; //Address of patient
        string city;    //city of patient
        string state;  //State of patient
        string zipcode;    //Zip code of patient
        string phoneNo; //phone number of patient
        string nameEmerContact; //Emergency contact name
        string phoneNoEmerContact; //Emergency contact phone number
    public:
        //constructor
        Patient(string, string, string, string, string, string, string, string, string, string);
        //Mutator function
        void setFirstName(string fName) {firstName = fName;}
        void setLastName(string lName) {lastName = lName;}
        void setMidName(string mName) {midName = mName;}
        void setAddress(string adres) {address = adres;}
        void setCity(string cityN) {city = cityN;}
        void setState(string st) {state = st;}
        void setZip(string zip) {zipcode = zip;}
        void setPhoneNo(string ph) {phoneNo = ph;}
        void setNameEmerContact(string eName) {nameEmerContact = eName;}
        void setPhoneNoEmerContact(string ePH) {phoneNoEmerContact = ePH;}
        //Accessor function
        string getFirstName() const {return firstName;}
        string getLastName() const {return lastName;}
        string getMidName() const {return midName;}
        string getAddress() const {return address;}
        string getCity() const {return city;}
        string getState() const {return state;}
        string getZip() const {return zipcode;}
        string getPhoneNo() const{return phoneNo;}
        string getNameEmerContact()const {return nameEmerContact;}
        string getPhoneNoEmerContact()const {return phoneNoEmerContact;}
};

#endif /* PATIENT_H */

