/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 19, 2022, 11:48 AM
 * Purpose: Develop an application using an array of structures created dynamically that
            will determine the gross pay for any number of employees input. i.e. ask up front how
            many employees you are inputting. The company pays ”straight-time” for the first 20
            hours worked, double time for all hours worked in excess of 20 hours but less than 40
            hours, and triple time for any hours worked over 40 hours.
            The program should be able to loop and input the employee’s name, hours worked, and
            the rate of pay. Once this has been done then output this information including the
            CSC 17a C++:Objects Midterm - Page 2 of 4 10/17/22 gross pay in the form of a paycheck. 
            The process starts all over again until you input an invalid rate of pay or hours worked. 
            Print it out like an actual paycheck with English language.Printout like a company Paycheck with format:
            Company, Address, Name: Amount: numerical,Amount: English of numerical value, Signature Line:
 */
 //System Level Libraries
#include <iostream> //input-output library
#include <string>   
#include <iomanip> //setw(), setprecision(), etc.
#include <sstream> 
#include <cmath> //floor()
#include <cfenv> //fesetround()
using namespace std;

//Structure declaration
struct EmployeeInfo{           // Declare a structure for employee information 
    string employeeName;       // To take the input of employee name
    float workHour;            // To take the input of total working hour
    float payRate;             // To take the input of pay rate
};

//Function Prototypes
EmployeeInfo* employeeInformationData(int ); //Get data/input by user
void displayPlayCheck(EmployeeInfo *, int); //Print the paycheck
string numberToText(float);//convert number to text

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int numberOfEmployee; //Number of employee
    EmployeeInfo* empInfo;//Define a structure pointer
    
    //ask user to enter the number of employee 
    cout << "Enter the total number of employee :" << endl;
    cin >> numberOfEmployee;
    if(numberOfEmployee <= 0) {
        cout << "There is no employee to work in!!!" << endl;
        return 0;
    }
    empInfo = employeeInformationData(numberOfEmployee); //call function to get input of dynamic array
    cout << "Here is the Paycheck: " << endl;
    displayPlayCheck(empInfo, numberOfEmployee);//Print the pay check
    
    //free the memory
    delete []empInfo;
    //Exit the program
    return 0;
}

//*****************************************************************
// Definition of function employeeInformationData
// This function ask for employee number and information                                
// Return the pointer of employee structure                                          
//*****************************************************************

