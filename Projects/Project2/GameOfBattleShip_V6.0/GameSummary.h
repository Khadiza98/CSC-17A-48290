/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on November 29, 2022, 8:19 PM
 * Purpose: Specification file for  GameSummary class
*/ 

#ifndef GAMESUMMARY_H
#define GAMESUMMARY_H
#include <cstring>          //For strlen(), strcpy()
#include "DateTimeInfo.h"   //Needed for DateTimeInfo class
using namespace std;

class GameSummary { // Declare a class for game summary
    private:
        DateTimeInfo<string>* dt; // Aggregation; use object reference of DateTimeInfo class
        int totalNumberOfAttack;// Total number of attack needed for this game
        char *winner;            // Who is the winner of the game
    public:
        GameSummary(int numOfAttck, char* win, DateTimeInfo<string>* dTime) {
            winner = new char[strlen(win) + 1];
            this->totalNumberOfAttack = numOfAttck;
            strcpy(this->winner,win);
            this->dt = dTime;
        }
        int writeSummary(string, fstream&);
        ~GameSummary() {    // Destructor for delete winner
            //free the memory
            delete winner;
        }
};
#endif /* GAMESUMMARY_H */

