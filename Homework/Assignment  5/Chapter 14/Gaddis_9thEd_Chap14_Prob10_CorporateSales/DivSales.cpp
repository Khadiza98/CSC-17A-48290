/* 
 * File:   DivSales.h
 * Author: Khadiza Akter
 * Created on November 8, 2022, 2:52 PM
 * Purpose: Implementation file for the DivSales class
 */

#include "DivSales.h"
//*****************************************************************
// Definition of salesAllQ. This function takes an array that 
// holds sales of 4 quarters and adds all up to totalSales variable
// and assigns each to our static array member variable
//*****************************************************************
void DivSales::setSalesAllQ(float allQuarters[]) {
	for (int count = 0; count < QUART; count++) {
		salesQ[count] = allQuarters[count];
		totalSalesY += allQuarters[count];
	}
}

// definition of the static member variable written outside the class
float DivSales::totalSalesY = 0;

