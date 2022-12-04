/* 
 * File:   Inventory.h
 * Author: KhadiZa Akter
 * Created on November 3, 2022, 8:11 PM
 * Purpose: Class Inventory specification
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
    private:
        int itemNumber; //Holds the item number
        int quantity;   //Holds the quantity of item
        float cost;     //Holds the per unit cost
        float totalCost; //Holds the total inventory cost
    public:
        //default constructor
       Inventory();
       //constructor
       Inventory(int, int, float);
       //Mutator function
       void setItemNumber(int iNum) {itemNumber = iNum;}
       void setQuantity(int qunt) {quantity = qunt;}
       void setCost(float price) {cost = price;}
       void setTotalCost(int, float);
       //Accessor function
       int getItemNumber() const {return itemNumber;}
       int getQuantity() const {return quantity;}
       float getCost() const {return cost;}
       float getTotalCost() const {return totalCost;}
    
};

#endif /* INVENTORY_H */

