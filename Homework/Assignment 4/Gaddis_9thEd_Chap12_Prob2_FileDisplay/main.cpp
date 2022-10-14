/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 10/13/2022
 * Purpose: Read in first 24 lines from the file 
            then pause for get the key by user
 */
//System Level Libraries
#include <iostream> //input-output library
#include <string>
#include <fstream> //i/o
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
bool fileOpenIn(fstream&); //check file open correctly
//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    fstream inputFile; //declare fstream object to read in file
    string lines;       //to read in line from the file
    string fileName;    //to take input from the user
    int countLine = 0;  //to count the number of lines read in
    char again;         //to get a char by user
    
    cout << "Enter the file name to read in: " << endl;
    getline(cin, fileName);
    //open the file to read in
    inputFile.open(fileName, ios::in);
    
    if(fileOpenIn(inputFile)) { //check the file open in
        cout << "File opened successfully " << endl;
        cout << "Now read in from the file...... " << endl;
        
        while(getline(inputFile, lines)) { //Read string from the file until the end of file
            countLine++;
            cout << lines << endl; //print lines
            
            if(countLine % 24 == 0) {//if lines are 24, pause to get any key by user
                cout << "Press any key to continue " << endl;
                cin.ignore();
                cin.get(again); //get a key 
            }
        }
        cout << "File read in 'Done'!!!!" << endl;
        //close the file
        inputFile.close();
    } 
    else {
        cout << "Error to open the file!!!" << endl;
    }
    
    //Exit the program
    return 0;
}
//***********************************************
//Definition of function fileOpenIn
//This function check file open in or not 
//return boolean data type
//***********************************************
bool fileOpenIn(fstream &in) {
    if(in) {
        return true;
    } else {
        return false;
    }
}
