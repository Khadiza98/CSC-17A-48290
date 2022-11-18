/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on November 13, 2022, 10:02 PM
 * Purpose: Specification file for BattleShip class
 */
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

class BattleShip {
    private:
        char** arrMatrix; //pointer to the array
    
    public:
        const int ROWS = 10;// Constant rows for 10x10 matrix
        const int COLS = 10;// Constant column for 10x10 matrix
        //constructor fill the arrMatrix dynamically
        BattleShip();
         
        // accessor inline function, return filled array matrix
        char** getMatrixData()const {
            return arrMatrix;
        } 
        //Destructor
        ~BattleShip() {
            //Free the memory after the use of array
            for (int i = 0; i < ROWS; i++) {
              delete[] arrMatrix[i];
            }
        }
};

#endif /* BATTLESHIP_H */