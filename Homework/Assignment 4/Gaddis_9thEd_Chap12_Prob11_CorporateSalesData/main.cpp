/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 13, 2022, 10:00 AM
 * Purpose: Fill structure data and record them on binary file
 */
//System Level Libraries
#include <iostream> //input-output library
#include <string>  //to work with string
#include <iomanip> //setw()
#include <fstream> //I/O
using namespace std;

//Global Constants
const int SIZE = 4;
//structure declaration
struct CorporateData{
    static string nameDivision[SIZE];  //array of division name
    float  quarter[SIZE];    //array of number of quarter
    float quarterlySale; //sale by quarterly
};

string CorporateData::nameDivision[SIZE] = {"East", "West", "North", "South"}; //initialized member of structure

//Function Prototypes
void writeTxt(fstream&, CorporateData*, int); //write to a text file

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable 
    fstream txtFile, binFile; //declare object of fstream to write in text and binary file
    CorporateData sales;    //structure variable
    int index = 0;          //loop counter variable
    
    //open text and binary file for output
    txtFile.open("data.txt", ios::out);
    binFile.open("corpdata.dat", ios::out | ios::binary);
    
    //initializing the structure data member
    cout << "Enter the quarterly sales for each quarter of four divisions: " << endl;
    
    //Ask user to enter the four quarter sales for each division
    do{ 
        cout <<"Name: " << sales.nameDivision[index] << endl;
        
        for (int i = 0; i < SIZE; i++) {
            
            do{
            cout << "Quarter #" << (i+1) << ":";
            cin >> sales.quarterlySale;
            if(sales.quarterlySale < 0) cout << "Enter the positive value, please" <<endl;
            } while(sales.quarterlySale < 0); //check input validation
            
            sales.quarter[i] = sales.quarterlySale; //assign quarterlySale to the each quarter
        }
        
        cout << "Writing to a text and  binary file...." << endl;
        writeTxt(txtFile, &sales, index);
        binFile.write(reinterpret_cast<char *>(&sales), sizeof(sales));
        index++;
        
    } while(index < SIZE);
    
    cout << "Writing is done!!!" << endl; 
    //close the file
    txtFile.close();
    binFile.close();
    //Exit stage right!
    return 0;
}
//********************************************************
//Definition of writeTxt                              *
//Write to a text file                             *
//********************************************************
void writeTxt(fstream& out, CorporateData *a, int index){
    out << endl;
    out << "Structure Contents: " << endl;
    out << setw(10) << a->nameDivision[index] << endl;
    for (int i = 0; i < SIZE; i++) {
        out << setw(10) << a->quarter[i] << endl;
    }
    out << endl;
   
}
