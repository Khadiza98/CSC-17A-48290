/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 4, 2022, 11:48 AM
 * Purpose: tracking of weather condition during the past year summer season. 
 */
//System Level Libraries
#include <iostream> //input-output library
#include <fstream> //input-output file library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
const int ROWS = 3;
const int COLOUMS = 30;
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
void readfile(char [][COLOUMS]); //Read the character from a file
void reportDisplay(char [][COLOUMS]);//Print the report


//Execution begins here!
int main(int argc, char** argv) {
    
    //Declare Variables
    char arrayList[ROWS][COLOUMS];
    
    //read the file
    readfile(arrayList);
    //generate the report by calculating rainy, cloudy and sunny days
    reportDisplay(arrayList);
    
    //Exit the program
    return 0;
} //close the main function

/*This function read the RainOrShine.txt file and store each character 
 *into the two dimension array
 *@Param array is a two dimensional character array to hold the character of file
 *@Return none
 */
void readfile(char array[][COLOUMS]) {
    
    string fileName = "RainOrShine.txt";
    FILE* input_file = fopen(fileName.c_str(), "r"); // open the file
    
    //check the file is opened validly or not 
    if (input_file == nullptr) {
       cout << "Error: Entered file can not read!!!" << endl;
    }
    
    // read the file until the end, get the character using getc()function and 
    // assign them into the array.
    char character;
    int i=0, j=0; //local variable, initialize with default value.
    while (!feof(input_file)) {
       character = getc(input_file); // read a character from the file
       if (character == 'R' || character == 'C' || character == 'S')
       {
           array[i][j] = character; //assign character into the array
           j +=1;
           if (j%COLOUMS == 0) // check the end of a row
           {
               i +=1;
               j = 0;
           }
        }
    }
    fclose(input_file); // close the file
}

/*
 * Function to calculate how many days were rainy, sunny or cloudy and
 * which months was the largest rainy months
 * @Param array is a two dimensional character array
 * @Return none
 */
void reportDisplay(char array[][COLOUMS]){
    //Declare local variables
    int totalR,
        totalC,
        totalS;
    string month[ROWS] ={"June", "July", "August"};
    string maxRainyMonth;
    int maxRainy = -1;
    for (int i = 0; i < ROWS; i++) { //Loop through the rows
        totalR = 0;
        totalC = 0;
        totalS = 0;
        for (int j = 0; j < COLOUMS; j++) { //loop through the columns
            
            // count the rainy, cloudy and sunny day
            if (array[i][j] == 'R') {
                totalR+=1;
            }
            else if(array[i][j] == 'C') {
                totalC+=1;
            }
            else if(array[i][j] == 'S') {
                totalS+=1;
            }
        }
        //display the total rainy, cloudy and sunny day
        cout<<month[i] << "\t" << "Rainy: "<<totalR<<"\t"<<"Cloudy: "
            <<totalC<<"\t"<<"Sunny: "<<totalS;
        cout<<endl;
        
        //check for the month of maximum rainy day
        if(totalR > maxRainy){
            maxRainyMonth = month[i];
            maxRainy = totalR;
        }
    }
    // display the maximum rainy month
    cout<<"Largest rainy month: " <<maxRainyMonth;
}

