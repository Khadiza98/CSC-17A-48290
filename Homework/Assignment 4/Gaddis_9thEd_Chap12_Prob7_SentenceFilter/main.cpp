/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 10/10/2022
 * Purpose: Read in from one file and write to the other file in formatted manner,
 *          change all the letters to lowercase except the first letter of
 *          sentence which should be uppercase.  
 */
 //System Level Libraries
#include <iostream> //input-output library
#include <string>
#include <fstream> //i/o
#include <cctype> //isspace(), tolower() etc.
using namespace std;

//Function Prototypes
bool fileOpenIn(fstream&);

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    fstream inputFile, outputFile; //declare fstream objects to read and write in file
    char ch;                //to read and write a character in file
    string fileName1;    //to take input from the user
    string fileName2;   //to take input from the user
    int countLine = 0;  //to count the number of lines read in

    do{
        cout << "Enter the first file name to read in: " << endl;
        getline(cin, fileName1);
        //open the file to read in
        inputFile.open(fileName1, ios::in);
        //check the first file open in
        if (!inputFile) {
            cout << "Error to open the file " << endl;
        }
    } while(inputFile.fail()); //until file open in try to get filename again 

    cout << "Enter the second file name to write out: " << endl;
    getline(cin, fileName2);
    //open the file to write out
    outputFile.open(fileName2, ios::out);
    if (!outputFile) {
        cout << "Error to open the output file!!" << endl;
        return 0;
    }
    
    cout << "Now read in from the first file ...... " << endl;
    cout << "\nWriting to the second file........\n";

    //read a character from input file
    inputFile.get(ch);
    //while last char read in successful, then continue
    while(inputFile) {
        //check for space character           
        while (isspace(ch)) {
            outputFile.put(ch);
            inputFile.get(ch);
        }
        //write the first char in upper case letter
        outputFile.put(toupper(ch));
        //read and write out other character in lower case letter until the '.' found
        do{
            inputFile.get(ch);
            outputFile.put(tolower(ch));
        } while (ch != '.');
        //read the char again
        inputFile.get(ch);
    }

    //close the file
    inputFile.close();
    outputFile.close();
    
    //Exit the program
    return 0;
}
