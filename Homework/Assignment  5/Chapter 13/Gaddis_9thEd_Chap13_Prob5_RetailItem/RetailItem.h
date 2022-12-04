/* 
 * File:   Date.h
 * Author: Khadiza Akter
 * Created on November 3, 2022, 3:43 PM
 * Purpose: Class RetailItem specification.
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string> //for strings
using namespace std;

class RetailItem {
    private:
        string description; //Holds a brief description of the item
        int unitsOnHand; // Holds the number of units currently in the inventory
        float price; //Holds the item retail price
    public:
        //default constructor
        RetailItem();
        //constructor
        RetailItem(string, int, float);
        //Mutator inline function
        void setDescription(string desc){description = desc;}
        void setUnitsOnHand(int units) {unitsOnHand = units;} 
        void setPrice(float rPrice) {price = rPrice;}
        //Accessor inline function
        string getDescription()const {return description;}
        int getUnitsOnHand() const {return unitsOnHand;}
        float getPrice() const {return price;}

};

#endif /* RETAILITEM_H */

