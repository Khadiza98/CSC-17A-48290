/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 17, 2022, 9:33 am
 * Purpose:Game of BattleShip
 *          Fill 2-D pointer with '*' character
 *          Apply the Rules of Battleship
 *          Set up player battleship
 *          Set up computer battleship
 *          Draw the both matrix and playing zone
 *          Start the play, and allow the user input and computer randomly selection input
 */

 //System Level Libraries
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
#include <ctime> //set for time()
#include <string>
using namespace std;//Standard Name-space under which System Libraries reside

//Global Constants
const int ROWS = 10;                                          // Constant rows for 10x10 matrix
const int COLS = 10;                                          // Constant column for 10x10 matrix
//Structure declaration
struct BattleShip {                                           // Declare a structure for different types battle ship 
    int aircraft[5][2];                                       // Aircraft length is 5 for tracking its coordinate values (row,col)
    int battleship[4][2];                                     // Battleship length is 4 for tracking its coordinate values (row,col)
    int destroyer[3][2];                                      // Destroyer length is 3 for tracking its coordinate values (row,col)
    int corvette[2][2];                                       // Corvette length is 2 for tracking its coordinate values (row,col)     
};
enum YCoord { A, B, C, D, E, F, G, H, I, J };                 // Take a enum type for calculating the y coordinate position
//Function Prototypes
void gameRules(); //Display the game rules
void gameHead(string); //Display player name
char** getMatrixData(int, int); // Fill the computer or player matrix grid (10x10) with '*' character
int letterToRowNumber(char); //Determine the letter (A,...J) value to integer y-axis value (0,1,2...9) using enum identifier 
void drawPlayerArea(const char* const*, int, int); //Display player matrix
BattleShip setYourBattleShip(char**, string); //Set player ship position and return structure
BattleShip setComputerBattleShip(char**); //set computer ship position
bool conflictWithOtherShip(char**, int, int, int, char); //Check the ship position conflict with other ship or not
void showPlayZone(char**, char**); // Draw the computer and player zone
void startPlay(char**, char**, BattleShip*); // Allow the player and computer for attack the ships 
bool checkSuccessful(char**, BattleShip*, int, int);  // Check where the attack is successful or not
void destroy(char**, int, int); //De-allocate memory    

//Execution begins here!
int main() {
    //random seed here
    srand(static_cast<unsigned int>(time(0)));
    //declare variables
    char gameRule;                                              // Take input for checking the start play or game rules
    const int NUM_PLAYERS = 2;                                  // Number of player
    const int NAME_SIZE = 100;                                  // Set the maximum length of the name
    char playerName[NAME_SIZE];                                 // Declare the input array to take player name
    BattleShip bsPlayer[NUM_PLAYERS];                           // Array of structure 
    char** pcMatrix;                                            // Pointer to the number
    char** playerMatrix;                                        // Point to the number

    // Fill computer matrix grid (10x10) with '*' character
    pcMatrix = getMatrixData(ROWS, COLS);
    // Fill the player matrix grid (10x10) with '*' character
    playerMatrix = getMatrixData(ROWS, COLS);

    //Output the game statistics to the screen
    cout << "\t\t (1) Game Rules " << endl;
    cout << "\t\t ( ) Play Battleship Now " << endl;
    cout << "\t\t Press 1 for game rules or Press any key for play....." << endl;
    cin >> gameRule;                                            // Ask for input to see the rules or continue to game

    if (gameRule == '1') {                                      // If input is one then player can review the game rules
        // call the function to view the games rules
        gameRules();
    }
    cin.ignore();                                               //To ignore one or more characters from the input buffer
    cout << "Please enter your name" << endl;                   //Ask user to enter name
    cin.getline(playerName, NAME_SIZE);                         // Take the player name
    //Display player information and game head
    gameHead(playerName);                                       
    //Display player matrix
    drawPlayerArea(playerMatrix, ROWS, COLS);
    //Set player ship position and return structure
    bsPlayer[0] = setYourBattleShip(playerMatrix, playerName);
    //Set computer ship position and return structure
    bsPlayer[1] = setComputerBattleShip(pcMatrix);
    //Display the player information and game head
    gameHead(playerName);
    //Display the player and computer matrix
    showPlayZone(playerMatrix, pcMatrix);
    startPlay(playerMatrix, pcMatrix, bsPlayer);

    //De-allocate memory
    destroy(pcMatrix, ROWS, COLS);
    destroy(playerMatrix, ROWS, COLS);
    //Exit the program
    return 0;
}

