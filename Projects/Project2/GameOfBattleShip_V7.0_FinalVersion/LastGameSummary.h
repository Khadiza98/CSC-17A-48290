/* 
 * File:   LastGameSummary.h
 * Author: Khadiza Akter
 * Created on December 5, 2022, 7:19 PM
 * Purpose: Specification file of LastGameSummary class
 */

#ifndef LASTGAMESUMMARY_H
#define LASTGAMESUMMARY_H
#include <string>
using namespace std;

class LastGameSummary {
    private:
        string plName;      //Last game's player name
        string dateOfPlay;  // Date of the play
        string startTime;   // Start time of the play
        string endTime;     // End time of the play
        int totalAttack;    // Total number of attack of play
    public:
        //constructor #1
        LastGameSummary() {plName = "";}
        //Constructor #2
        LastGameSummary(string pName, string dPlay, string sTime, 
                        string eTime, int tAttack) {
            plName = pName;
            dateOfPlay = dPlay;
            startTime = sTime;
            endTime = eTime;
            totalAttack = tAttack;
        }
        // Copy constructor
        LastGameSummary(LastGameSummary& objLastSumm) {
            plName = objLastSumm.plName;
            dateOfPlay = objLastSumm.dateOfPlay;
            startTime = objLastSumm.startTime;
            endTime = objLastSumm.endTime;
            totalAttack = objLastSumm.totalAttack;
        }
        void lastGameSummary();
        //Friend, Operator<< overloading for displaying data
        friend ostream& operator<<(ostream&, const LastGameSummary&);
        string lastWinner(); // Last winner of the game
        
};

#endif /* LASTGAMESUMMARY_H */

