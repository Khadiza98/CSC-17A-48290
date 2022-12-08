/* 
 * File:   BShipSetUp.cpp
 * Author: Khadiza Akter
 * Created on December 5, 2022, 6:50 PM
 * Purpose: Implementation file of derived BShipSetUp class from both BattleShip
            and AbsDateTime class
 */

#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed
#include <ctime>    //set for time()
#include <cstring>  //For memcpy()
#include <fstream>  //File I/O
#include <stdlib.h> //System()
#include <sstream>
using namespace std;//Standard Name-space under which System Libraries reside

#include "BShipSetUp.h"

//*******************************************************************
//Definition of function operator==. This is an operator== overloaded  
//function of BShipSetUp class, use constant object of BShipSetUp 
//class as @param and also return boolean               
//*******************************************************************
bool BShipSetUp::operator ==(const BShipSetUp& equal) {
    if (sizeof(aircraft) == sizeof(equal.aircraft) && sizeof(battleship)
        == sizeof(equal.battleship) && sizeof(destroyer) == sizeof(equal.destroyer)
        && sizeof(corvette) == sizeof(equal.corvette)) {
        return true; // check the equality of both player and computer battle ship
    }
    else {
        return false;
    }
}
//*******************************************************************
//Definition of function operator=. This is an operator= overloaded  
//function of BShipSetUp class, use constant object of BShipSetUp 
//class as @param and also return constant object of that class               
//*******************************************************************
const BShipSetUp BShipSetUp::operator=(const BShipSetUp& right) {
    if (this != &right) {
        memcpy(aircraft, right.aircraft, 5 * 2 * sizeof(int));
        memcpy(battleship, right.battleship, 4 * 2 * sizeof(int));
        memcpy(destroyer, right.destroyer, 3 * 2 * sizeof(int));
        memcpy(corvette, right.corvette, 2 * 2 * sizeof(int));
    }
    return *this;
}
//*************************************************************************
//Definition of function letterToRowNumber.This function is declared as a                        *
//friend by BShipSetUp class and it will determine the letter (A, B, C...J)
// value to integer y-axis value (0,1,2...9)           
//*************************************************************************
int letterToRowNumber(char letter)
{
    switch (letter)
    {
    case 'A':
        return 0;                       // return index 0
    case 'B':
        return 1;                       // return index 1                                               
    case 'C':
        return 2;                       // return index 2 
    case 'D':
        return 3;                       // return index 3 
    case 'E':
        return 4;                       // return index 4 
    case 'F':
        return 5;                       // return index 5 
    case 'G':
        return 6;                       // return index 6 
    case 'H':
        return 7;                       // return index 7 
    case 'I':
        return 8;                       // return index 8 
    case 'J':
        return 9;                       // return index 9 
    }
}
//*****************************************************************
//Definition of function conflictWithOtherShip                    *
//This check the ship position conflict with other ship or not    *
//*****************************************************************
bool BShipSetUp::conflictWithOtherShip(vector<vector<char>> playerMatrix,
    int row, int col, int shipLength, char shipOrientation) {
    if (shipOrientation == 'h') { // check the ship orientation
        // for horizontal orientation check the column till ship length
        for (int i = col; i < col + shipLength; i++)
        {    // check the character for position of the matrix, if it is 
            // not '*' that means it is conflict with other ship position
            if (playerMatrix[row][i] != '*') {
                return true;// and return true   
            }
        }
    } //end if
    else {
        // for horizontal orientation check the row till ship length
        for (int i = row; i < row + shipLength; i++)
        {
            if (playerMatrix[i][col] != '*') {
                return true;        // and return true 
            }
        }
    } //end else
    return false;
}