//*****************************************************************
//Definition of function gameRules                                *
//Display the game rules                                          *
//*****************************************************************
void gameRules()
{
    char c;
    system("cls"); //clear the screen
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << " - - - - -                     ~~~Welcome to BattleShip Game~~~               - - - - - -" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Battleship game information/rules~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

    cout << "1. Total four battleships for each player, the winner is who destroy other battleships first" << endl;
    cout << "2. The battlefield is 10x10 grid where you place all four ships" << endl;
    cout << "3. You can place your ships position using coordinate values (e.g., A0, B1, g5) where 'A' or 'a' is the row number and 1,2..10 is the column number " << endl;
    cout << "4. Also, you can place the ship orientation, i.e horizontal or vertical. For horizontal orientation, type 'h' or 'H', and type 'v' or 'V' for vertical option" << endl;
    cout << "5. You total four battle ships: Aircraft Carrier (5 units long), Battleship (4 units long), Destroyer (3 units long) and Corvette (2 units long)" << endl;
    cout << "6. After placing your ship position; you are ready to play. To attack the opponent, enter a position value such as A1 or a1, b9, j5 (without spacing) and so on,  " << endl;
    cout << "7. If your attack is successful then it is denoted by '@' and you will continue your turn" << endl;
    cout << "8. If your attack is missed then it is denoted by 'o' and your turn will be end" << endl;
    cout << "Press any key to continue game... ... ...." << endl;
    system("pause"); //wait for the press any key

}
//*****************************************************************
//Definition of function gameHead                                 *
//Display the player name                                         *
//*****************************************************************
void gameHead(string playerName) {

    system("cls");
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -                     ~~~Welcome to BattleShip~~~               -" << endl;
    cout << " -                     ~~~Player Name: " << playerName << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

//*****************************************************************
//Definition of function getMatrixData                            *
//fill the computer or player matrix grid (10x10) with '*' char   *
//Return the 2-D array pointer.                                   *
//*****************************************************************
char** getMatrixData(int rows, int cols) {
    int i, j; //Loop counter variable
    char** arrMatrix; //Pointer to the array
    arrMatrix = new char* [rows]; //Allocating the row space in heap dynamically
    for (i = 0; i < rows; i++) {
        arrMatrix[i] = new char[cols];  //Allocating the column space in heap dynamically
    }
    //read into the array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arrMatrix[i][j] = '*';      //Set the '*' character for the matrix
        }
    }
    return arrMatrix; //Return pointer to the array
}
//*****************************************************************
//Definition of function drawPlayerArea                           *
//Display player matrix                                           *
//*****************************************************************
void drawPlayerArea(const char* const* matrixData, const int rows, const int cols) {
    system("cls");
    char yCoord[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0' };     // declare a character array for maintain y-coordinate as a character
    cout << "           Your Area                           " << endl;              // write a text head for computer zone
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -            " << endl;                     // display the x-coordinate value
    for (int i = 0; i < rows; i++) {                                                // loop to draw the 2-D matrix
        cout << " | " << yCoord[i] << " | ";
        for (int j = 0; j < cols; j++) {
            cout << matrixData[i][j] << " ";
        }
        cout << "|" << endl;
    }
}


//*****************************************************************
//Definition of function setYourBattleShip                        *
//Set player ship position and return structure                   *
//*****************************************************************
BattleShip setYourBattleShip(char** playerMatrix, string playerName) {

    const int AIRCRAFT_LENGTH = 5;                      // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;                    // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;                     // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;                      // Unit length of the corvette
    const int POSITION_LENGTH = 2;                      // Input length of a grid position
    char shipOrientiation;                              // Take the input for ship orientation (h or v)                              
    string shipPosition = "";                           // Take the input for ship starting position (a0, a2...j9 so on) 

    BattleShip playerShipPosition;                 // Declare a battleship structure variable to store player ship position 
    while (true)                                        // Loop for setup the aircraft position    
    {
        cout << "Setup your aircraft carrier location" << endl;
        cout << "Select your aircraft carrier orientation (h-horizontal) and (v-vertical) : " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;                        // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' or tolower(shipOrientiation) == 'v') {    // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' " << endl;     // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the aircraft position without a space (example: a0, a1...): " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for air craft position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid aircraft position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid aircraft position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }
        }

        if (tolower(shipOrientiation) == 'h')                                     // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            if (startPositionCol > AIRCRAFT_LENGTH)                                // not able to setup the aircraft horizontally from this position
            {
                cout << "You cannot place the aircraft in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionCol; i < startPositionCol + AIRCRAFT_LENGTH; i++)
                {
                    playerMatrix[startPositionRow][i] = 'A';                          // set the player matrix with 'A' for indicating the aircraft location
                    playerShipPosition.aircraft[counter][0] = startPositionRow;                             // insert the ship position values in the structure variable
                    playerShipPosition.aircraft[counter][1] = i;
                    counter++;                                                      // increase the counter one
                }
                break;
            }
        }
        if (tolower(shipOrientiation) == 'v')                                   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';                         // make a character value to integer

            if (startPositionRow > AIRCRAFT_LENGTH)                                // not able to setup the aircraft vertically from this position
            {
                cout << "You cannot place the aircraft in this position. TRY AGAIN!" << endl;
                //cin.ignore();
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow + AIRCRAFT_LENGTH; i++)
                {
                    playerMatrix[i][startPositionCol] = 'A';                          // set the player matrix with 'A' for indicationg the aircraft location
                    playerShipPosition.aircraft[counter][0] = i;                                    // insert the ship position values in the structure variable
                    playerShipPosition.aircraft[counter][1] = startPositionCol;
                    counter++;                                                      // increase the counter one
                }
                break;
            }

        }
    }

    drawPlayerArea(playerMatrix, ROWS, COLS);            // redraw the player area with the position of battleship    
    shipOrientiation = '\0';                            // reset the ship orientation
    shipPosition.clear();                               // clear the shipPosition
    while (true)                                        // loop for setup the battleship position    
    {
        cout << "Setup your battleship carrier location" << endl;
        cout << "Select your battleship carrier orientation (h-horizontal) and (v-vertical) : " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;                        // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' or tolower(shipOrientiation) == 'v') {    // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' " << endl;     // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the battleship position without a space (example: a0, a1...): " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for battleship position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid battleship position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid battleship position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }
            
        }

        if (tolower(shipOrientiation) == 'h')                               // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = conflictWithOtherShip(playerMatrix, startPositionRow, startPositionCol, BATTLESHIP_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionCol > BATTLESHIP_LENGTH + 2) || isConflict)                          // not able to setup the battleship horizontally from this position
            {
                cout << "You cannot place the battleship in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionCol; i < startPositionCol + BATTLESHIP_LENGTH; i++)
                {
                    playerMatrix[startPositionRow][i] = 'B';                          // set the player matrix with 'B' for indicating the battle location
                    playerShipPosition.battleship[counter][0] = startPositionRow;                             // insert the ship position values in the structure variable
                    playerShipPosition.battleship[counter][1] = i;
                    counter++;                                                      // increase the counter one
                }
                break;
            }
        }
        if (tolower(shipOrientiation) == 'v')                                   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';                         // make a character value to integer
            bool isConflict = conflictWithOtherShip(playerMatrix, startPositionRow, startPositionCol, BATTLESHIP_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionRow > BATTLESHIP_LENGTH + 2) || isConflict)                            // not able to setup the battleship vertically from this position

            {
                cout << "You cannot place the battleship in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow + BATTLESHIP_LENGTH; i++)
                {
                    playerMatrix[i][startPositionCol] = 'B';                       // set the player matrix with 'B' for indicationg the battle location
                    playerShipPosition.battleship[counter][0] = i;                                    // insert the ship position values in the structure variable
                    playerShipPosition.battleship[counter][1] = startPositionCol;
                    counter++;                                                      // increase the counter one
                }
                break;
            }

        }
    }
    drawPlayerArea(playerMatrix, ROWS, COLS);           // Redraw the player area with the position of destroyer    
    shipOrientiation = '\0';                            // Reset the shiporientation
    shipPosition.clear();                               // Clear the shipPosition
    while (true)                                        // Loop for setup the battleship position    
    {
        cout << "Setup your destroyer carrier location" << endl;
        cout << "Select your destroyer carrier orientation (h-horizontal) and (v-vertical) : " << endl;
        while (true) {                                      // Take a infinite loop for satifying the valid input for ship orientation
            cin >> shipOrientiation;                        // Take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' or tolower(shipOrientiation) == 'v') {    // Compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' " << endl;     // If input is not h or v then ask for input again
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the destroyer position without a space (example: a0, a1...): " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for destroyer position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid destroyer position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid destroyer position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }
            
        }

        if (tolower(shipOrientiation) == 'h')                               // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = conflictWithOtherShip(playerMatrix, startPositionRow, startPositionCol, DESTROYER_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionCol > DESTROYER_LENGTH + 4) || isConflict)                          // not able to setup the battleship horizontally from this position
            {
                cout << "You cannot place the battleship in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionCol; i < startPositionCol + DESTROYER_LENGTH; i++)
                {
                    playerMatrix[startPositionRow][i] = 'D';                          // set the player matrix with 'D' for indicating the battle location
                    playerShipPosition.destroyer[counter][0] = startPositionRow;                             // insert the ship position values in the structure variable
                    playerShipPosition.destroyer[counter][1] = i;
                    counter++;                                                      // increase the counter one
                }
                break;
            }
        }
        if (tolower(shipOrientiation) == 'v')                                   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';                         // make a character value to integer
            bool isConflict = conflictWithOtherShip(playerMatrix, startPositionRow, startPositionCol, DESTROYER_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionRow > DESTROYER_LENGTH + 4) || isConflict)                            // not able to setup the destroyer vertically from this position

            {
                cout << "You cannot place the battleship in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow + DESTROYER_LENGTH; i++)
                {
                    playerMatrix[i][startPositionCol] = 'D';                       // set the player matrix with 'D' for indicationg the battle location
                    playerShipPosition.destroyer[counter][0] = i;                                    // insert the ship position values in the structure variable
                    playerShipPosition.destroyer[counter][1] = startPositionCol;
                    counter++;                                                      // increase the counter one
                }
                break;
            }

        }
    }

    drawPlayerArea(playerMatrix, ROWS, COLS);           // redraw the player area with the position of CORVETTE    
    shipOrientiation = '\0';                            // reset the ship orientation
    shipPosition.clear();                               // clear the shipPosition
    while (true)                                        // loop for setup the battleship position    
    {
        cout << "Setup your corvette carrier location" << endl;
        cout << "Select your corvette carrier orientation (h-horizontal) and (v-vertical) : " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for ship orientation
            cin >> shipOrientiation;                        // take the input of ship orientation 'h' or 'v'
            if (tolower(shipOrientiation) == 'h' or tolower(shipOrientiation) == 'v') {    // compare the ship orientation input if it is 'v' or 'h' then fine
                cin.ignore();
                break;
            }
            else {
                cout << "Please enter a valid input 'H' or 'h' or 'V' or 'v' " << endl;     // if input is not h or v then ask for input again
                cin.ignore();
                continue;
            }
        }
        cout << "Enter the corvette position without a space (example: a0, a1...): " << endl;
        while (true) {                                      // take a infinite loop for satisfying the valid input for corvette position
            getline(cin, shipPosition);                     // get the ship position
            if (shipPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
                for (auto& c : shipPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
                if ((shipPosition[0] >= 'A' && shipPosition[0] <= 'J') && (shipPosition[1] >= '0' && shipPosition[1] <= '9')) { // check for valid input
                    break;      // if valid input then exit the infinite while loop
                }
                else {
                    cout << "Enter a valid corvette position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                    shipPosition.clear();
                    continue;
                }
            }
            else {
                cout << "Enter a valid corvette position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                shipPosition.clear();
                continue;
            }
            //cin.ignore();
        }

        if (tolower(shipOrientiation) == 'h')                               // check for horizontal setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';
            bool isConflict = conflictWithOtherShip(playerMatrix, startPositionRow, startPositionCol, CORVETTE_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionCol > CORVETTE_LENGTH + 6) || isConflict)                          // not able to setup the battleship horizontally from this position
            {
                cout << "You cannot place the corvette in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionCol; i < startPositionCol + CORVETTE_LENGTH; i++)
                {
                    playerMatrix[startPositionRow][i] = 'C';                          // set the player matrix with 'C' for indicating the battle location
                    playerShipPosition.corvette[counter][0] = startPositionRow;                             // insert the ship position values in the structure variable
                    playerShipPosition.corvette[counter][1] = i;
                    counter++;                                                      // increase the counter one
                }
                break;
            }
        }
        if (tolower(shipOrientiation) == 'v')                                   // check for the vertical setup
        {
            int startPositionRow = letterToRowNumber(shipPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
            int startPositionCol = shipPosition[1] - '0';                         // make a character value to integer
            bool isConflict = conflictWithOtherShip(playerMatrix, startPositionRow, startPositionCol, CORVETTE_LENGTH, tolower(shipOrientiation)); // check the ship is conflict with other ship position
            if ((startPositionRow > CORVETTE_LENGTH + 6) || isConflict)                            // not able to setup the destroyer vertically from this position

            {
                cout << "You cannot place the battleship in this position. TRY AGAIN!" << endl;
                shipPosition.clear();
                continue;
            }
            else
            {
                int counter = 0;
                for (int i = startPositionRow; i < startPositionRow + CORVETTE_LENGTH; i++)
                {
                    playerMatrix[i][startPositionCol] = 'C';                       // set the player matrix with 'C' for indicating the battle location
                    playerShipPosition.corvette[counter][0] = i;                                    // insert the ship position values in the structure variable
                    playerShipPosition.corvette[counter][1] = startPositionCol;
                    counter++;                                                      // increase the counter one
                }
                break;
            }

        }
    }
    drawPlayerArea(playerMatrix, ROWS, COLS);            // redraw the player area with the position of destroyer    


    return playerShipPosition;
}

