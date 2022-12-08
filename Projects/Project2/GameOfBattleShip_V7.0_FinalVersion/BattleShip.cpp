/* 
 * File:   BattleShip.cpp
 * Author: Khadiza Akter
 * Created on December 05, 2022, 6:40 PM
 * Purpose: Implementation file for base class BattleShip
 */
#include <iostream> //Input-output library
#include <stdlib.h> //System()
using namespace std;//Standard Name-space under which System Libraries reside

#include "BattleShip.h"

//Definition of static member variable outside of the class
char BattleShip::yCoord[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 
                               'H', 'I', 'J', '\0' };
//*****************************************************************
//Definition of function drawPlayerArea.Use 2d char array as @param                           *
//Display player matrix                                           *
//*****************************************************************
void BattleShip::showPlayZone(vector<vector<char>> matrixData) {
    system("cls");
    int i = 0;
    // write a text head for computer zone
    // display the x-coordinate value
    cout << "           Your Area                           " << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -            " << endl;
    // loop to draw the 2-D vector using iterator vector
    for (auto it = matrixData.begin(); it != matrixData.end(); it++) {
        cout << " | " << yCoord[i] << " | ";
        for (auto element : *it) {
            cout << element << " ";
        }
        cout << "|" << endl;
        i++;
    }
}