EmployeeInfo* employeeInformationData(int n) {
    EmployeeInfo* employee; //Define a EmployeeInfo structure pointer
    if (n > 0) {
        employee = new EmployeeInfo[n]; //Dynamically allocate array of structure
        cout << "Please insert the employee information below:" << endl;
        for (int i = 0; i < n; i++) {
            cin.ignore();
            cout << "Employee #"<<(i+1) << endl;
            cout << "Employee name: ";
            getline(cin, employee[i].employeeName);
            cout << "Total working hours: ";
            cin >> employee[i].workHour;
            while(employee[i].workHour < 0 ){// Check the negative number for working hours
                cout << "Please enter a positive value for working hours: ";
                cin >>employee[i].workHour;
            }
            cout << "Employee pay rate: ";
            cin >> employee[i].payRate;
            while(employee[i].payRate < 0 ){// Check the negative number for payRate
                cout << "Please enter a positive value for pay rate: ";
                cin >>employee[i].payRate;
            }
               
            
        }
        
        return employee; //Return the pointer of structure
    }
    return nullptr; //Return nullptr if number of employee is less than 0
}
//*****************************************************************
// Definition of function displayPlayCheck                        *
// This function display paycheck of each employee                *
// Use pointer of structure, number of employee as parameter      *
//*****************************************************************
void displayPlayCheck(EmployeeInfo* empInfo, int numberOfEmployee) {
    const int H_LIMIT = 20;     // Work limit for straight hour
    float payAmount = 0.0f;     // Calculate the employee payment amount
    float extraHour = 0.0f;     // Hour for double and triple pay
    for (int i = 0; i < numberOfEmployee; i++)
    {

        if (empInfo[i].workHour > 0 && empInfo[i].workHour <= 20) {         // Check the straight hour
            payAmount = empInfo[i].workHour * (empInfo[i].payRate);         // Calculate the straight hour amount
        }
        else if (empInfo[i].workHour > 20 && empInfo[i].workHour <= 40) {   // Check the double hour
            extraHour = empInfo[i].workHour - H_LIMIT;                      // Determine the double hour length
            payAmount = H_LIMIT * (empInfo[i].payRate) + 
                        (extraHour * (empInfo[i].payRate) * 2);             // Calculate the amount 
        }
        else
        {
            extraHour = empInfo[i].workHour - H_LIMIT - H_LIMIT;                  // Determine the triple hour length 
            payAmount = H_LIMIT*(empInfo[i].payRate)+H_LIMIT*(empInfo[i].payRate) // Calculate the amount
                    * 2 + (extraHour * (empInfo[i].payRate) * 3);       

        }
        string numToText = numberToText(payAmount);//call numberToText function to format and display the paycheck
        cout << endl;
        cout << endl;
        cout << "\t" << setfill('-') << setw(112) << "" << endl;
        cout << setfill(' ');
        cout << "\t" << "Company Inc." << setw(100) <<"Cheque No: 123456"<<endl;
        cout << "\t" << "123 Street Name" << endl;
        cout << "\t" << "City Name, CA 90000"<< setw(80)<<"Date: 10/18/2022\n";
        cout << "\t" <<endl;
        cout << "\t" << endl;
        cout << "\t" << "PAY TO THE ORDER OF   "<< empInfo[i].employeeName<<endl;
        cout << "\t" << "                      "<<setfill('-')<<setw(78)<< "\n";
        cout << setfill(' ');
        fesetround(FE_DOWNWARD);//set the floating-point rounding direction equal to the argument round
        cout << "\t" << numToText << setw(105-numToText.length()) 
             << "$ " << setprecision(2) << fixed << payAmount << endl;
        cout << "\t" << setfill('-') << setw(100) << "" << endl;
        cout << setfill(' ');
        cout << "\t" << endl;
        cout << "\t" << endl;
        cout << "\t" <<"------------------------------" << setw(70) 
             << "---------------------------------------------" << endl;
        cout << setw(20) << "Memo" << setw(70) << "Authorized Signature\n";
        cout << "\t" << setfill('-') << setw(112) << "" << endl;
        cout << setfill(' ');
       
    }
}
//********************************************************************
// Definition of function numberToText.Use float of amount as @param *                        
// This function convert number to text                              *
// Return amountInText for the check amount                          *
//********************************************************************
string numberToText(float amount) {
    int fractionalPart = (amount - floor(amount)) * 100; // Make the fraction part as integer
    int n2Cnvrt = int(amount);  // Make the number only integer
    string amountInText = "";   // Store the text value of the amount
    ostringstream out;          // To store and convert the 0 padding left

    //Determine 1000's, 100's, 10's, 1's
    unsigned char n1000s, n100s, n10s, n1s;
    n1000s = n2Cnvrt / 1000;   //Shift 3 places to the left
    n100s = n2Cnvrt % 1000 / 100;//Remainder of division of 1000 then shift 2 left
    n10s = n2Cnvrt % 100 / 10;   //Remainder of division of 100 then shift 1 left
    n1s = n2Cnvrt % 10;        //Remainder of division by 10

    //Output the number of 1000's in text
    //Using the Switch Statement
    switch (n1000s) {
    
    case 3: amountInText += "THREE THOUSAND ";
        break;
    case 2: amountInText += "TWO THOUSAND ";
        break;
    case 1: amountInText += "ONE THOUSAND ";
        break;
    }

    //Output the number of 100's
    //Using the Ternary Operator
    n100s == 9 ? amountInText += "NINE HUNDRED " :
        n100s == 8 ? amountInText += "EIGHT HUNDRED " :
        n100s == 7 ? amountInText += "SEVEN HUNDRED " :
        n100s == 6 ? amountInText += "SIX HUNDRED " :
        n100s == 5 ? amountInText += "FIVE HUNDRED " :
        n100s == 4 ? amountInText += "FOUR HUNDRED " :
        n100s == 3 ? amountInText += "THREE HUNDRED " :
        n100s == 2 ? amountInText += "TWO HUNDRED " :
        n100s == 1 ? amountInText += "ONE HUNDRED " : "";

    //Output the number of 10's
    //Using Independent If Statements
    if (n10s == 9)amountInText += "NINETY ";
    if (n10s == 8)amountInText += "EIGHTY ";
    if (n10s == 7)amountInText += "SEVENTY ";
    if (n10s == 6)amountInText += "SIXTY ";
    if (n10s == 5)amountInText += "FIFTY ";
    if (n10s == 4)amountInText += "FOURTY ";
    if (n10s == 3)amountInText += "THIRTY ";
    if (n10s == 2)amountInText += "TWENTY ";
    if (n10s == 1) {
        if (n1s == 9) amountInText += "NINETEEN ";
        else if (n1s == 8) amountInText += "EIGHTEEN ";
        else if (n1s == 7) amountInText += "SEVENTEEN ";
        else if (n1s == 6) amountInText += "SIXTEEN ";
        else if (n1s == 5) amountInText += "FIFTEEN ";
        else if (n1s == 4) amountInText += "FOURTEEN ";
        else if (n1s == 3) amountInText += "THIRTEEN ";
        else if (n1s == 2) amountInText += "TWELVE ";
        else if (n1s == 1) amountInText += "ELEVEN ";
        else
        {
            amountInText += "TEN ";
        }
    }

    //Output the number of 1's
    //Using Dependent If Statements
    if (n10s != 1)
    {
        if (n1s == 9) amountInText += "NINE ";
        else if (n1s == 8)amountInText += "EIGHT ";
        else if (n1s == 7)amountInText += "SEVEN ";
        else if (n1s == 6)amountInText += "SIX ";
        else if (n1s == 5)amountInText += "FIVE ";
        else if (n1s == 4)amountInText += "FOUR ";
        else if (n1s == 3)amountInText += "THREE ";
        else if (n1s == 2)amountInText += "TWO ";
        else if (n1s == 1)amountInText += "ONE ";
    }
    out << setw(2) << std::setfill('0') << fractionalPart; // Padding zero left till two place
    amountInText += "AND " + out.str() + "/100 U.S. DOLLARS";   // Add it to the cheque amount
    return amountInText;    // Return the check amount
}


