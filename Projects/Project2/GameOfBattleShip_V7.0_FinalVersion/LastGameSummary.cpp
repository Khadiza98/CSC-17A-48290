/* 
 * File:   LastGameSummary.cpp
 * Author: Khadiza Akter
 * Created on December 5, 2022, 7:19 PM
 * Purpose: Implementation file of LastGameSummary class
 */
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

#include "LastGameSummary.h"

//***********************************************************************
//Definition of operator<< overloading function.Use an ostream reference
//object and a constant LastGameSummary class reference object. this 
//return a reference to an ostream object.
//***********************************************************************
ostream& operator<<(ostream& output, const LastGameSummary& objLastSumm) {
    output << "\t\t Player name: " << objLastSumm.plName << endl
        << "\t\t Date: " << objLastSumm.dateOfPlay << endl
        << "\t\t Start time: " << objLastSumm.startTime << endl
        << "\t\t End time: " << objLastSumm.endTime << endl
        << "\t\t Total attack: " << objLastSumm.totalAttack << endl;;
    return output;
}
        
//*****************************************************************
//Definition of function lastWinner. 
//Input->:None, and read text file to get the name of winner
//Output->:Return string winner
//*****************************************************************
string LastGameSummary::lastWinner() {
    char ch; //to get a char from text file
    string winner;
    string sInfo[6];        // To hold info from file
    string line;            // To hold line from file 
    string delimiter = ";"; // For split the line
    int i = 0;              // To track the sInfo array index
    size_t pos = 0;         // To hold the size of sub-string

    fstream file("gameSummary.txt", ios::in); //open file to read in
    if (file.fail()) {//Check file open in or not
        cout << "No information available now" << endl;
        return "";
    }
    //Read from file to string
    getline(file, line);
    // Split the line
    while ((pos = line.find(delimiter)) != std::string::npos) {
        sInfo[i] = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        i++;
    }//end while-loop
    if (sInfo[5] == "p") {
        winner = "Human";
    }
    else if (sInfo[5] == "c") {
        winner = "Computer";
    }
    else {
        winner = "None(saved game)";
    }
    file.close();
    return winner;
} //End lastWinner function

//**************************************************************************
//Definition of function lastGameSummary. 
//Input->:None, this function write and read text file for last game summary
//Output->:Return none
//**************************************************************************
void LastGameSummary::lastGameSummary() {
    //Declare variable
    string delimiter = ";"; // For split the line
    string name = "";       // To hold name of the player
    char yn;                // ask to get input for updating or not
    char ch;                // To get a char from file
    string sInfo[6];        // To hold info from file
    string line;            // To hold line from file 
    int i = 0;              // To track the sInfo array index
    size_t pos = 0;         // To hold the size of sub-string
    //Open file to write and read in simultaneously
    fstream file("gameSummary.txt", ios::in | ios::out);
    if (file.fail()) {
        cout << "No summary available now" << endl;
        return;
    }//end if
    //Read from file to string
    getline(file, line);
    // Split the line
    while ((pos = line.find(delimiter)) != std::string::npos) {
        sInfo[i] = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        i++;
    }//end while-loop
    //Display the output to the screen
    LastGameSummary objLastGmSummary(*sInfo, *(sInfo + 1), *(sInfo + 2), *(sInfo + 3), stoi(*(sInfo + 4)));
    LastGameSummary objLastGmSummary_new(objLastGmSummary); // call the copy constructor
    cout << objLastGmSummary_new;
    file.close();//close the file
} //End LastGameSummary function

