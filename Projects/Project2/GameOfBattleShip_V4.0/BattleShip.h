/* 
 * File:   BShipSetUp.cpp
 * Author: Khadiza Akter
 * Created on November 21, 2022, 1:56 PM
 * Purpose: Specification file for base class BattleShip
 */

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <vector>
using namespace std;

class BattleShip {
    private:
       vector<vector<char>> arrMatrix; //pointer to the array
    
    public:
        const int ROWS = 10;// Constant rows for 10x10 matrix
        const int COLS = 10;// Constant column for 10x10 matrix
		 
        //constructor fill the array matrix grid (10x10) with '*' character 
        //for computer or player matrix. 
        BattleShip() {
            arrMatrix.resize(10, std::vector<char>(10, '*'));
        }
        // accessor inline function, return filled array matrix
        vector<vector<char>> getMatrixData() const { return arrMatrix; };
        
};

#endif /* BATTLESHIP_H */

