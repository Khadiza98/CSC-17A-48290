/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 10/13/2022
 * Purpose: write array contents to a binary file and
 *          read back from the file and display
 */
 //System Level Libraries
#include <iostream>  //input-output library
#include <string>
#include <ctime>    //Time for rand
#include <cstdlib>  //Srand to set the seed
#include <fstream>  //File I/O
#include <iomanip>  //setw()


using namespace std;

//Function Prototypes
void arrayToFile(string, int*, const int); //write array content to the binary file
void fileToArray(string, int*, const int); //read in binary file

//Execution begins here!
int main(int argc, char** argv) {
    //random seed here
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int size = 50;  //size of array
    int array[size];      //static array of int
    string fileName;      //to store filename from user
    
    //ask user to enter the file name for output
    cout << "Enter the file name for output: " << endl;
    cin >> fileName;
    
    //fill the array elements with random values
   for (int i = 0; i < size; i++) {
        array[i] = rand() % 50 + 1; //assign random value to array (range from 0 to 50)
   }
    //write array content to the binary file
    cout << "Writing the data to the file.\n";
    arrayToFile(fileName, array, size);
    
    //read in binary file 
    cout << "Reading the data back into memory." << endl;
    fileToArray(fileName, array, size);

    //Display the contents of the array
    cout << "The contents of the array are: " << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(3) << array[i] << " ";
        if ((i + 1) % 10 == 0) cout << endl; //print 10 element in per line
    }
    cout << endl;

    
    //Exit the program
    return 0;
}
//********************************************************
//Definition of arrayToFile                              *
//Write array content to the binary file                 *
//********************************************************
void arrayToFile(string fileName, int* arr, const int size) {
      
    fstream outfile; //declare the fstream object for output in binary file
    //open the file for output in binary mode
    outfile.open(fileName, ios::out | ios::binary);
    if (!outfile) { //check file opened or not
        cout << "Error to open the file!!" << endl;
    }
    //write array contents to the binary file
    outfile.write(reinterpret_cast<char*>(arr), sizeof(int)*size);
    //close the file
    outfile.close();
}
//********************************************************
//Definition of fileToArray                              *
//Read in from binary file                               *
//********************************************************
void fileToArray(string fileName, int* arr, const int size) {
    fstream inFile; //declare the fstream object to read in binary file

    inFile.open(fileName, ios::in | ios::binary);//open the file for input in binary mode
    if (!inFile) { //check file opened or not
        cout << "Error to open the file!!" << endl;
       
    }
    //read from the binary file
    inFile.read(reinterpret_cast<char*>(arr), sizeof(int)*size);
    //close the file
    inFile.close();
    
}