//*****************************************************************
//Definition of function setYourBattleShip                        *
//Set player ship position and return player ship position        *
//*****************************************************************
BShipSetUp BShipSetUp::setYourBattleShip(BShipSetUp b) {

    const int AIRCRAFT_LENGTH = 5;     // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;   // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;    // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;     // Unit length of the corvette
    const int POSITION_LENGTH = 2;     // Input length of a grid position
    char shipOrientiation;             // Take the input for ship orientation (h or v)                              
    string shipPosition = "";          // Take the input for ship starting position (a0, a2...j9 so on) 
    b.playerName = getPlayerName();     // Get the player name
    playerMatrix = getMatrixData();     // Get the matrix data
    BattleShip objBShip;               // Define a battleship object
    
    while (true) {  // Loop for setup the aircraft position    
        cout << "Setup your aircraft carrier location" << endl;
        cout << "Select your aircraft carrier orientation "
            "(h-horizontal) and (v-vertical) : " << endl;
        while (true) { // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;   // take the input of ship orientation 'h' or 'v'
            // compare the ship orientation input if it is 'v' or 'h' then fine
            if (tolower(shipOrientiation) == 'h'
                || tolower(shipOrientiation) == 'v') {
                cin.ignore();
                break;
            }
            else {// if input is not h or v then ask for input again
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n";
                cin.ignore();
                continue;
            } //end else
        } //end while-loop

        cout << "Enter the aircraft position without a space "
            "(example: a0, a1...): " << endl;
        while (true) {  // take a infinite loop for satisfying the valid input for air craft position
            getline(cin, shipPosition);  // get the ship position
            // position length should the 2 character length
            if (shipPosition.length() == POSITION_LENGTH) {
                // make the uppercase of the input position for comparing value
                // and allow for lower or upper case character
                for (auto& c : shipPosition) c = toupper(c);
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J')
                    && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break; // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid aircraft position without a space"
                        " (example: a0, a1...): \n"; // ask for valid input 
                    shipPosition.clear();
                    continue;
                }
            } //end if
            else {
                cout << "Enter a valid aircraft position without a"
                    " space (example: a0, a1...): \n"; // ask for valid input
                shipPosition.clear();
                continue;
            }


        }//end while-loop

        if (tolower(shipOrientiation) == 'h') { // check for horizontal setup
            // Get the start value of y-axis (0,1,2...9)
            //from the letter position (A,B,C....J)
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0';
            // not able to setup the aircraft horizontally from this position
            if (startPositionCol > AIRCRAFT_LENGTH) {
                cout << "You cannot place the aircraft in this position."
                    " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            } //end if
            else {
                int counter = 0;
                for (int i = startPositionCol;
                    i < startPositionCol + AIRCRAFT_LENGTH; i++) {
                    // set the player matrix with 'A' for indicating the aircraft location
                    playerMatrix[startPositionRow][i] = 'A';
                    // insert the ship position values in the structure variable
                    b.aircraft[counter][0] = startPositionRow;
                    b.aircraft[counter][1] = i;
                    counter++;  // increase the counter one
                }
                break;
            } //end else
        } //end if
        if (tolower(shipOrientiation) == 'v') { // check for the vertical setup
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0'; // make a character value to integer
            // not able to setup the aircraft vertically from this position
            if (startPositionRow > AIRCRAFT_LENGTH) {
                cout << "You cannot place the aircraft in this position."
                    " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            } //end if
            else {
                int counter = 0;
                for (int i = startPositionRow;
                    i < startPositionRow + AIRCRAFT_LENGTH; i++) {
                    // set the player matrix with 'A' for indicating the aircraft location
                    playerMatrix[i][startPositionCol] = 'A';
                    b.aircraft[counter][0] = i;// insert the ship position values in member variables
                    b.aircraft[counter][1] = startPositionCol;
                    counter++; // increase the counter one
                } //end for
                break;
            } //end else

        } //end if
    } //end while-loop

    objBShip.showPlayZone(playerMatrix); // redraw the player area with the position of battleship    
    shipOrientiation = '\0';     // reset the ship orientation
    shipPosition.clear();        // clear the shipPosition
    while (true) {               // loop for setup the battleship position    
        cout << "Setup your battleship carrier location" << endl;
        cout << "Select your battleship carrier orientation"
            " (h-horizontal) and (v-vertical) : " << endl;
        while (true) {    // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;  // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' ||
                tolower(shipOrientiation) == 'v') {
                cin.ignore();
                break;
            } //end if
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n";
                cin.ignore();
                continue;
            } //end else
        }
        cout << "Enter the battleship position without a space"
            " (example: a0, a1...): " << endl;
        while (true) {  // take a infinite loop for satisfying the valid input for battleship position
            getline(cin, shipPosition); // get the ship position
            // position length should the 2 character length
            if (shipPosition.length() == POSITION_LENGTH) {
                for (auto& c : shipPosition) c = toupper(c);
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J')
                    && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break; // if valid input then exit the infinite while loop
                } //end if
                else {
                    // ask for valid input again
                    cout << "Enter a valid battleship position without a"
                        " space (example: a0, a1...): " << endl;
                    shipPosition.clear();
                    continue;
                } //end else
            }
            else {
                cout << "Enter a valid battleship position without a space"
                    " (example: a0, a1...): \n";// ask for valid input again
                shipPosition.clear();
                continue;
            }

        } //end while-loop

        if (tolower(shipOrientiation) == 'h') {  // check for horizontal setup
        // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = true;
            if (startPositionCol + BATTLESHIP_LENGTH <= 10) // check the position withing correct range   
            {
                isConflict = conflictWithOtherShip(playerMatrix,
                    startPositionRow, startPositionCol, BATTLESHIP_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            }
            if (isConflict) // not able to setup the battleship horizontally from this position
            {
                cout << "You cannot place the battleship in this position."
                    "TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionCol;
                    i < startPositionCol + BATTLESHIP_LENGTH; i++)
                {
                    // set the player matrix with 'B' for indicating the battle location
                    playerMatrix[startPositionRow][i] = 'B';
                    // insert the ship position values in the structure variable
                    b.battleship[counter][0] = startPositionRow;
                    b.battleship[counter][1] = i;
                    counter++; // increase the counter one
                } //end for
                break;
            } //end else
        } //end if
        if (tolower(shipOrientiation) == 'v')   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0'; // make a character value to integer
            bool isConflict = true;
            if (startPositionRow + BATTLESHIP_LENGTH <= 10)// check the position withing correct range   
            {
                isConflict = conflictWithOtherShip(playerMatrix,
                    startPositionRow, startPositionCol, BATTLESHIP_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            }
            if (isConflict) // not able to setup the battleship vertically from this position
            {
                cout << "You cannot place the battleship in this position."
                    " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow
                    + BATTLESHIP_LENGTH; i++) {
                    // set the player matrix with 'B' for indicating the battle location
                    playerMatrix[i][startPositionCol] = 'B';
                    b.battleship[counter][0] = i;
                    b.battleship[counter][1] = startPositionCol;
                    counter++;   // increase the counter one
                } //end  for
                break;
            } //end else

        } //end if
    } //end while
    objBShip.showPlayZone(playerMatrix);  // redraw the player area with the position of destroyer    
    shipOrientiation = '\0';      // reset the ship orientation
    shipPosition.clear();   // clear the shipPosition
    while (true)   // loop for setup the battleship position    
    {
        cout << "Setup your destroyer carrier location" << endl;
        cout << "Select your destroyer carrier orientation (h-horizontal)"
            " and (v-vertical) : " << endl;

        while (true) { // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation; // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' ||
                tolower(shipOrientiation) == 'v') {
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n";
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the destroyer position without a space "
            "(example: a0, a1...): " << endl;
        while (true) { // take a infinite loop for satisfying the valid input for destroyer position
            getline(cin, shipPosition);   // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) {
                for (auto& c : shipPosition) c = toupper(c);
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J')
                    && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break; // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid destroyer position without a space"
                        " (example: a0, a1...): \n"; // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid destroyer position without a space"
                    " (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            } //endl else

        }

        if (tolower(shipOrientiation) == 'h') { // check for horizontal setup
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = true;
            if (startPositionCol + DESTROYER_LENGTH <= 10)
            {
                isConflict = conflictWithOtherShip(playerMatrix,
                    startPositionRow, startPositionCol, DESTROYER_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            }
            if (isConflict) { // not able to setup the battleship horizontally from this position
                cout << "You cannot place the battleship in this position."
                    " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            } //end if
            else
            {
                int counter = 0;
                for (int i = startPositionCol; i < startPositionCol
                    + DESTROYER_LENGTH; i++) {
                    // set the player matrix with 'D' for indicating the battle location
                    playerMatrix[startPositionRow][i] = 'D';
                    // insert the ship position values in the member variables
                    b.destroyer[counter][0] = startPositionRow;
                    b.destroyer[counter][1] = i;
                    counter++;  // increase the counter one
                }
                break;
            } //end else
        }
        if (tolower(shipOrientiation) == 'v') // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0';  // make a character value to integer
            bool isConflict = true;
            if (startPositionRow + DESTROYER_LENGTH <= 10)
            {
                isConflict = conflictWithOtherShip(playerMatrix,
                    startPositionRow, startPositionCol, DESTROYER_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            }
            if (isConflict) { // not able to setup the destroyer vertically from this position

                cout << "You cannot place the battleship in this position."
                    " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow
                    + DESTROYER_LENGTH; i++) {
                    // set the player matrix with 'D' for indicating the battle location
                    playerMatrix[i][startPositionCol] = 'D';
                    // insert the ship position values in the structure variable
                    b.destroyer[counter][0] = i;
                    b.destroyer[counter][1] = startPositionCol;
                    counter++;// increase the counter one
                }
                break;
            }

        }
    }

    objBShip.showPlayZone(playerMatrix); // redraw the player area with the position of CORVETTE    
    shipOrientiation = '\0';     // reset the ship orientation
    shipPosition.clear();   // clear the shipPosition
    while (true)         // loop for setup the battleship position    
    {
        cout << "Setup your corvette carrier location" << endl;
        cout << "Select your corvette carrier orientation "
            "(h-horizontal) and (v-vertical) : " << endl;
        while (true) { // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation; // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' ||
                tolower(shipOrientiation) == 'v') {
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' \n";
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the corvette position without a space "
            "(example: a0, a1...): " << endl;
        while (true) {  // take a infinite loop for satisfying the valid input for corvette position
            getline(cin, shipPosition);      // get the ship position
            // position length should the 2 character length
            if (shipPosition.length() == POSITION_LENGTH) {
                for (auto& c : shipPosition) c = toupper(c);
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J')
                    && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid corvette position without a space "
                        "(example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid corvette position without a space"
                    " (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }

        }

        if (tolower(shipOrientiation) == 'h')  // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = true;
            if (startPositionCol + CORVETTE_LENGTH <= 10)
            {
                isConflict = conflictWithOtherShip(playerMatrix,
                    startPositionRow, startPositionCol, CORVETTE_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            }
            if (isConflict) {  // not able to setup the battleship horizontally from this position
                cout << "You cannot place the corvette in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionCol; i < startPositionCol
                    + CORVETTE_LENGTH; i++) {
                    // set the player matrix with 'C' for indicating the battle location
                    playerMatrix[startPositionRow][i] = 'C';
                    // insert the ship position values in the member variable
                    b.corvette[counter][0] = startPositionRow;
                    b.corvette[counter][1] = i;
                    counter++; // increase the counter one
                }
                break;
            }
        }
        if (tolower(shipOrientiation) == 'v') { // check for the vertical setup
            int startPositionRow = letterToRowNumber(shipPosition[0]);
            int startPositionCol = shipPosition[1] - '0'; // make a character value to integer
            bool isConflict = true;
            if (startPositionRow + CORVETTE_LENGTH <= 10) {
                isConflict = conflictWithOtherShip(playerMatrix,
                    startPositionRow, startPositionCol, CORVETTE_LENGTH,
                    tolower(shipOrientiation)); // check the ship is conflict with other ship position
            }
            if (isConflict) { // not able to setup the destroyer vertically from this position
                cout << "You cannot place the battleship in this position."
                    " TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow +
                    CORVETTE_LENGTH; i++) {
                    // set the player matrix with 'C' for indicating the battle location
                    playerMatrix[i][startPositionCol] = 'C';
                    // insert the ship position values in the member variable
                    b.corvette[counter][0] = i;
                    b.corvette[counter][1] = startPositionCol;
                    counter++;  // increase the counter one
                }
                break;
            }

        }
    } //end while-loop
    objBShip.showPlayZone(playerMatrix); // redraw the player area with the position of destroyer    

    return b;
} //end of setYourBattleShip

//*****************************************************************
//Definition of function setComputerBattleShip                    *
//Set computer ship position and return ship position             *
//*****************************************************************
BShipSetUp BShipSetUp::setComputerBattleShip(BShipSetUp computerShipPosition) {
    const int AIRCRAFT_LENGTH = 5;      // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;    // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;    // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;     // Unit length of the corvette
    computerMatrix = getMatrixData();

    //setup aircraft
    int rowPosition = rand() % 2 + 2; // Randomly select a row position from 2-3  
    int colPosition = rand() % 2 + 2; // Randomly select a column position from 2-3
    int shipOrientation = rand() % 2; // Select a ship orientation value 0 or 1
    if (shipOrientation == 0) // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        for (int i = colPosition; i < colPosition + AIRCRAFT_LENGTH; i++) {
            // Set the computer matrix with 'A' for indicating the aircraft location
            computerMatrix[rowPosition][i] = 'A';
            // Insert the ship position values in the structure variable
            computerShipPosition.aircraft[counter][0] = rowPosition;
            computerShipPosition.aircraft[counter][1] = i;  // Insert the column position 
            counter++;             // Increase the counter one
        }
    }
    else { // Otherwise orientation is vertical  
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + AIRCRAFT_LENGTH; i++)
        {
            // Set the player matrix with 'A' for indicating the battle location
            computerMatrix[i][colPosition] = 'A';
            computerShipPosition.aircraft[counter][0] = i;
            computerShipPosition.aircraft[counter][1] = colPosition;
            counter++;
        }
    }

    //setup the battleship
    rowPosition = (rand() % 2) + 5; // Randomly select a row position from 5-6  
    colPosition = (rand() % 2) + 5; // Randomly select a column position from 5-6
    shipOrientation = (rand() % 2); // Select a ship orientation value 0 or 1
    if (shipOrientation == 0) { // If value is 0 then consider the orientation as horizontal;
        int counter = 0;
        for (int i = colPosition; i < colPosition + BATTLESHIP_LENGTH; i++) {
            // Set the computer matrix with 'B' for indicating the battleship location
            computerMatrix[rowPosition][i] = 'B';
            computerShipPosition.battleship[counter][0] = rowPosition;
            computerShipPosition.battleship[counter][1] = i; // Insert the column position 
            counter++;         // Increase the counter one
        }
    }
    else {  // Otherwise orientation is vertical
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + BATTLESHIP_LENGTH; i++)
        {
            computerMatrix[i][colPosition] = 'B';
            computerShipPosition.battleship[counter][0] = i;
            computerShipPosition.battleship[counter][1] = colPosition;
            counter++;
        }
    }

    //setup the corvette
    rowPosition = (rand() % 2) + 8;  // Randomly select a row position from 8-9  
    colPosition = (rand() % 3);     // Randomly select a column position from 0-2
    shipOrientation = (rand() % 2);
    if (shipOrientation == 0)  // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        for (int i = colPosition; i < colPosition + DESTROYER_LENGTH; i++)
        {
            computerMatrix[rowPosition][i] = 'D';
            computerShipPosition.destroyer[counter][0] = rowPosition;
            computerShipPosition.destroyer[counter][1] = i;  // Insert the column position 
            counter++;     // Increase the counter one
        }
    }
    else { // Otherwise orientation is vertical
        rowPosition = (rand() % 3); // Randomly select a row position from 0-2  
        colPosition = (rand() % 2) + 8; // Randomly select a column position from 8-9
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + DESTROYER_LENGTH; i++) {
            // Set the player matrix with 'D' for indicating the battle location
            computerMatrix[i][colPosition] = 'D';
            // Insert the ship position values in member variables
            computerShipPosition.destroyer[counter][0] = i;
            computerShipPosition.destroyer[counter][1] = colPosition;
            counter++; // Increase the counter one
        }
    }
    //setup the destroyer
    shipOrientation = (rand() % 2); // Randomly select ship orientation for destroyer 
    if (shipOrientation == 0) // If value is 0 then consider the orientation as horizontal;
    {
        rowPosition = (rand() % 2); // Randomly select a row position from 0-1  
        colPosition = (rand() % 7);  // Randomly select a column position from 0-6
        int counter = 0;
        for (int i = colPosition; i < colPosition + CORVETTE_LENGTH; i++) {
            // Set the computer matrix with 'C' for indicating the battleship location
            computerMatrix[rowPosition][i] = 'C';
            // Insert the ship position values in class members variable
            computerShipPosition.corvette[counter][0] = rowPosition;
            computerShipPosition.corvette[counter][1] = i;  // Insert the column position 
            counter++;          // Increase the counter one
        }
    }
    else { // Otherwise orientation is vertical
        rowPosition = (rand() % 5) + 2; // Randomly select a row position from 2-6  
        colPosition = (rand() % 2);  // Randomly select a column position from 0-1
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + CORVETTE_LENGTH; i++)
        {
            computerMatrix[i][colPosition] = 'C';
            computerShipPosition.corvette[counter][0] = i;
            computerShipPosition.corvette[counter][1] = colPosition;
            counter++;             // Increase the counter one
        }
    }
    return computerShipPosition;
}

