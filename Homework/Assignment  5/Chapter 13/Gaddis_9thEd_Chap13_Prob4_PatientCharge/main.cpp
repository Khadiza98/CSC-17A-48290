/* 
 * File:   main.cpp
 * Author: khadiza Akter
 * Created on November 3, 2022, 10:58 PM
 * Purpose: Demonstrate a Patient and Procedure class by writing a complete
 *          program.
 */

//System Level Libraries
#include <iostream> //input-output library
#include <string> //needed for strings
#include <iomanip> //needed for format

using namespace std;

//User Defined Libraries
#include "Patient.h" // Needed for Patient class
#include "Procedure.h" // Needed for Procedure class

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    string firstName,lastName,midName;  //holds the input for name of patient
    string address; //Address input of patient
    string city;    //city input of patient
    string state;  //State input of patient
    string zipCode;    //Zip code input of patient
    string phoneNo; //phone number input of patient
    string nameEmerContact; //Emergency contact name input
    string phoneNoEmerContact; //Emergency contact phone number input
    float totalCharge;  //total charge of three procedure
    const int NUM_PROCED = 3; //Number of procedure
    Procedure procedure[NUM_PROCED]; //Declare array of Procedure
    
    //Ask user to enter the information of patient
    cout << "Enter the patient information:" << endl;
    cout << "First Name: ";
    getline(cin, firstName);
    cout << "Mid Name: ";
    getline(cin, midName);
    cout << "Last Name: ";
    getline(cin, lastName);
    cout << "Address: ";
    getline(cin, address);
    cout << "City: ";
    getline(cin, city);
    cout << "State: ";
    getline(cin, state);
    cout << "zipCode: ";
    getline(cin, zipCode);
    cout << "Phone Number: ";
    getline(cin, phoneNo);
    cout << "Name of emergency contact: ";
    getline(cin, nameEmerContact);
    cout << "Phone no. of emergency contact: ";
    getline(cin, phoneNoEmerContact);
    //declare an instance of Patient class and initialize with data
    Patient data(firstName, midName, lastName, address, city, state, zipCode,
                phoneNo, nameEmerContact, phoneNoEmerContact);
    //Initialize member variable for first 2 Procedure using constructor 
    procedure[0] = {Procedure("Physical Exam", "11/3/2022", 250.00, "Dr. Irvine")};
    procedure[1] = {Procedure("X-ray", "11/3/2022", 500.00, "Dr. Jamison")};
 
    //Third Procedure initialize calling mutator function
    procedure[2].setNameProcedure("Blood test");
    procedure[2].setDateProcedure("11/3/2022");
    procedure[2].setChargeProcedure(200.00);
    procedure[2].setNamePractitioner("Dr. Smith");
    //Display information about patient and three Procedure
    cout << "\n=============================================" << endl;
    cout << "THE PATIENT'S INFORMATION ARE:" <<endl;
    cout << "=============================================\n" << endl;
    cout << "First Name:  " << firstName << endl;
    cout << "Mid Name:  " << midName << endl; 
    cout << "Last Name:  " << lastName << endl; 
    cout << "Address:  " << address << endl;
    cout << "City:  " << city << endl;
    cout << "State:  " << state << endl;
    cout << "Zip Code:  " << zipCode << endl;
    cout << "Phone Number:  " << phoneNo << endl;
    cout << "Name of emergency contact: " << nameEmerContact << endl;
    cout << "Phone no. of emergency contact: " << phoneNoEmerContact << endl;
    
    cout << "\nThe information about three Procedures are:\n";
    cout << "-----------------------------------------"
            "-----------------------------\n";
    cout << "Procedure #" << setw(18) << "Procedure Name" << setw(12) << "Date"
         << setw(18) << "Practitioner" << setw(12) << " Charge\n";
    cout << "------------------------------------"
            "----------------------------------\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < NUM_PROCED; i++) {
        totalCharge += procedure[i].getChargeProcedure();
        cout << "Procedure #" << i+1 << setw(17) << procedure[i].getNameProcedure()
             << setw(14) <<procedure[i].getDateProcedure()<< setw(16)
             << procedure[i].getNamePractitioner() << setw(11) 
             << procedure[i].getChargeProcedure() << endl;;
    }
    cout << "\nTotal charge of the three Procedure: $" << totalCharge << endl;
    
    return 0;
}

