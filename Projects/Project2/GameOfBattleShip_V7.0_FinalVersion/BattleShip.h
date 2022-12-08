/* 
 * File:   BattleShip.h
 * Author: Khadiza Akter
 * Created on December 05, 2022, 6:40 PM
 * Purpose: Specification file of BattleShip base class
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <vector>
using namespace std;

class BattleShip {
    protected:
        static char yCoord[11]; // declare a character array for maintain 
                                // y-coordinate as a character
        vector<vector<char>> arrMatrix; //vector of the player and computer matrix
        
    public:
        const int ROWS = 10;// Constant rows for 10x10 matrix
        const int COLS = 10;// Constant column for 10x10 matrix
        //constructor fill the vector matrix grid (10x10) with '*' character 
        //for computer or player matrix. 
        BattleShip() {
            arrMatrix.resize(10, vector<char>(10, '*'));
        }
        // accessor inline function, return filled array matrix
        vector<vector<char>> getMatrixData() const { return arrMatrix; }
        void showPlayZone(vector<vector<char>>); //Display player zone matrix     

};

#endif /* BATTLESHIP_H */

