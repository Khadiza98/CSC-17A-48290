/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 18, 2022, 8:48 pm
 * Purpose: Simulates a customer checking account balance using a
            dynamically create structure.This program take input from user 
            and store in a structure,calculate the new balance, display the new
            balance, debit the account $35 if overdrawn,and output the 
            contents of the structure. 
 */
//System Level Libraries
#include <iostream> //input-output library
#include <string>
#include <iomanip> //setprecision()
using namespace std;

//Structure declaration
struct Customer {          //Account of a customer
    string accountNum;     //Account number of customer
    string name;           //Name of customer
    string address;        //Address of customer
    float initialBalance;  //Early balance of customer
    float *check;          //Pointer to the array, record all checks written by the customer 
    float *deposit;        //Pointer to the array, record all deposit credited to this customer
};

//Function Prototypes
Customer *getData(int &, int &); //Get data input from the user and store to the structure
void displayCustomerInfo(const Customer *, int, int); // Print customer information
//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int nCheck;                   //Number of checks written
    int nDeposit;                 //Number of Deposit credited
    Customer *personAcc = nullptr;//Define a structure pointer 
    
    personAcc = getData(nCheck, nDeposit); ///Get data input from the user and store to the structure
    //Display the Customer content
    displayCustomerInfo(personAcc, nCheck, nDeposit);
    
    //free the memory
    delete personAcc;
    if(nCheck > 0) delete []personAcc->check; //if number of check 0,provide an exception to delete the array, so check it before delete
    if(nDeposit > 0)delete []personAcc->deposit;
    //Exit the program
    return 0;
}
//*************************************************************
//Definition of getData.Use 2 integer variable as @param like *                                  
//number of checks, deposit, and pass by reference .          *
//Store all data about the customer to the structure members  * 
//Return structure to the pointer                             *
//*************************************************************
Customer *getData(int &nCK, int &nDEP) {
    unsigned int i;               //loop counter variable
    bool correctDigit;            //to check the input digit correct
    Customer *person = new Customer;//Dynamically create a structure
    //Ask the customer to input his/ her account information
    do{ //Check input validation
        correctDigit = true;
        cout << "Enter the account number(5 digits only): ";
        getline(cin, person->accountNum);
        if((person->accountNum).size() != 5) {
            cout << "Invalid input! Enter 5 digit only." << endl;
            continue;
        } else {
            for (i = 0; i < person->accountNum.length(); i++) {
                if (person->accountNum[i] < '0' || person->accountNum[i] > '9') { // Input validation check
                    correctDigit = false;
                    break;
                }
            }
        }
        if (!correctDigit) continue;
        break;
    } while(true);
    //Get the name of customer
    cout << "Name: ";
    getline(cin, person->name);
    //Get the address of customer
    cout << "Address: ";
    getline(cin, person->address);
    //Get the Initial balance of customer
    cout << "Initial balance: $";
    cin >> person->initialBalance;
    //ask customer for check written information
    cout << "Total checks have been written this month: ";
    cin >> nCK;
    if (nCK >  0) {
        person->check = new float[nCK]; //Dynamically allocated array
        cout << "Enter how much spent per check: " << endl;
        for (i = 0; i < nCK; i++) {
            cout << "Check " << (i+1) <<": ";
            cin >> person->check[i];   
        } 
    }
    //ask customer for deposit credit information
    cout << "Total deposits credited this month: ";
    cin >> nDEP;
    if (nDEP > 0) {
        person->deposit = new float[nDEP]; //Dynamically allocated array for deposit credited
        cout << "Enter how much credited per check: " << endl;
        for (i = 0; i < nDEP; i++) {
            cout << "Deposit " << (i+1) <<": ";
            cin >> person->deposit[i];
        } 
    } 
    return person;
}
//*******************************************************************
//Definition of displayCustomerInfo.Use 2 integer variable as       *                                  
//@param like number of checks, deposit, and a pointer of structure *
//This display customer checking account information                *
//*******************************************************************
void displayCustomerInfo(const Customer *personAcc, int nCheck, int nDeposit) {
    unsigned int i;               //loop counter variable
    float sumDEPVal;              //Total amount of money deposited
    float newBalance;             //New balance of account
    float sumCheckVal;            //Total amount of money spent per check
    
    cout << fixed << setprecision(2);
    cout << "\nHere are the information of customer checking account:" << endl;
    cout << "Account Number:  " << personAcc->accountNum << endl;
    cout << "Name:            " << personAcc->name << endl;
    cout << "Address:         " << personAcc->address << endl;
    cout << "Initial Balance  $" << personAcc->initialBalance << endl;
    cout << "Checks Written   #" << nCheck << endl;
    for (i = 0; i < nCheck; i++) {
        cout << "Check " << (i+1) << ": $"<< personAcc->check[i] << endl;
        sumCheckVal += personAcc->check[i]; //calculate total amount of checks written 
    }
    cout << "Deposit Credited #" << nDeposit << endl;
    for (i = 0; i < nDeposit; i++) {
        cout << "Deposit " << (i+1) <<": $" << personAcc->deposit[i] << endl;
        sumDEPVal += personAcc->deposit[i];
    } 
    cout << "Total amount of money withdraw: $" <<sumCheckVal << endl;
    cout << "Total amount of money credited: $" <<sumDEPVal << endl;
    
    //calculate new balance of account and display
    newBalance = personAcc->initialBalance - sumCheckVal + sumDEPVal;
    if (newBalance >= 0){
        cout << "New balance is $" << newBalance << endl;
    }
    else {
        newBalance -= 35;
        cout << "The account has been overdrawn, additional $35 fee has accessed.\n";
        cout << "Now new balance is(with fee included): $" << newBalance <<endl;
    }
}


