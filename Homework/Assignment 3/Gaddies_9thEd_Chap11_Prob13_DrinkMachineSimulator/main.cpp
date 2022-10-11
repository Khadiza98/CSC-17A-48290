/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/26/2022
 * Purpose: simulates a soft drink machine using loop and structure variable
 */
//System Level Libraries
#include <iostream> //input-output library
#include <iomanip> //setw()
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!
struct DrinkMachine{
    string name; //name of drinks
    float cost;  //cost of drinks
    int numOfDrinks; //number of drinks available
};

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    
    //Declare Variables, constant and Initialize
    const int NUM_DRINKS = 5;
    bool quit = false;           //looping variable
    float totalEarned = 0.0f;    //total earned from the drinks initialized with default value
    string dOrquit;              //used to hold string from user
    float money = 0.0f;          //used to store money to buy drink initialized with default value
    float change = 0.0f;         //change of money initialized with default value
    //array of structure
    DrinkMachine data[NUM_DRINKS] = { {"Cola", 75, 20},
                                      {"Root Beer", 75, 20},
                                      {"Lemon-Lime", 75, 20},
                                      {"Grape Soda", 80, 20},
                                      {"Cream Soda", 80, 20} };
                                      
    //Map the inputs/known to the outputs
    do{
       
        for(int i = 0; i < NUM_DRINKS; i++) { //loop through the structure array to display the choices
            cout <<setw(10)<<left << data[i].name<<" "<<(data[i].cost)
                 <<"  "<<data[i].numOfDrinks<<endl;
        }
        cout << "Quit"<<endl; //print quit to eager user to get out from the loop
        
        
        getline(cin, dOrquit); //to read the string
        
        //check user like to quit the program or go for the next step
        if (dOrquit == "Quit") {
            quit = true;
            
        } else {
            
            for(int i = 0; i < NUM_DRINKS; i++) { //loop through the structure array
            
                if (dOrquit == data[i].name) {  //check user name equals to menu name
                
                    if (data[i].numOfDrinks > 0) { //check availability of number of drinks
                    
                        cin >> money;              //receive money from user
                        while(money < 75 || money > (1.00*100)) { //input validation check
                            cin >> money;
                        }
                        
                        change = money - data[i].cost; //calculate money change
                        cout << change << endl;
                        
                        data[i].numOfDrinks -= 1; //count number of drinks left
                        totalEarned += data[i].cost; //calculate total earned from drinks
                    }
                    else {
                        cout << data[i].name << " sold out!!!" << endl;
                    }
                    
                }
                
            }
            cin.ignore(); //ignore or clear one or more characters from the input buffer
             
        }
        
        
        
    } while(!quit); //loop until enter Quit
    
    cout << static_cast<int>(totalEarned) << endl; //convert total earned into int and print
    
    
    //Exit the program
    return 0;
}
