/* 
 * File: main.cpp   
 * Author: Khadiza Akter
 * Created on 9/20/2022
 * Purpose: calculating and displaying corporate sales data of four division  
 */

//System Libraries
#include <iostream>
#include <string> //work with string
#include <iomanip> //setprecision()
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
//structure declaration
struct SalesData{
    string name;         //the division name
    float totalAnnualS,  //total annual sales of each division
           avgQurtSales, //average Qrt. sales of each division
           firstQrtS,    //first quarter sale
           secondQrtS,   //second quarter sale
           thirdQrtS,    //third quarter sale
           fourthQrtS;   //four quarter sale
};

//Function Prototypes
void getSalesInfo(SalesData& ); //used to get all information about 4 divisions

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    const int NUM_BRANCE = 4;
    SalesData divName[NUM_BRANCE] = {{"North"}, {"West"}, {"East"}, {"South"}}; //Array of structures initialized with brances names.
    SalesData divisions; //structure variable
    
    //Process or map Inputs/Known to Outputs and Display Outputs
    for (int index=0; index<NUM_BRANCE; index++) {
        cout<<divName[index].name<<endl;
        getSalesInfo(divisions);
        if (index == 0 || index == 1 || index == 2) { //checking for create a newline
            cout << endl;
        } 
    }

    //Exit stage right!
    return 0;
}
/*
 *This function used to get all information about the corporate sales.
 *@Param div is a structure variable to work with structure date member
 *@Return none
 */
void getSalesInfo(SalesData &div) {
    
    cout<<"Enter first-quarter sales:"<<endl;
    cin>>div.firstQrtS;
    cout<<"Enter second-quarter sales:"<<endl;
    cin>>div.secondQrtS;
    cout<<"Enter third-quarter sales:"<<endl;
    cin>>div.thirdQrtS;
    cout<<"Enter fourth-quarter sales:"<<endl;
    cin>>div.fourthQrtS;
    
    //calculate total annual sale
    div.totalAnnualS = div.firstQrtS+div.secondQrtS+div.thirdQrtS+div.fourthQrtS; 
    cout <<fixed<<setprecision(2)<<showpoint; //output formatting with 2 decimal place
    cout<<"Total Annual sales:$"<<div.totalAnnualS<<endl;
    //calculate average quarter sales
    div.avgQurtSales = div.totalAnnualS / 4; 
    cout<<"Average Quarterly Sales:$" << div.avgQurtSales;
    
}
