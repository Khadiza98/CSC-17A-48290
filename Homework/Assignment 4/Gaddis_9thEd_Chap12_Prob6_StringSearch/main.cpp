/*
String Search
Write a program that asks the user for the name of a file and a string to search for. The program
will search the file for all occurrences of the specified string and display all lines that
contain the string. After all occurrences have been located, the program should report the
number of times the string appeared in the file.
*/
/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 10/13/2022
 * Purpose:Read a file and search for a specified string for all occurrence
 */
 //System Level Libraries
#include <iostream> //input-output library
#include <string>  //to work with string
#include <fstream> //I/O

using namespace std;

//User Defined Libraries
//Global Constants, not Global Variables
//structure declarations


int main(int argc, char** argv) {
    //Declare variable
    fstream inFile;  //declare fstream object to read in file
    string fileName; //to hold the name of file
    string str;      //read string from the file
    string search;   //to hold the specified search string
    int count = 0;   //number of occurrence of search string, initialized with default value
    int index = 0;   //to track the all occurrence of search string

    cout << "Enter the name of a file to read in: " << endl;
    cin >> fileName;
    
    //open the file
    inFile.open(fileName, ios::in);
    //check the file open correctly or not
    if (!inFile) {
        cout << "Error to open the file!!!!" << endl;
        cout << "Need to process it.........." << endl;
        return 0;
    }
    //ask user to enter a string to search on file
    cout << "Enter a string to search in file: ";
    cin >> search;

    inFile.seekg(0, ios::beg);
    getline(inFile, str); //read first string line from file
    //while read the file successfully
    while (inFile) {

        //search the string line for all occurrence until the length of string
        while (str.find(search, index) < str.length()) {
            cout << str << endl;
            count++; //number of occurrence
            index = (str.find(search, index)) + 1;
        }

        getline(inFile, str); //read next string line from file
        index = 0;
    }
    //number of times the string appeared in the file.
    cout << "\nThe search string appeared in file: " << count << " times " << endl;

    //close the file
    inFile.close();
    //Exit the program
    return 0;
}

