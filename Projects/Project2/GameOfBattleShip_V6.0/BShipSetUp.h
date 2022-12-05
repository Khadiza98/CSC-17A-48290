/* 
 * File:   BShipSetUp.cpp
 * Author: Khadiza Akter
 * Created on November 29, 2022, 8:07 PM
 * Purpose: Specification file for derived class BShipSetUp
 */

#ifndef BSHIPSETUP_H
#define BSHIPSETUP_H

#include <iostream>      //Input-output library
#include <string>        //To work with strings
#include "BattleShip.h"  //needed for base class
#include "GameSummary.h" //needed for GameSummary class
using namespace std;//Standard Name-space under which System Libraries reside

//This a derived class from base class BattleShip
class BShipSetUp:public BattleShip {    // Declare a class for different types battle ship 
    private:
        string playerName; // Declare the input array to take player name
        int aircraft[5][2]; //Aircraft length is 5 for tracking its coordinate value
        int battleship[4][2]; // Battleship length is 4 for tracking its coordinate values (row,col)
        int destroyer[3][2]; // Destroyer length is 3 for its coordinate values (row,col)
        int corvette[2][2]; // Corvette length is 2 for tracking its coordinate values (row,col)   
        vector<vector<char>> playerMatrix;// to hold player matrix information
        vector<vector<char>> computerMatrix;// to hold computer Matrix information

    public:
        //Exception class for InvalidName
        class InvalidName {};
        //default constructor #1
        BShipSetUp() { }
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
        string getPlayerName() const { return playerName; }//accessor function
        // mutator function,and set player ship position and return ship members
        BShipSetUp setYourBattleShip(BShipSetUp);
        //Set computer ship position and return ship members
        BShipSetUp setComputerBattleShip(BShipSetUp);
        //Determine the letter (A,...J) value to integer y-axis value (0,1,2...9)  
        friend int letterToRowNumber(char);
         //operator= overloaded
        const BShipSetUp operator=(const BShipSetUp& right);
        bool operator ==(const BShipSetUp& equal);// Operator overloading ==
        void showPlayZone();// Draw the computer and player zone
        // mutator inline function,and set player name
        void setName(string name) { playerName = name; }
        // Allow the player and computer for attack the ships 
        void startPlay(BShipSetUp, BShipSetUp);
        bool checkSuccessful(BShipSetUp&, char, int, int); // The attack was successful or not
        int displayShipStatus(BShipSetUp, BShipSetUp); // Display the ship status for computer and player
        void saveGame(BShipSetUp, BShipSetUp, vector<vector<char>>, vector<vector<char>>); // Save the game
        bool openGame(); // Open a saved game
        void drawPlayerArea(vector<vector<char>>); //Display player matrix 
        //Check the ship position conflict with other ship or not
        bool conflictWithOtherShip(vector<vector<char>>, int, int, int, char);
        string currentTime(); // Redefined the virtual method from abstract class
        string currentDate(); // Redefined the virtual method from abstract class
        vector<int> split(const string& str, char sep); //Returned vector from a string using a separator character
        friend bool openSummaryFile(fstream& infile, string fileName); //check file open in or not.
        friend string readContent(fstream& infile); //find the last player name from file
        ~BShipSetUp() {
        }
};

#endif /* BSHIPSETUP_H */