//*****************************************************************
//Definition of function setComputerBattleShip                        *
//Set computer ship position and return structure                   *
//*****************************************************************
BattleShip setComputerBattleShip(char** computerMatrix) {
    const int AIRCRAFT_LENGTH = 5;                      // Unit length of the aircraft 
    const int BATTLESHIP_LENGTH = 4;                    // Unit length of the battleship 
    const int DESTROYER_LENGTH = 3;                     // Unit length of the destroyer
    const int CORVETTE_LENGTH = 2;                      // Unit length of the corvette
    
    BattleShip computerShipPosition = BattleShip();                    // Declare a structure variable to store computer ship position
    //setup aircraft
    int rowPosition = rand() % 2 + 2;                       // Randomly select a row position from 2-3  
    int colPosition = rand() % 2 + 2;                       // Randomly select a column position from 2-3
    int shipOrientation = rand() % 2;                   // Select a ship orientation value 0 or 1
    if (shipOrientation == 0)                           // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        for (int i = colPosition; i < colPosition + AIRCRAFT_LENGTH; i++)
        {
            computerMatrix[rowPosition][i] = 'A';                          // Set the computer matrix with 'A' for indicating the aircraft location
            computerShipPosition.aircraft[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.aircraft[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {                                                                       // Otherwise orientation is vertical
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + AIRCRAFT_LENGTH; i++)
        {
            computerMatrix[i][colPosition] = 'A';                       // Set the player matrix with 'A' for indicating the battle location
            computerShipPosition.aircraft[counter][0] = i;              // Insert the ship position values in the structure variable
            computerShipPosition.aircraft[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }

    //setup the battleship
    rowPosition = (rand() % 2) + 5;                       // Randomly select a row position from 5-6  
    colPosition = (rand() % 2) + 5;                       // Randomly select a column position from 5-6
    shipOrientation = (rand() % 2);                   // Select a ship orientation value 0 or 1
    if (shipOrientation == 0)                       // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        for (int i = colPosition; i < colPosition + BATTLESHIP_LENGTH; i++)
        {
            computerMatrix[rowPosition][i] = 'B';                          // Set the computer matrix with 'B' for indicating the battleship location
            computerShipPosition.battleship[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.battleship[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {                                                                       // Otherwise orientation is vertical
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + BATTLESHIP_LENGTH; i++)
        {
            computerMatrix[i][colPosition] = 'B';                       // Set the player matrix with 'B' for indicating the battle location
            computerShipPosition.battleship[counter][0] = i;              // Insert the ship position values in the structure variable
            computerShipPosition.battleship[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }

    //setup the corvette
    rowPosition = (rand() % 2) + 8;                   // Randomly select a row position from 8-9  
    colPosition = (rand() % 3);                       // Randomly select a column position from 0-2
    shipOrientation = (rand() % 2);
    if (shipOrientation == 0)                         // If value is 0 then consider the orientation as horizontal;
    {
        int counter = 0;
        for (int i = colPosition; i < colPosition + DESTROYER_LENGTH; i++)
        {
            computerMatrix[rowPosition][i] = 'D';                          // Set the computer matrix with 'D' for indicationg the battleship location
            computerShipPosition.destroyer[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.destroyer[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {   
                                                          // Otherwise orientation is vertical
        rowPosition = (rand() % 3);                       // Randomly select a row position from 0-2  
        colPosition = (rand() % 2) + 8;                   // Randomly select a column position from 8-9
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + DESTROYER_LENGTH; i++)
        {
            computerMatrix[i][colPosition] = 'D';                       // Set the player matrix with 'D' for indicationg the battle location
            computerShipPosition.destroyer[counter][0] = i;            // Insert the ship position values in the structure variable
            computerShipPosition.destroyer[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }
    //setup the destroyer
    shipOrientation = (rand() % 2);                    // Randomly select ship orientation for destroyer 
    if (shipOrientation == 0)                         // If value is 0 then consider the orientation as horizontal;
    {
        rowPosition = (rand() % 2);                   // Randomly select a row position from 0-1  
        colPosition = (rand() % 7);                       // Randomly select a column position from 0-6
        int counter = 0;
        for (int i = colPosition; i < colPosition + CORVETTE_LENGTH; i++)
        {
            computerMatrix[rowPosition][i] = 'C';                          // Set the computer matrix with 'C' for indicating the battleship location
            computerShipPosition.corvette[counter][0] = rowPosition;       // Insert the ship position values in the structure variable
            computerShipPosition.corvette[counter][1] = i;                 // Insert the column position 
            counter++;                                                     // Increase the counter one
        }
    }
    else
    {
        // Otherwise orientation is vertical
        rowPosition = (rand() % 5) + 2;                       // Randomly select a row position from 2-6  
        colPosition = (rand() % 2);                   // Randomly select a column position from 0-1
        int counter = 0;
        for (int i = rowPosition; i < rowPosition + CORVETTE_LENGTH; i++)
        {
            computerMatrix[i][colPosition] = 'C';                       // Set the player matrix with 'C' for indicating the battle location
            computerShipPosition.corvette[counter][0] = i;            // Insert the ship position values in the structure variable
            computerShipPosition.corvette[counter][1] = colPosition;
            counter++;                                                  // Increase the counter one
        }
    }
    return computerShipPosition;
 }

//*****************************************************************
//Definition of function letterToRowNumber                        *
//This function will determine the letter (A, B, C...J) value to  *
//integer y-axis value (0,1,2...9) using enum identifier          *
//*****************************************************************
int letterToRowNumber(char letter)
{
    switch (letter)
    {
    case 'A':
        return A;                       // return 0 for enum identifier A
    case 'B':
        return B;                       // return 1 for enum identifier B                                              
    case 'C':
        return C;                       // return 2 for enum identifier C
    case 'D':
        return D;                       // return 3 for enum identifier D
    case 'E':
        return E;                       // return 4 for enum identifier E
    case 'F':
        return F;                       // return 5 for enum identifier F
    case 'G':
        return G;                       // return 6 for enum identifier G
    case 'H':
        return H;                       // return 7 for enum identifier H
    case 'I':
        return I;                       // return 8 for enum identifier I
    case 'J':
        return J;                       // return 9 for enum identifier J
    }
}
//*****************************************************************
//Definition of function conflictWithOtherShip                    *
//This check the ship position conflict with other ship or not    *
//*****************************************************************
bool conflictWithOtherShip(char** playerMatrix, int row, int col, int shipLength, char shipOrientation)
{
    if (shipOrientation == 'h')                      // check the ship orientation
    {
        for (int i = col; i < col + shipLength; i++) // for horizontal orientation check the column till ship length
        {
            if (playerMatrix[row][i] != '*') {       // check the character for position of the matrix, if it is not '*' that means it is conflict with other ship position
                return true;                         // and return true   
            }
        }
    }
    else
    {
        for (int i = row; i < row + shipLength; i++)  // for horizontal orientation check the row till ship length
        {
            if (playerMatrix[i][col] != '*') { // check the character for position of the matrix, if it is not '*' that means it is conflict with other ship position         
                return true;                    // and return true 
            }
        }
    }
    return false;
}

//*****************************************************************
//Definition of function showPlayZone                    *
//This draw the computer and player play zone    *
//*****************************************************************
void showPlayZone(char** playerMatrix, char** pcMatrix) {
    
    char yCoord[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0' };     // declare a character array for maintain y-coordinate as a character
    cout << " -          Computer Zone                          Your Zone      -" << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -           - - - 0 1 2 3 4 5 6 7 8 9 -" << endl;
    for (int i = 0; i < ROWS; i++){         //Nested loop draw the player and computer matrix                      
        cout << " | " << yCoord[i] << " | ";    // Set the y-column 'A' to 'J'
        for (int j = 0; j < COLS; j++) {
            if (pcMatrix[i][j] >= 'A' && pcMatrix[i][j] <= 'D') // Hide the computer ship position
            {
                cout <<"* ";   // Display the computer matrix
            }
            else {
                cout << pcMatrix[i][j] << " ";   // Display the computer matrix
            }
        }
        cout << "|           | " << yCoord[i] << " | ";     //set the y-column 'A' to 'J'
        for (int j = 0; j < COLS; j++)
            cout << playerMatrix[i][j] <<" ";       // Display the player matrix
        cout << "|" << endl;
    }

 }

//*****************************************************************
//Definition of function startPlay                    *
//This function allow to input player and computer attack position each other   *
//*****************************************************************
void startPlay(char** playerMatrix, char** pcMatrix, BattleShip* battleShipInfo)
{
    const int POSITION_LENGTH = 2;
    int rowPosition;
    int colPosition;
    string attackPosition;
    bool isSuccessful;
    cout << "~~ Now your turn to attack the computer ship position ~~" << endl;
    
    cout << "Choose a position for attacking the computer ships (example: a0, a1...): " << endl;
    while (true) {                                      // Take a infinite loop for satisfying the valid input for attack position
        getline(cin, attackPosition);                     // Get the ship position
        if (attackPosition.length() == POSITION_LENGTH) { // position length should the 2 character length
            for (auto& c : attackPosition) c = toupper(c);   // make the uppercase of the input position for comparing value and allow for lower or upper case character
            if ((attackPosition[0] >= 'A' && attackPosition[0] <= 'J') && (attackPosition[1] >= '0' && attackPosition[1] <= '9')) { // check for valid input
                rowPosition = letterToRowNumber(attackPosition[0]);      // Get the start value of y-axis (0,1,2...9) from the letter position (A,B,C....J)
                colPosition = attackPosition[1] - '0';                   // Convert the column position character to integer  
                isSuccessful = checkSuccessful(playerMatrix, &battleShipInfo[0], rowPosition, colPosition);           // check it is successfully hit or not // the function body will be written next version
                if (isSuccessful) {                         // If successfully hit then player will get another change for attack
                    attackPosition.clear();
                    continue;
                }
                else {
                    break;                                  // End the player attack and computer will attack now to player battle ship
                }
            }
            else {
                cout << "Enter a valid aircraft position without a space (example: a0, a1...): " << endl;   // ask for valid input again
                attackPosition.clear();
                continue;
            }
        }
        else {
            cout << "Enter a valid aircraft position without a space (example: a0, a1...): " << endl;   // ask for valid input again
            attackPosition.clear();
            continue;
        }
    }

    cout << "Computer is now attacking your ships...: " << endl;
    while (true) {                                      // Take a infinite loop for satisfying the valid input for attack position
        rowPosition = rand() % 10;                        // randomly select a row position from 0-9 
        colPosition = rand() % 10;                        // randomly select a column position from 0-9 
        isSuccessful = checkSuccessful(playerMatrix, &battleShipInfo[0], rowPosition, colPosition);           // check it is successfully hit or not // the function body will be written next version
        if (isSuccessful) {                         // If successfully hit then player will get another change for attack
            continue;
        }
        else {
            break;                                  // End the computer attack and player will attack now to player battle ship
        }
    }
}
//*****************************************************************
//Definition of function checkSuccessful                          *
//This function check the attack is successful or not and         *
//Update the ship position structure                              *
//*****************************************************************
bool checkSuccessful(char** playerMatrix, BattleShip *shipPosition, int row, int col) 
{
    return false;                                                       // Full body will be the next version
}
//*****************************************************************
//Definition of function destroy                                  *
//De-allocate memory.                                             *
//*****************************************************************
void destroy(char** array, int rows, int cols) {
    //Free the memory after the use of array
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
}