//*******************************************************************
//Definition of function showPlayZone, member function of BShipSetUp                   
//This draw the computer and player play zone    
//*******************************************************************
void BShipSetUp::showPlayZone() {
     cout << "~~'*'=unexplore area ~~ 'o'=unsuccessful attack ~~ "
        "'@'=successful attack ~~\n";
    cout <<"------ PRESS 'S' (UPPER CASE) TO SAVE THE GAME ANY TIME --------\n";
    cout <<"................................................................\n";
    cout << " -       Computer Zone                        "
        "  Your Zone      -" << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -          "
        " - - - 0 1 2 3 4 5 6 7 8 9 -" << endl;
    for (int i = 0; i < ROWS; i++) {  //Nested loop draw the player and computer matrix                      
        cout << " | " << yCoord[i] << " | "; // Set the y-column 'A' to 'J'
        for (int j = 0; j < COLS; j++) {
            // Hide the computer ship position
            if (computerMatrix[i][j] >= 'A' && computerMatrix[i][j] <= 'D')
            {
                cout << "* ";   // Display the computer matrix
            }
            else {
                cout << computerMatrix[i][j] << " "; // Display the computer matrix
            }
        }
        cout << "|           | " << yCoord[i] << " | "; //set the y-column 'A' to 'J'
        for (int j = 0; j < COLS; j++)
            cout << playerMatrix[i][j] << " "; // Display the player matrix
        cout << "|" << endl;
    }

}

