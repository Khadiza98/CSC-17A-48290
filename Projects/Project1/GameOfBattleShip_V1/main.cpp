/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 6, 2022, 11:15 AM
 * Purpose: Game of BattleShip
 *          Fill 2-D pointer with '*' 
 *          Apply the Rules of Battleship
            
 */
//System Level Libraries
#include <iostream> //Input-output library
#include <cstdlib>  //Srand to set the seed or system()
using namespace std;//Standard Name-space under which System Libraries reside

//Global Constants
//Function Prototypes
void gameRules();//display the game rules
char** getMatrixData(int rows, int cols);// Fill the computer or player matrix grid (10x10) with '*' character

//Execution begins here!
int main() {
    //declare variables
    char gameRule;                                              // take input for checking the start play or game rules
    const int ROWS = 10;                                        // Constant rows for 10x10 matrix
    const int COLS = 10;                                        // Constant column for 10x10 matrix
    char** pcMatrix;                                            // point to the computer matrix grid
    char** playerMatrix;                                        // point to the player matrix grid
    
    // Fill computer matrix grid (10x10) with '*' character
    pcMatrix = getMatrixData(ROWS, COLS);     
    // Fill the player matrix grid (10x10) with '*' character
    playerMatrix = getMatrixData(ROWS, COLS);                   
   
    //Output the game statistics to the screen
    cout << "\t\t (1) Game Rules " << endl;
    cout << "\t\t ( ) Play Battleship Now " << endl;
    cout << "\t\t Press 1 for game rules or Press any key for play....." << endl;
    cin >> gameRule;                                            // ask for input to see the rules or continue to game
    
    if (gameRule == '1') {                                      // if input is one then player can review the game rules
        // call the function to view the games rules
        gameRules();                                            
    }
    else {
     // develop the code for next version                                                           
    }
    //Exit the program
    return 0;
}
//display the game rules
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

//*************************************************************
//Definition of function getMatrixData                        *
//This function fill the computer or player matrix grid (10x10) with '*' character
//Return the 2-D array pointer.
char** getMatrixData(int rows, int cols) {
    int i, j; //loop counter variable
    char** arrMatrix; //pointer to the array
    arrMatrix = new char* [rows]; //Allocating the row space in heap dynamically
    for (i = 0; i < rows; i++) {
        arrMatrix[i] = new char[cols];  //Allocating the column space in heap dynamically
    }
    //read into the array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arrMatrix[i][j] = '*';      //set the '*' character for the matrix
        }
    }
    return arrMatrix; //return pointer to the array
}
