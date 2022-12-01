/* 
 * File:   BShipSetUp.cpp
 * Author: Khadiza Akter
 * Created on November 26, 2022, 5:44 PM
 * Purpose: Specification file for derived class BShipSetUp
 */

#ifndef BSHIPSETUP_H
#define BSHIPSETUP_H

#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <string>   //To work with strings
#include <vector>   //needed for class container vector in the STL
using namespace std;//Standard Name-space under which System Libraries reside

#include "BattleShip.h" //needed for base class

//This a derived class from base class BattleShip
//class declaration
class BShipSetUp :public BattleShip {    // Declare a class for different types battle ship 
    private:
        static char yCoord[11]; // declare a character array for maintain y-coordinate as a character
        string playerName; // Declare the input array to take player name
        int aircraft[5][2]; //Aircraft length is 5 for tracking its coordinate value
        int battleship[4][2]; // Battleship length is 4 for tracking its coordinate values (row,col)
        int destroyer[3][2]; // Destroyer length is 3 for its coordinate values (row,col)
        int corvette[2][2]; // Corvette length is 2 for tracking its coordinate values (row,col)   

    public:
        //Exception class for InvalidName
        class InvalidName {};
        //constructor #1
        BShipSetUp() {

        }
        //constructor #2
        BShipSetUp(string name) {
            bool space = false;
            if (name.empty()) throw InvalidName();
            else if (name.size() > 0) {
                for (int i = 0; i < name.size(); i++) {
                    if (isspace(name[i])) space = true;
                    else {
                        space = false;
                        break;
                    }
                }
                if (space == true) throw InvalidName();
                else              playerName = name;
            }
        }
        vector<vector<char>> playerMatrix;// to hold player matrix information
        vector<vector<char>> computerMatrix;// to hold computer Matrix informationxs
        // mutator function,and set player ship position and return ship members
        BShipSetUp setYourBattleShip(BShipSetUp); 
        //Set computer ship position and return ship members
        BShipSetUp setComputerBattleShip(BShipSetUp);
        //Determine the letter (A,...J) value to integer y-axis value (0,1,2...9)  
        friend int letterToRowNumber(char);
        void drawPlayerArea(vector<vector<char>>); //Display player matrix     
         //operator= overloaded
        const BShipSetUp operator=(const BShipSetUp& right);
        void showPlayZone();// Draw the computer and player zone
        // mutator inline function,and set player name
        void setName(string name) {playerName = name;}
        string getPlayerName() const { return playerName; }//accessor function
        // Allow the player and computer for attack the ships 
        void startPlay(BShipSetUp, BShipSetUp);
        void gameHead(); //Display player name
        bool checkSuccessful(BShipSetUp&, char, int, int);
        int displayShipStatus(BShipSetUp, BShipSetUp);
        void saveGame(BShipSetUp, BShipSetUp, vector<vector<char>>, vector<vector<char>>);
        bool openGame();
        //Check the ship position conflict with other ship or not
        bool conflictWithOtherShip(vector<vector<char>>, int, int, int, char);
        string currentTime();
        string currentDate();
        vector<int> split(const string& str, char sep);
};
#endif /* BSHIPSETUP_H */