//*****************************************************************
//Definition of function startPlay. Use two BShipSetUp objects as
//@param which allow to input player and computer to 
//attack position each other. Return none
//*****************************************************************
void BShipSetUp::startPlay(BShipSetUp battleShipPlayer, BShipSetUp
    battleShipComputer) {
    const int POSITION_LENGTH = 2; // The input position string length always two,e.g, a0,b9..
    int rowPosition;               // row value
    int colPosition;               // column value
    string attackPosition;         // input string for attack
    bool isSuccessful;             // Successfully attack or not
    int trackWin;                  // The winner of the game
    fstream gInfo;                 // Declare a fstream object
    int attackCount = 0;           // A counter for count the number of attack
    DateTimeInfo <string> dt;      // Declare a DateTimeInfo class object
    char* winner = new char[2];    // Dynamically allocate character array
    
    if (!battleShipPlayer.getPlayerName().empty()) { // Check for openning a saved game
        playerName = battleShipPlayer.getPlayerName(); // set the player name
    }
    if (battleShipPlayer == battleShipComputer) { // Confirm the both player battle ships are in same size
        cout << "Play is continuing now! " << endl;
    }
    else {
        cout << "Miss configuration of player and computer battle ship";
    }
    dt.setDateOfPlay(currentDate()); // Hold the current date 
    dt.setStartTimePlay(currentTime()); // Hold the start time 

    cout << "~~ Now your turn to attack the computer ship position ~~" << endl;
    while (true) {
        while (true) { // Take a infinite loop for satisfying the valid input for attack position
            cout << "Choose a position for attacking the computer ships"
                " (example: a0, a1...'S'(save game) ): " << endl;
            getline(cin, attackPosition);                     // Get the ship position
            if (attackPosition == "S") break;
            // position length should the 2 character length
            if (attackPosition.length() == POSITION_LENGTH) {
                // make the uppercase of the input position for comparing value 
                //and allow for lower or upper case character
                for (auto& c : attackPosition) c = toupper(c);
                if ((attackPosition[0] >= 'A' && attackPosition[0] <= 'J')
                    && (attackPosition[1] >= '0' && attackPosition[1] <= '9')) { // check for valid input
                    // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
                    rowPosition = letterToRowNumber(attackPosition[0]);
                    colPosition = attackPosition[1] - '0';
                    attackCount += 1; // Count the attack
                    isSuccessful = checkSuccessful(battleShipComputer, 'p',
                        rowPosition, colPosition);
                    // If successfully hit then player will get another change for attack
                    if (isSuccessful) {
                        //Display the ship status of the game, and track availability
                        trackWin = displayShipStatus(battleShipPlayer,
                            battleShipComputer);
                        showPlayZone();// Draw the play zone
                        cout << " You attack successfully !!! " << endl;
                        attackPosition.clear();
                        if (trackWin == 0) break; // Player won the game; do not need continue
                        continue;
                    } //end if
                    else {
                        trackWin = displayShipStatus(battleShipPlayer,
                            battleShipComputer);
                        showPlayZone();// Draw the play zone
                        cout << "You miss the hit. Now computer's turn! \n";
                        break;// End the player attack, now computer will attack 
                    } //end else
                } //end if
                else {
                    cout << "--Enter a valid aircraft position without a space"
                        " (example: a0, a1...'S'(save game) )----\n";// ask for valid input again
                    attackPosition.clear();
                    continue;
                } //end else
            }
            else {
                cout << "----Enter a valid aircraft position without a space"
                    " (example: a0, a1...'S'(save game) )----" << endl;// ask for valid input again
                attackPosition.clear();
                continue;
            }//end else
        } //end while-loop
        if (attackPosition == "S")break;
        if (trackWin == 0) { // The player won
            cout << "Congratulation!!! ~~~" << playerName
                << "~~~ You won this game!!!" << endl;
            winner[0] = 'p';     // Hold player win the game
            winner[1] = '\0';
            break;
        } // end if
        while (true) { // Take a infinite loop for satisfying the valid input for attack position
            cout << "Computer is now attacking your ships...: " << endl;
            rowPosition = rand() % 10; // randomly select a row position from 0-9 
            colPosition = rand() % 10; // randomly select a column position from 0-9 
            // Check if it is successfully hit or not 
            isSuccessful = checkSuccessful(battleShipPlayer, 'c', rowPosition, colPosition);
            if (isSuccessful) {  // If successfully hit then player will get another change for attack
                trackWin = displayShipStatus(battleShipPlayer, battleShipComputer);
                showPlayZone();   // Draw the play zone
                cout << "Computer attack the position: " << yCoord[rowPosition]
                    << colPosition << endl;
                cout << "Computer attack your ship successfully !!! " << endl;
                if (trackWin == 1) break; // Computer won the game; do not need continue
                continue;
            }//end if
            else {
                trackWin = displayShipStatus(battleShipPlayer, battleShipComputer);
                showPlayZone(); // Draw the play zone
                cout << "Computer attack the position: " << yCoord[rowPosition]
                    << colPosition << endl;
                cout << "Computer miss the hit. Now your turn! " << endl;
                break;  // End the computer attack and player will attack now to player battle ship
            } //end else
        }//end while-loop
        if (trackWin == 1) { // The computer won
            cout << "Congratulation!!! ~~~ Computer ~~~ won this game!!!\n";
            winner[0] = 'c';                 // Hold the winner 
            winner[1] = '\0';

            break;
        }//end if
    } //End while-loop
    dt.setEndTimeOfPlay(currentTime());  //Hold the end time of play
    if (attackPosition == "S") {         // If save the game
        winner[0] = 's';               // No one win the game, and is saved game
        winner[1] = '\0';

        GameSummary objGSummary(attackCount, winner, &dt);   
        int rVal = objGSummary.writeSummary(playerName, gInfo);   // Write a summary of game
        // save the game
        saveGame(battleShipPlayer, battleShipComputer, playerMatrix, computerMatrix);
    } //end if
    else {
        GameSummary objGSummary(attackCount, winner, &dt); 
        int rVal = objGSummary.writeSummary(playerName, gInfo); //Play is ended, write a summary
    }

} //End of startPlay member function

