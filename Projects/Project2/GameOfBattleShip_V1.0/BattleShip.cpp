/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on November 13, 2022, 10:02 PM
 * Purpose: Implementation file for BattleShip class
 */
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
using namespace std;//Standard Name-space under which System Libraries reside

#include "BattleShip.h" //needed for BattleShip class


//****************************************************************
//Defintion of BattleShip. This constructor dynamically fill the 
//array matrix grid (10x10) with '*' character 
//for computer or player matrix.
//****************************************************************
BattleShip::BattleShip() {
    int i, j; //loop counter variable
    arrMatrix = nullptr; 
    arrMatrix = new char* [ROWS]; //Allocating the row space in heap dynamically
    for (i = 0; i < ROWS; i++) {
        arrMatrix[i] = new char[COLS];  //Allocating the column space in heap dynamically
    }
    //read into the array
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arrMatrix[i][j] = '*';      //set the '*' character for the matrix
        }
    }
}