/* 
 * File:   GameSummary.cpp
 * Author: Khadiza Akter
 * Created on December 5, 2022, 7:11 PM
 * Purpose: Implementation file of GameSummary class
 */
#include <fstream>  //File I/O
#include <iomanip>  //Format the output
using namespace std;

#include "GameSummary.h"

//*******************************************************************
//Definition of function writeSummary. Use structure pointer, fstream
//object as @param. This function write game summary in a file
//Return integer value
//*****************************************************************
int GameSummary::writeSummary(string pName, fstream& gmInfo) {
    gmInfo.open("gameSummary.txt", ios::out);
    gmInfo << pName << ";";
    gmInfo << dt->getDateOfPlay()<< ";";
    gmInfo << dt->getStartTimePlay() << ";";
    gmInfo << dt->getEndTimeOfPlay() << ";";
    gmInfo << totalNumberOfAttack << ";";
    gmInfo << winner <<";";
    gmInfo.close();
    return 0;
} // End writeSummary function