//*****************************************************************
//Definition of function checkSuccessful                          *
//This function check the attack is successful or not and         *
//Update the ship position structure                              *
//*****************************************************************
bool BShipSetUp::checkSuccessful(BShipSetUp& bShipInfo,
    char sourceData, int row, int col) {
    const int AIRCRAFT_LENGTH = 5;    // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;  // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;   // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;   // Unit length of the corvette
    bool isFound = false;
    for (int i = 0; i < AIRCRAFT_LENGTH; i++) { // Check the air craft position
        if (bShipInfo.aircraft[i][0] != -1)     // If the position not hit yet
        {
            //hit successful
            if (bShipInfo.aircraft[i][0] == row && bShipInfo.aircraft[i][1] == col)
            {
                // Track this position destroy
                bShipInfo.aircraft[i][0] = -1;
                if (sourceData == 'c') {
                    // Set the matrix position '@' if hit successfully
                    playerMatrix[row][col] = '@';
                }
                else
                {
                    // Set the matrix position '@' if hit successfully
                    computerMatrix[row][col] = '@';
                }
                isFound = true;  // The value is found already
                return isFound;
            }
        }
    }

    for (int i = 0; i < BATTLESHIP_LENGTH; i++) // Check the battle ship position
    {
        if (bShipInfo.battleship[i][0] != -1)   // If the position not hit yet
        {
            if (bShipInfo.battleship[i][0] == row &&
                bShipInfo.battleship[i][1] == col) { //hit successful

                bShipInfo.battleship[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                {
                    playerMatrix[row][col] = '@'; // Set the matrix position '@' if hit successfully
                }
                else
                {
                    computerMatrix[row][col] = '@'; // Set the matrix position '@' if hit successfully
                }
                isFound = true;  // The value is found already
                return isFound;
            }
        }
    }

    for (int i = 0; i < DESTROYER_LENGTH; i++)     // Check the Destroyer position
    {
        if (bShipInfo.destroyer[i][0] != -1)   // If position not hit yet 
        {
            if (bShipInfo.destroyer[i][0] == row && bShipInfo.destroyer[i][1] == col) //hit successful
            {
                bShipInfo.destroyer[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                {
                    playerMatrix[row][col] = '@';  // Set the matrix position '@' if hit successfully
                }
                else
                {
                    computerMatrix[row][col] = '@'; // Set the matrix position '@' if hit successfully
                }
                isFound = true;    // The value is found already
                return isFound;
            }
        }
    }

    for (int i = 0; i < CORVETTE_LENGTH; i++)     // Check the corvette position
    {
        if (bShipInfo.corvette[i][0] != -1)   // If position not hit yet 
        {
            if (bShipInfo.corvette[i][0] == row && bShipInfo.corvette[i][1] == col) //hit successful
            {
                bShipInfo.corvette[i][0] = -1;   // Track this position destroy
                if (sourceData == 'c')
                {
                    playerMatrix[row][col] = '@'; // Set the matrix position '@' if hit successfully
                }
                else {
                    computerMatrix[row][col] = '@';  // Set the matrix position '@' if hit successfully
                }
                isFound = true; // The value is found already
                return isFound;
            }
        }
    }
    if (sourceData == 'c')
    {
        playerMatrix[row][col] = 'o'; // Set the matrix position '@' if hit successfully
    }
    else
    {
        computerMatrix[row][col] = 'o'; // Set the matrix position '@' if hit successfully
    }
    return isFound;
}
//*****************************************************************
//Definition of function displayShipStatus                    
//Check the ship status using structure reference
//Draw the ship status     
//Return the integer indicating the game is over or not
//*****************************************************************
int BShipSetUp::displayShipStatus(BShipSetUp player, BShipSetUp computer)
{
    system("cls");
    const int AIRCRAFT_LENGTH = 5;           // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;         // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;          // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;           // Unit length of the corvette
    int airCarftComputer = 0;                // Counter for air craft
    int battelShipComputer = 0;              // Counter for battleship
    int destroyerComputer = 0;               // Counter for destroyer
    int corvetteComputer = 0;                // Counter for corvette
    int airCarftPlayer = 0;                  // Counter for air craft
    int battelShipPlayer = 0;                // Counter for battleship
    int destroyerPlayer = 0;                 // Counter for destroyer
    int corvettePlayer = 0;                  // Counter for corvette

    bool isFound = false;

    //Count aircraft
    for (int i = 0; i < AIRCRAFT_LENGTH; i++)   // Check the air craft position
    {
        if (computer.aircraft[i][0] != -1)      // If the position not hit yet
        {
            airCarftComputer += 1;              // Count the computer air craft 
        }
        if (player.aircraft[i][0] != -1)
        {
            airCarftPlayer += 1;                // Count the player air craft
        }
    }
    //Count battleship
    for (int i = 0; i < BATTLESHIP_LENGTH; i++)  // Check the battle ship position
    {
        if (computer.battleship[i][0] != -1)     // If the position not hit yet
        {
            battelShipComputer += 1;             // Count the computer battle ship 
        }
        if (player.battleship[i][0] != -1)
        {
            battelShipPlayer += 1;              // Count the player battle ship
        }
    }
    //Count destroyer
    for (int i = 0; i < DESTROYER_LENGTH; i++) // Check the Destroyer position
    {
        if (computer.destroyer[i][0] != -1)    // If the position not hit yet
        {
            destroyerComputer += 1;           // Count the computer destroyer ship 
        }
        if (player.destroyer[i][0] != -1)
        {
            destroyerPlayer += 1;           // Count the player destroyer ship
        }
    }
    //Count corvette
    for (int i = 0; i < CORVETTE_LENGTH; i++)  // Check the corvette position
    {
        if (computer.corvette[i][0] != -1)     // If the position not hit yet
        {
            corvetteComputer += 1;             // Count the computer corvette ship 
        }
        if (player.corvette[i][0] != -1)
        {
            corvettePlayer += 1;              // Count the player corvette ship
        }
    }
    //Display the ship status
    cout << "........................................................."
        "..........." << endl;
    cout << " -      Computer Ships Status                 Your Ships Status-\n";
    cout << "........................................................"
        "............" << endl;
    cout << "----Aircraft: " << airCarftComputer << " units                "
        " | ----Aircraft: " << airCarftPlayer << " units" << endl;
    cout << "----Battleship: " << battelShipComputer << " units              "
        " | ----Battleship: " << battelShipPlayer << " units" << endl;
    cout << "----Destroyer: " << destroyerComputer << " units                "
        "| ----Destroyer: " << destroyerPlayer << " units" << endl;
    cout << "----Corvette: " << corvetteComputer << " units                "
        " | ----Corvette: " << corvettePlayer << " units" << endl;
    cout << ".............................................................."
        "......." << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    cout << " -                     ~~~Welcome to BattleShip~~~               -\n";
    if (player.getPlayerName() == "") {  // Start with player name using new game
        cout << " -                     ~~~Player Name: " << playerName << endl;
    }
    else { //Start with player name using a saved game
        cout << " -                     ~~~Player Name: "
            << player.getPlayerName() << endl;
    }
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    // Check all computer ships were hit successfully
    if (airCarftComputer == 0 && battelShipComputer == 0 &&
        destroyerComputer == 0 && corvetteComputer == 0) {
        return 0;   // Computer loss and player win
    }
    // Check all player ships were hit successfully
    else if (airCarftPlayer == 0 && battelShipPlayer == 0 &&
        destroyerPlayer == 0 && corvettePlayer == 0)
    {
        return 1;   // player loss and computer win
    }
    else
    {
        return 2; // Continue play
    }
}

//**************************************************************************
//Definition of function currentDate                    
//Input->: None, This function convert the current date as MM-DD-YYYY format
//Output->: Return string sTime
//**************************************************************************
string BShipSetUp::currentDate() {
    string sTime;
    time_t curr_time;
    curr_time = time(NULL);
    tm* tm_local = localtime(&curr_time);
    sTime = to_string(tm_local->tm_mon + 1) + "/" + to_string(tm_local->tm_mday)
        + "/" + to_string(tm_local->tm_year % 100);
    return sTime;
} // End currentDate function

//*****************************************************************
//Definition of function currentTime                    
//Input: None, This function convert the current time as HH:mm:ss format
//Output: Return string sTime 
//*****************************************************************
string BShipSetUp::currentTime() {
    string sTime;
    time_t curr_time;
    curr_time = time(NULL);
    tm* tm_local = localtime(&curr_time);
    sTime = to_string(tm_local->tm_hour) + ":" + to_string(tm_local->tm_min) +
        ":" + to_string(tm_local->tm_sec);
    return sTime;

} //End currentTime function

//*****************************************************************
//Definition of function saveGame. Use structure variables, double 
//pointer as parameters, and write the game in binary file.
//Return none
//*****************************************************************
void BShipSetUp::saveGame(BShipSetUp player, BShipSetUp computer,
    vector<vector<char>> playerMatrix, vector<vector<char>> pcMatrix) {
    //setPMatrix(playerMatrix);
    //setCMatrix(computerMatrix);
    char pMat[10][10];
    char cMat[10][10];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pMat[i][j] = playerMatrix[i][j];
            cMat[i][j] = pcMatrix[i][j];
        }//end for-loop
    } //end for-loop

    fstream pShip, pMatrix, cShip, cMatrix; //Declare fstream objects to write out
    //open player ship file
    pShip.open("playerShip.txt", ios::out);
    for (int i = 0; i < 5; i++)             
        for (int j = 0; j < 2; j++)
            pShip << player.aircraft[i][j] << ";"; // Store aircraft position from save game
    pShip << endl;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            pShip << player.battleship[i][j] << ";"; // Store battleship position from the save game
    pShip << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            pShip << player.destroyer[i][j] << ";";// Store destroyer postion from the save game
    pShip << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            pShip << player.corvette[i][j] << ";"; // Store corvette position from the save game
    pShip << endl;
    // Open the computer ship file
    cShip.open("computerShip.txt", ios::out);
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 2; j++)
            cShip << computer.aircraft[i][j] << ";";
    cShip << endl;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
            cShip << computer.battleship[i][j] << ";";
    cShip << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cShip << computer.destroyer[i][j] << ";";
    cShip << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cShip << computer.corvette[i][j] << ";";

    pMatrix.open("playerMatrix.dat", ios::out | ios::binary);
    cMatrix.open("pcMatrix.dat", ios::out | ios::binary);
    pMatrix.write(reinterpret_cast<char*>(&pMat), (ROWS * COLS) * sizeof(char));
    cMatrix.write(reinterpret_cast<char*>(&cMat), (ROWS * COLS) * sizeof(char));
    //close the file
    pShip.close();
    cShip.close();
    pMatrix.close();
    cMatrix.close();
} //End saveGame function
//***************************************************************
//Definition of function openSummaryFile. Use fstream object 
//and string parameters.This is friend function of BShipSetUp class
//check file open in or not. Return Boolean type status
//***************************************************************
bool openSummaryFile(fstream& infile, string fileName) {
    infile.open(fileName, ios::in);
    if (infile.fail()) return false;
    else              return true;

} //End openSummaryFile function

