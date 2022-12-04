/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 9, 2022, 11:48 AM
 * Purpose: Demonstrates a relationship between GradedActivity and Essay class
             based on an essay grade by writing a main program.
 */
//System Level Libraries
#include <iostream> //input-output library
#include <iomanip> //needed for format
using namespace std;

//User Defined Libraries
#include "Essay.h"

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    float gramPoint;    //number of points on grammar
    float spellPoint;   //number of points on spelling
    float contentPoint; //number of points on content
    float corLengthPoint;//number of points on correct Length
    float totalPoints; //holds total point on an essay 
    
    //Get the points for grammar, spelling, content, correct Length on Essay class
    cout << "Enter the data to determine a student grade on an essay:\n";
    do{
        cout << "How many points receive on Grammar between(0 to 30): ";
        cin >> gramPoint;
    } while (gramPoint < 0 || gramPoint > 30); //check input validation
    do{
        cout << "How many points receive on Spelling between(0 to 20): ";
        cin >> spellPoint;
    } while (spellPoint < 0 || spellPoint > 20); //check input validation
    do{
        cout << "How many points receive on Correct Length between(0 to 20): ";
        cin >> corLengthPoint;
    } while (corLengthPoint < 0 || corLengthPoint > 20); //check input validation
    do{
        cout << "How many points receive on Content between(0 to 30): ";
        cin >> contentPoint;
    } while (contentPoint < 0 || contentPoint > 30); //check input validation
    
    //Define Essay instance dynamically and initialize it with the values entered
    Essay *written = new Essay(gramPoint, spellPoint, contentPoint, corLengthPoint);
    
    //Display the essay result
    cout << fixed << setprecision(1);
    cout << "\n============================================================\n";
    cout << "Here are the information about how did a student on an essay:\n";
    cout << "============================================================\n";
    cout << "Grammar: \t" << written->getGrammar() << " Points\n";
    cout << "Spelling:\t" << written->getSpelling() << " Points\n";
    cout << "Correct Length: " << written->getCorrectLength() << " Points\n";
    cout << "Content: \t" << written->getContent() << " Points\n";
    //Calculate total points on an essay receive within 100 points
    totalPoints = written->getGrammar() + written->getSpelling() + 
                  written->getCorrectLength() + written->getContent();
    cout << "Total points on an essay: -> " << totalPoints << " Points" <<endl;
    cout << "\nThe grade on an essay: -> " << written->getLetterGrade() << endl;

    //free the memory
    delete written;
    //Exit the program
    return 0;
}

