/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on November 8, 2022, 2:50 PM
 * Purpose: Demonstrate a DivSales class of six division of four quarter by
 *          writing a complete program
 */

#include <iostream>
#include "DivSales.h"

using namespace std;

const int NUM_DIV = 6;		// Number of divisions
const int NUM_QUART = 4;	// Number of quarters

int main() {
    //Declare variable
    DivSales divisions[NUM_DIV]; // creates array of DivSales for 6 division
    float qSales[NUM_QUART];// store sales of 4 quarters for each div in this array
    

    // ask user to enter the sales for four quarters of each division
    cout << "Enter four quarter sales of each division: \n"; 
    for (int div = 0; div < NUM_DIV; div++) {
        cout << "********* Division " << (div + 1) << " **********"<< endl;
        // reset quarter sales for each division
        for (int reset = 0; reset < NUM_QUART; reset++) qSales[reset] = 0;

        for (int quart = 0; quart < 4; quart++) {

                do {
                    cout << "Quarter " << (quart + 1) << ": $";
                    cin >> qSales[quart];
                    
                } while (qSales < 0);	//check input validation
        }//end for-loop
        // set sales of 4 quarters for the division to the setSalesAllQ member function.
        divisions[div].setSalesAllQ(qSales);
    } //end for-loop

    //Display the information
    cout << "\n*************THE DIVISION SALES FOR EACH QUARTER*************\n";


    // display division sales for each quarter
    for (int division = 0; division < NUM_DIV; division++) {
        cout << "\n\tDIVISION " << (division + 1) << endl;

        for (int quart = 0; quart < NUM_QUART; quart++) {
                cout << "    Quarter " << (quart + 1) << ": -> $";
                cout << divisions[division].displayQ(quart) << endl;
        }//end for-loop
    }//end for-loop



    // display the total corporate sales
    cout << "\nTotal Corporate Sales: $" << divisions[0].getTotalS() << endl;


    return 0;
}