//******************************************************************************
//Definition of function readContent. This is a friend function of BShipSetUp 
//Input->:fstream object as @param, function find the last player name from file
//Output->:Return token as player name
//******************************************************************************
string readContent(fstream& infile) {
    string line;            //To read line from file
    string delimiter = ";"; //To read line until this delimiter
    string token;           //To hold player name
    infile >> line;         //Read line from file
    //Find name and store to the token
    token = line.substr(0, line.find(delimiter));
    return token;   //Return the player name
    infile.close(); //Close the file
} // End readContent function
//*****************************************************************
//Definition of function openGame. 
//Input->:None, and read the game from binary file.
//Output->:Return Boolean status
//*****************************************************************
bool BShipSetUp::openGame() {
    char plMatrix[10][10]; //To read in from binary file to 2d array
    char coMatrix[10][10]; //To read in from binary file to 2d array
    playerMatrix.resize(10, std::vector<char>(10, '*'));    // allocate memory for the vector
    computerMatrix.resize(10, std::vector<char>(10, '*'));    // allocate memory for the vector

    BShipSetUp objPlayer;   //Declare player object
    BShipSetUp objComputer; // Declare computer object
    fstream pMatrix, cMatrix, pShip, cShip; //Declare fstream object to read in
    string playerName; //Name of player

    //open multiple binary files to read 
    pShip.open("playerShip.txt", ios::in);
    cShip.open("computerShip.txt", ios::in);
    pMatrix.open("playerMatrix.dat", ios::in | ios::binary);
    cMatrix.open("pcMatrix.dat", ios::in | ios::binary);
    if (pMatrix.fail() || cMatrix.fail() || pShip.fail() || cShip.fail())
        return false;
    string line;    // Store file content at the line
    int lineCount = 1;  // count the line number
    while (getline(pShip, line))
    {
        // Fill the battle ship status
        if (lineCount == 1)
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 2; j++) {
                    objPlayer.aircraft[i][j] = tokens[index];
                    index++;
                }
            }
        }
        else if (lineCount == 2)
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    objPlayer.battleship[i][j] = tokens[index];
                    index++;
                }
            }
        }
        else if (lineCount == 3)
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    objPlayer.destroyer[i][j] = tokens[index];
                    index++;
                }
            }
        }
        else
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    objPlayer.corvette[i][j] = tokens[index];
                    index++;
                }
            }
        }
        lineCount++;
    }
    lineCount = 1;
    while (getline(cShip, line))
    {
        if (lineCount == 1)
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 2; j++) {
                    objComputer.aircraft[i][j] = tokens[index];
                    index++;
                }
            }
        }
        else if (lineCount == 2)
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    objComputer.battleship[i][j] = tokens[index];
                    index++;
                }
            }
        }
        else if (lineCount == 3)
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 2; j++) {
                    objComputer.destroyer[i][j] = tokens[index];
                    index++;
                }
            }
        }
        else
        {
            int index = 0;
            vector<int> tokens = split(line, ';');
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    objComputer.corvette[i][j] = tokens[index];
                    index++;
                }
            }
        }
        lineCount++;
    }

    //Read in from binary files 
    pMatrix.read(reinterpret_cast<char*>(&plMatrix), (ROWS * COLS) * sizeof(char));
    cMatrix.read(reinterpret_cast<char*>(&coMatrix), (ROWS * COLS) * sizeof(char));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            playerMatrix[i][j] = plMatrix[i][j];
            computerMatrix[i][j] = coMatrix[i][j];
        }
    }
    //close the files
    pMatrix.close();
    cShip.close();
    pMatrix.close();
    cMatrix.close();
    // Send file fstream object as a function reference parameter
    bool fOpen = openSummaryFile(pMatrix, "gameSummary.txt");
    if (fOpen) {
        string pName = readContent(pMatrix);
        objPlayer.setName(pName);
        objComputer.setName(pName);
        //Display the ship status
        int retInit = displayShipStatus(objPlayer, objComputer);
        //Display the player information and game head
        cin.ignore();
        //Display the player and computer matrix
        showPlayZone();
        // Start the play allow player and computer to play
        startPlay(objPlayer, objComputer);
    } //end if
    else {
        cout << "Save game is not available now!";
    } //end else
    return true;
} //End openGame function

//*********************************************************************
//Definition of function openSummaryFile. This function Split a line 
//Use a reference string and a char as parameters.Return vector object
//*********************************************************************
vector<int> BShipSetUp::split(const string &str, char sep) {
    vector<int> tokens;
    int i;
    stringstream ss(str);
    while (ss >> i) {
        tokens.push_back(i);
        if (ss.peek() == sep) {
            ss.ignore();
        }
    }

    return tokens;
}