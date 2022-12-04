/* 
 * File:   DivSales.h
 * Author: Khadiza Akter
 * Created on November 8, 2022, 2:52 PM
 * Purpose: Specification file for the DivSales class
 */

// specification file for the DivSales class
#ifndef DIVSALES_H
#define DIVSALES_H

const int QUART = 4;

class DivSales {    
    private:
	float salesQ[QUART];      // holds 4 quarters of sales figures for the division
	static float totalSalesY; // holds the total corporate sales of all divisions for the entire year
    public:
	// constructor 
	DivSales() {
            for (int count = 0; count < QUART; count++) {
                    salesQ[count] = 0;//initializes all elements in salesQ array to 0 
            }
	}

	// takes an array that holds sales of 4 quarters and adds all up
        // to totalSales variable and assigns each to static array member variable
	void setSalesAllQ(float allQuarters[]);
	// Accessor function
	float displayQ(int quarter) const {return salesQ[quarter];}
	float getTotalS() const {return totalSalesY;}
	

};



#endif

