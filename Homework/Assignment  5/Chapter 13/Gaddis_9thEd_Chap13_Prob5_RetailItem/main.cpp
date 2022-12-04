/* 
 * File:   main.cpp
 * Author: khadiza Akter
 * Created on November 3, 2022, 111:53 PM
 * Purpose: Demonstrate a RetailItem class by writing a complete program 
 *          implementing it.
 */

//System Level Libraries
#include <iostream> //input-output library
#include <string>   //needed for strings
#include <iomanip>  //needed for format

using namespace std;

//User Defined Libraries
#include "RetailItem.h" // Needed for RetailItem class

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    const int ITEM_NUM = 3;
    // Declare a array of RetailItem for 3 items, initialize first 2 item using
    // constructor and called default constructor for third object
    RetailItem item[ITEM_NUM] = { RetailItem("Jacket", 12, 59.95),
                                RetailItem("Designer Jeans", 40, 34.95)}; 
 
    // Initialize item #3 calling mutator functions
    item[2].setDescription("Shirt");
    item[2].setUnitsOnHand(20);
    item[2].setPrice(24.95);
    
    
    //Display the outputs
    cout << "The Retail Items are: " << endl << endl;
    cout << "-----------------------------------------------------------\n";
    cout << "Item #" << setw(20) << "Description" << setw(20) << "Units On Hand"
         << setw(12) << "Price" << endl;
    cout << "-----------------------------------------------------------\n";
    for (int itm = 0; itm < ITEM_NUM; itm++) { //loop to display the retail item
        
        cout << "Item #" <<  itm+1 << setw(20) << item[itm].getDescription() 
             << setw(13) << item[itm].getUnitsOnHand() << setw(18) 
             << item[itm].getPrice() << endl;
    }
    
    //Exit the program
    return 0;
}


