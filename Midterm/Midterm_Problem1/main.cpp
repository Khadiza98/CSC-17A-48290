/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 18, 2022, 8:48 pm
 * Purpose: Develop an application using a structure for a customer that will determine if
            he/she has exceeded his/her checking account balance. For each customer, the following
            facts are available and the structure should include in the following order:
            • a. Account number (Five digits only, i.e. test for this)
            • b. Name
            • c. Address
            • d. Balance at the beginning of the month
            • e. Record all checks written by this customer this month Loop until customer is
            through entering checks. Use dynamic array.
            • f. Record all deposits credited to this customer’s account this month. Loop until
            customer is through entering deposits. Use dynamic array.
            Dynamically create the structure.
            The program should input each of these facts from input dialogs, store in a structure,
            calculate the new balance, display the new balance and debit the account $35 if overdrawn.
            Also, if overdrawn, tell the customer the additional $35 fee has been accessed
            and what the balance would be with this fee included. Make sure to output the contents
            of the structure.
 */
//System Level Libraries
#include <iostream> //input-output library
#include <string>
#include <iomanip>//setprecision()


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
void getData(Customer *, int &, int &); //Get data input from the user and store to the structure
//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int nCheck;                   //Number of checks written
    float sumCheckVal;            //Total amount of money spent per check
    int nDeposit;                 //Number of Deposit credited
    float sumDEPVal;              //Total amount of money deposited
    float newBalance;             //New balance of account
    Customer *personAcc = new Customer;//Dynamically create a structure
    
    getData(personAcc, nCheck, nDeposit); //pass argument as pass by reference
    
    //Display the Customer content
    cout << fixed << setprecision(2);
    cout << "\nHere are the information of customer checking account:" << endl;
    cout << "Account Number: " << personAcc->accountNum << endl;
    cout << "Name: " << personAcc->name << endl;
    cout << "Address: " << personAcc->address << endl;
    cout << "Initial Balance: " << personAcc->initialBalance << endl;
    cout << "Checks Written #: " << nCheck << endl;
    for (int i = 0; i < nCheck; i++) {
        cout << "Check " << (i+1) << ": "<< personAcc->check[i] << endl;
        sumCheckVal += personAcc->check[i]; //calculate total amount of checks written 
    }
    cout << "Deposit Credited #:" << nDeposit << endl;
    for (int i = 0; i < nDeposit; i++) {
        cout << "Deposit " << (i+1) <<": " << personAcc->deposit[i] << endl;
        sumDEPVal += personAcc->deposit[i];
    } 
    cout << "Amount of money withdraw: $" <<sumCheckVal << endl;
    cout << "Amount of money credited: $" <<sumDEPVal << endl;
    
    //calculate new balance of account and display
    newBalance = personAcc->initialBalance - sumCheckVal + sumDEPVal;
    cout << "New balance is $" << newBalance << endl;
    if (newBalance < 0) {
        newBalance -= 35;
        cout << "Since money is overdrawn, additional $35 fee has accessed.\n ";
        cout << "Now new balance is(with fee included): $" << newBalance <<endl;
    }
    //free the memory
    delete personAcc;
    delete []personAcc->check;
    delete []personAcc->deposit;
    //Exit the program
    return 0;
}
//*************************************************************
//Definition of getData.Use a pointer to a structure variable,*                                  
//number of checks and deposit as parameter.                  *
//Store all data about the customer to the structure members  *                                   
//*************************************************************
void getData(Customer *person, int &nCK, int &nDEP) {
     
    //Ask the customer to input his/ her account information
    do{
        cout << "Enter the account number(5 digit only) of your account: ";
        getline(cin, person->accountNum);
        if((person->accountNum).size() != 5) {
            cout << "Invalid input! Enter 5 digit only." << endl;
        }
    }while((person->accountNum).size() != 5);//Check input validation
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
    person->check = new float[nCK]; //Dynamically allocated array
    cout << "Enter how much spent per check: " << endl;
    for (int i = 0; i < nCK; i++) {
        cout << "Check " << (i+1) <<": ";
        cin >> person->check[i];   
    } 
    //ask customer for deposit credit information
    cout << "Total deposits credited this month: ";
    cin >> nDEP;
    person->deposit = new float[nDEP]; //Dynamically allocated array for deposit credited
    cout << "Enter how much credited per check: " << endl;
    for (int i = 0; i < nDEP; i++) {
        cout << "Deposit " << (i+1) <<": ";
        cin >> person->deposit[i];
    } 
    
}


