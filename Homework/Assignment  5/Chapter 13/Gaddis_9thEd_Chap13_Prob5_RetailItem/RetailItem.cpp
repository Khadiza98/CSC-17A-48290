/* 
 * File:   Date.cpp
 * Author: Khadiza Akter
 * Created on November 3, 2022, 3:40 PM
 * Purpose: Class RetailItem implementation
 */

#include "RetailItem.h" //need for RetailItem class 
#include <string> //for strings
using namespace std;

//**************************************************************
//Definition of RetailItem. This default constructor initialize
//description with "", unitsOnHand with 0, price with 0.0f.
//**************************************************************
RetailItem::RetailItem() {
    description = "";
    unitsOnHand = 0;
    price = 0.0f;
}

//************************************************************
//Definition of RetailItem. This constructor accepts arguments
// for each member variable.
//************************************************************
RetailItem::RetailItem(string desc, int units, float rPrice) {
    description = desc;
    unitsOnHand = units;
    price = rPrice;
}

