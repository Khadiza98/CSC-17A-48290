/* 
 * File: BattleShip.cpp
 * Author: Khadiza Akter
 * Created on November 29, 2022, 8:19 PM
 * Purpose: Implementation file for  GameSummary class
*/ 
#include <fstream>  //File I/O
#include <iomanip>  //Format the output
#include "GameSummary.h"
using namespace std;

//*******************************************************************
//Definition of function writeSummary. Use string pName, fstream
//object as @param. This function write game summary in a file
//Return integer value
//*****************************************************************
int GameSummary::writeSummary(string pName, fstream& gmInfo) {
    gmInfo.open("gameSummary.txt", ios::out);
    gmInfo << pName << ";"
           << setw((dt->getDateOfPlay()).size() + 1);
    gmInfo << dt->getDateOfPlay()<< ";";
    gmInfo << setw(dt->getStartTimePlay().size() + 1);
    gmInfo << dt->getStartTimePlay() << ";";
    gmInfo << setw(dt->getEndTimeOfPlay().size() + 1);
    gmInfo << dt->getEndTimeOfPlay() << ";";
    gmInfo << setw(to_string(totalNumberOfAttack).size() + 1);
    gmInfo << totalNumberOfAttack << ";";
    gmInfo << setw(2);
    gmInfo << winner;
    gmInfo.close();
    return 0;
} // End writeSummary function


