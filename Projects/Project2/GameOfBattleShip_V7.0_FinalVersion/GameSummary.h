/* 
 * File:   GameSummary.h
 * Author: Khadiza Akter
 * Created on December 5, 2022, 7:11 PM
 * Purpose: Specification file of GameSummary class
 */

#ifndef GAMESUMMARY_H
#define GAMESUMMARY_H
#include <cstring> //For strlen(), strcpy()
using namespace std;

#include "DateTimeInfo.h" //Needed for DateTimeInfo class

class GameSummary { // Declare a class for game summary
    private:
        DateTimeInfo<string>* dt; // Aggregation; use object reference of DateTimeInfo class
        int totalNumberOfAttack;  // Total number of attack needed for this game
        char *winner;             // Who is the winner of the game
    public:
        //default constructor #1
        GameSummary() {
            totalNumberOfAttack = 0;
        }
        //constructor #2
        GameSummary(int numOfAttck, char* win, DateTimeInfo<string>* dTime) {
            winner = new char[strlen(win) + 1];
            this->totalNumberOfAttack = numOfAttck;
            strcpy(this->winner,win);
            this->dt = dTime;
        }
        int writeSummary(string, fstream&);
        // Destructor for delete winner
        ~GameSummary() {           
            //free the memory
            delete winner;
        }
};

#endif /* GAMESUMMARY_H */

