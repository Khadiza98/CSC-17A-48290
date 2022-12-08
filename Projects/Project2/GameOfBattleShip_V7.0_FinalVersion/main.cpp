/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on December 05, 2022, 7:57 PM
 * Purpose: Game of BattleShip
 *          Fill 2-D vector with '*'
 *          Apply the Rules of Battleship
 *          Set up player battleship
 *          Set up computer battleship
 *          Draw the both matrix and playing zone
 *          Start the play, allow user to input and computer to select input randomly
 *          Check the input of both player and computer that hit successfully or
            not, update both player matrix and ship status structure.
 *          Draw the number of remaining ship status both player and computer
 *          Winner of the game.
 *          Save game and game summary; open a save game and play it,
 *          update the main menu, project testing, update comments.
 *          Specification and implementation of base,derived, 
            abstract(only specification), template or other classes.

 */
 //System Level Libraries
#include <iostream> //Input-output library
#include <string>   //Needed for strings
#include <cstdlib>  //Srand to set the seed
#include <ctime>    //set for time()
#include <iomanip>  //Format the output
#include <stdlib.h> //System()
using namespace std;//Standard Name-space under which System Libraries reside

//User defined libraries
#include "BShipSetUp.h" //needed for BShipSetUp class
#include "LastGameSummary.h" //needed for LastGameSummary class

//Function Prototypes
void gameRules(); //display the game rules
void menu(); //Display the menu

//Execution begins here!
int main() {
    //Random seed here
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    char choice;                     // take input for menu option
    const int NUM_PLAYERS = 2;       // Number of player
    BShipSetUp bsPlayer[NUM_PLAYERS];// Array of class BShipSetUp
    string playerName;               //To hold the player name
    bool sGame;                      // To track do while-loop for menu
    bool tryAgain = true;            //Flag to reread the input for player name
    // Define a object dynamically for LastGameSummary class
    LastGameSummary *objLastSummary = new LastGameSummary; 
    BattleShip objBship;             // Define a object for BattleShip class
    BShipSetUp objBsetup;            // Define a object for BShipSetUp class
    
    //Output the game statistics or menu to the screen
    do {
        sGame = true;
        menu();
        cin >> choice;  // Ask for input to see the rules or continue to game
        if (choice == '1')  gameRules(); //Call function to view the games rules   
        else if (choice == '2') {
            bool ga = objBsetup.openGame();   // Open a save game
            if (!ga) cout << "Saved game is not available now" << endl;
            else     return 0;      // If open successfully, then play and exit
        } //End else-if
        else if (choice == '3') {
            // Display the last time winner of the match
            string w = objLastSummary->lastWinner();
            cout << "The winner was :" + w << endl;
        } //End else-if
        // Display the game summary
        else if (choice == '4') objLastSummary->lastGameSummary();   
        
        else if (choice == 'x') return 0;           // exit the program 
        else                    sGame = false;      // Start to play
    } while (sGame); //End do-while loop

    cin.ignore(); //To ignore one or more characters from the input buffer
    cout << "\t Please enter your name: "; //Ask user to enter name
    getline(cin, playerName); // Take the player name
    while (tryAgain) {
        try {
            //create an object of BShipSetUp class and using constructor
            //to initialize member
            BShipSetUp bSetUp(playerName);
            // Method call from the base class object that
            // will show a compile-time polymorphism 
            objBship.showPlayZone(objBship.getMatrixData()); 
            //Set player ship position and return structure
            bsPlayer[0] = bSetUp.setYourBattleShip(bSetUp);
            //Set computer ship position and return structure
            bsPlayer[1] = bSetUp.setComputerBattleShip(bSetUp);
            int retInit = bSetUp.displayShipStatus(bsPlayer[0], bsPlayer[1]);
            //Method call from derived class that show compile-time polymorphism
            bSetUp.showPlayZone();  
            bSetUp.startPlay(bsPlayer[0], bsPlayer[1]);
            tryAgain = false;
        } //End try
        catch (BShipSetUp::InvalidName) {
            cout << "\t Error: invalid input -> [" << playerName
                << "] entered for the Player Name!!" << endl;
            cout << "\t Enter the valid name: ";
            getline(cin, playerName);
        } //End catch 

    } //End while-loop
    
    //free the memory
    delete objLastSummary;

    //Exit the program
    return 0;
} //end of main function

//*************************************************************
//Definition of menu.                  
//Input->: None, data on menu item
//Output->:No return, This display menu item  
//*************************************************************
void menu() {
    //Display menu
    cout << endl;
    cout << endl;
    cout << setfill('-') << setw(112) << "" << endl;
    cout << "\t\t --------------WELCOME TO BATTLESHIP GAME--------------\n";
    cout << "\t Press 1= Game Rules, 2= Open a save game,";
    cout << " 3= Last Winner, 4= Last Game Summary, X = Exit" << endl;
    cout << "\t\t Any other key for start play....." << endl;
    cout << setfill('-') << setw(112) << "" << endl;
    cout << "\t Please choose an item..." << endl;
    cout << "\t\t (1) Game Rules " << endl;
    cout << "\t\t (2) Open a Saved Game " << endl;
    cout << "\t\t (3) Last Winner " << endl;
    cout << "\t\t (4) Last Game Summary " << endl;
    cout << "\t\t (x) Exit " << endl;
    cout << "\t\t ()  Any other key to play " << endl;
    cout << setfill('-') << setw(112) << "" << endl;
} //End menu function

//*****************************************************************
//Definition of function gameRules
//Input->: None, data on game rules
//Output->:No return, Display the game rules                             
//*****************************************************************
void gameRules() {

    system("cls"); //clear the screen
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
        " - - - - - - - - - - - " << endl;
    cout << " - - - - -                     ~~~Welcome to BattleShip Game~~~   "
        "            - - - - - -" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ Battleship game information/rules~ ~"
        "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
        " - - - - - - - - - - - -" << endl;
    cout << "1.Total four battleships for each player, the winner is who"
        " destroy other battleships first" << endl;
    cout << "2.The battlefield is 10x10 grid where you place all four ships\n";
    cout << "3.You can place your ships position using coordinate values(e.g."
        ", A0, B1)where 'A' or 'a' is the row and 1-10 is the col number\n";
    cout << "4.Also, you can place the ship orientation, i.e horizontal or "
        "vertical. For horizontal orientation, type 'h' or 'H', and type"
        " 'v' or 'V' for vertical option" << endl;
    cout << "5.You have total four battle ships: Aircraft Carrier-> 5, "
        "Battleship-> 4, Destroyer-> 3 and Corvette-> 2 units long" << endl;
    cout << "6.You cannot place two ship at any same coordinate location\n";
    cout << "7.After placing your ship position; you are ready to play. To "
        "attack the opponent, enter a position value such as A1 or a1, b9,"
        " j5 (without spacing) and so on,  " << endl;
    cout << "8.If your attack is successful then it is denoted by '@' "
        "and you will continue your turn" << endl;
    cout << "9.If your attack is missed then it is denoted by 'o'"
        " and your turn will be end" << endl;

} //End gameRules function




