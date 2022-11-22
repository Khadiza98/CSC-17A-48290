/* 
 * File:   BShipSetUp.cpp
 * Author: Khadiza Akter
 * Created on November 21, 2022, 1:28 PM
 * Purpose: Specification file for derived class BShipSetUp
 */

#ifndef BSHIPSETUP_H
#define BSHIPSETUP_H
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <string>
#include <vector>
using namespace std;//Standard Name-space under which System Libraries reside

#include "BattleShip.h" //needed for base class

//This a derived class from base class BattleShip
class BShipSetUp:public BattleShip {    // Declare a class for different types battle ship 
    private:
        static char yCoord[11]; // declare a character array for maintain y-coordinate as a character
        string playerName; // Declare the input array to take player name
        int aircraft[5][2]; //Aircraft length is 5 for tracking its coordinate value
        int battleship[4][2]; // Battleship length is 4 for tracking its coordinate values (row,col)
        int destroyer[3][2]; // Destroyer length is 3 for its coordinate values (row,col)
        int corvette[2][2]; // Corvette length is 2 for tracking its coordinate values (row,col)   
        //Check the ship position conflict with other ship or not
        bool conflictWithOtherShip(vector<vector<char>>, int, int, int, char); 
        
    public:
        //Exception class for InvalidName
        class InvalidName {};
        //constructor #1
        BShipSetUp() {
            playerName = "";
        }
        //constructor #2
        BShipSetUp(string name) {
            bool space = false;
            if(name.empty()) throw InvalidName();
            else if(name.size() > 0) {
                for (int i = 0; i < name.size(); i++) {
                    if (isspace(name[i])) space = true;   
                    else {
                     space = false;
                     break;
                    }
                }
                if(space == true) throw InvalidName();
                else              playerName = name;
            }
        }
        vector<vector<char>> playerMatrix; // to hold player matrix information 
        vector<vector<char>> computerMatrix;// to hold computer Matrix information 
        string getPlayerName()const {return playerName;}
        // mutator function,and set player ship position and return ship members
        BShipSetUp setYourBattleShip(BShipSetUp); 
        //Set computer ship position and return ship members
        BShipSetUp setComputerBattleShip(BShipSetUp);
        //Determine the letter (A,...J) value to integer y-axis
        //value (0,1,2...9)
        friend int letterToRowNumber(char); 
        void drawPlayerArea(vector<vector<char>>); //Display player matrix     
        void gameHead(); //Display player name
        //operator= overloaded
        const BShipSetUp operator=(const BShipSetUp& right); 
        
}; 

#endif /* BSHIPSETUP_H */

