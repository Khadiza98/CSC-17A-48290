/* 
 * File:  Inventory.cpp
 * Author: KhadiZa Akter
 * Created on November 3, 2022, 8:11 PM
 * Purpose: Class Inventory implementation
 */

#include "Inventory.h"

//**************************************************************
//Definition of Inventory. This default constructor 
//set all member variables to 0.
//**************************************************************
Inventory::Inventory() {
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

//************************************************************
//Definition of Inventory. This constructor accepts arguments
//for each member variable except totalCost. 
//Call a setTotalCost function to calculate the total cost
//************************************************************
Inventory::Inventory(int itemNo, int quant, float price) {
    itemNumber = itemNo;
    quantity = quant;
    cost = price;
    setTotalCost(quantity, cost);
}

//************************************************************
//Definition of setTotalCost. This accepts arguments
//to calculate the total cost and store to totalCost member. 
//************************************************************
void Inventory::setTotalCost(int quant, float price) {
    totalCost = quant * price;
}


