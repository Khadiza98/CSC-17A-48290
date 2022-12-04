/* 
 * File:   main.cpp
 * Author: khadiza Akter
 * Created on November 3, 2022, 111:53 PM
 * Purpose: Demonstrate a Inventory class by writing a complete program.
 */

//System Level Libraries
#include <iostream> //input-output library
#include <string>   //needed for strings
#include <iomanip>  //needed for format

using namespace std;

//User Defined Libraries
#include "Inventory.h" // Needed for Inventory class

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int itemNumInput;    //Holds the input for number of items
    int quantityInput;   //Holds the input for quantity of item
    float costInput;     //Holds the input for per unit cost
    
    do {
        cout << "Enter the total items number in a retail store's inventory: ";
        cin >> itemNumInput;
    } while(itemNumInput < 0); //check input validation
    cout << fixed << setprecision(2);
    if (itemNumInput == 0) {
        cout << "There is no item in a retail store's inventory!!!" << endl;
    }
    else if (itemNumInput == 1) {
        
        do {
        cout << "Enter the quantity of item #1: ";
        cin >> quantityInput;
        } while(quantityInput < 0); //check input validation
        do {
            cout << "Enter the per unit cost of item #1: $";
            cin >> costInput;
        } while(costInput < 0); //check input validation
        //create an inventory object with default constructor
        Inventory item1; 
        //utilize the mutator function
        item1.setItemNumber(itemNumInput);
        item1.setQuantity(quantityInput);
        item1.setCost(costInput);
        item1.setTotalCost(quantityInput, costInput);
        //display the data for item 1
        cout << "\nThe following items are in inventory:\n";
        cout << "Item #" << item1.getItemNumber() << "\t\tQuantity: "
             << item1.getQuantity() << "\t\tCost Per Unit: $" << item1.getCost() 
             << "\t\tTotal Cost: $" << item1.getTotalCost() << endl;
              
    } //end else if
    else {
        
        Inventory *ptrItem = new Inventory[itemNumInput]; //dynamically create Inventory array
        //loop to initialize value to member variable and display them
        for (int item = 0; item < itemNumInput; item++) {
            do {
                cout << "Enter the quantity of item #" << item+1 << ": ";
                cin >> quantityInput;
            } while(quantityInput < 0);
            do {
                cout << "Enter the per unit cost of item #" << item+1 << ": $";
                cin >> costInput;
            } while(costInput < 0);
            ptrItem[item] = {Inventory((item+1), quantityInput, costInput)};
        } //end for-loop
        
        //loop to display the items in inventory
        cout << "\nThe following items are in inventory:\n";
        for (int item = 0; item < itemNumInput; item++) {
            //display the data for items
            cout << "Item #" << ptrItem[item].getItemNumber() << "\t\tQuantity: "
                 << ptrItem[item].getQuantity() << "\t\tCost Per Unit: $" 
                 << ptrItem[item].getCost() << "\t\tTotal Cost: $" 
                 << ptrItem[item].getTotalCost() << endl;
             
        } //end for-loop
        //free the memory
        delete []ptrItem;
        
    } //end else
    
    
    //Exit the program
    return 0;
}

