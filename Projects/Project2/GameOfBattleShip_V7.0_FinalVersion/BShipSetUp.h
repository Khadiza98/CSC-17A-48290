/* 
 * File:   BShipSetUp.h
 * Author: Khadiza Akter
 * Created on December 5, 2022, 6:50 PM
 * Purpose: Specification file of derived BShipSetUp class from both BattleShip
            and AbsDateTime class
 */

#ifndef BSHIPSETUP_H
#define BSHIPSETUP_H
#include <iostream>      //Input-output library
#include <string>        //To work with strings
using namespace std; //Standard Name-space under which System Libraries reside

#include "BattleShip.h"  //needed for base class
#include "AbsDateTime.h" //needed for base class
#include "GameSummary.h" //needed for GameSummary class

//Derived class from both base class BattleShip and AbsDateTime
class BShipSetUp :public BattleShip, public AbsDateTime {
    private:
        string playerName;    // Declare the input array to take player name
        int aircraft[5][2];   //Aircraft length is 5 for its coordinate value
        int battleship[4][2]; // Battleship length is 4 for its coordinate value
        int destroyer[3][2];  // Destroyer length is 3 for its coordinate values 
        int corvette[2][2];   // Corvette length is 2 for tracking its 
                              //coordinate values (row,col)   
        vector<vector<char>> playerMatrix;// to hold player matrix information
        vector<vector<char>> computerMatrix;// to hold computer Matrix information

    public:
        //Exception class for InvalidName
        class InvalidName {};
        //constructor #1
        BShipSetUp() { }
        //constructor #2, check for the validation of player name.if invalid
        //input throw exception, otherwise set name to the playerName
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
        // Draw the computer and player zone and same function name
        // as base class that will provide run-time polymorphism
        void showPlayZone();
        // mutator inline function,and set player name
        void setName(string name) { playerName = name; }
        // Allow the player and computer for attack the ships 
        void startPlay(BShipSetUp, BShipSetUp);
        // The attack was successful or not
        bool checkSuccessful(BShipSetUp&, char, int, int); 
        // Display the ship status for computer and player
        int displayShipStatus(BShipSetUp, BShipSetUp); 
        void saveGame(BShipSetUp, BShipSetUp, vector<vector<char>>, 
                      vector<vector<char>>); // Save the game
        bool openGame(); // Open a saved game
        //Check the ship position conflict with other ship or not
        bool conflictWithOtherShip(vector<vector<char>>, int, int, int, char);
        string currentTime(); // Redefined the virtual method from abstract class
        string currentDate(); // Redefined the virtual method from abstract class
        //Returned vector from a string using a separator character
        vector<int> split(const string& str, char sep); 
        //check file open in or not.
        friend bool openSummaryFile(fstream& infile, string fileName); 
        //find the last player name from file
        friend string readContent(fstream& infile); 
};

#endif /* BSHIPSETUP_H */

