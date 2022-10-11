/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/30/2022, 11:48 AM
 * Purpose: Tracking of a speakers bureau using menu-driven user interface and structure
 */
 //System Level Libraries
#include <iostream> //input-output library
#include <iomanip>  //setw()
#include <string>
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
const int SIZE = 10;    //size of array
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!
//structure define
struct SpeakersBureau {
    string name;          //name of speaker
    string telephoneNo;   //phone number of speaker
    string speakingTopic; //name of speaking topics
    float feeRequired;    //speaker fees
};
//Function Prototypes
void displayData(SpeakersBureau[], int); //print the stored data in structure array
void modifyData(SpeakersBureau[], int); //modify the existing data of speaker

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int count = 0;            //arrays size tracking variable
    bool exit = false;        //used to continue loop or not
    int option;               //hold the input for menu choice
    SpeakersBureau info[SIZE];//structure array

    //Display the menu repeatedly until the user like to exit,
    //allow user to choose the option, enter the data to array, change the content of any element, and 
    //let user to display all data stored in the array and exit.
    do {
       
        cout << "\t\tWELCOME TO THE MENU\t\t" << endl;
        cout << setw(25) << setfill('=') << "*****" << setw(25) << " " << endl;
        cout << "[1] Add a new speaker." << endl;
        cout << "[2] Modify an existing data of speaker." << endl;
        cout << "[3] Display all data stored." << endl;
        cout << "[0] Exit." << endl;
        cout << setw(50) << setfill('=') << " " << endl;
        cout << "[ Current number of speaker: " << count << "]" << endl;
        cout << "Choose your option-> 1,2,3 or 0: ";
        cin >> option;
        while (!(option >= 0 && option <= 3)) { //input validation check
            cout << "Invalid input!!! Try with 1, 2, 3 or 0" << endl;
            cin >> option;
        }
        cout << setw(50) << setfill('-') << " " << endl;
        cout << "Your choice: " << option << "\n" << endl;

        //allow user to enter their option
        switch (option) {

            case 1:
                cout << "*****************Add a new speaker****************" << endl;
                cin.ignore();
                cout << "Name: ";
                getline(cin, info[count].name);
                while (info[count].name.length() == 0) { //input validation check
                    cout << "Invalid input! please enter the name again" << endl;
                    getline(cin, info[count].name);
                }

                cout << "Telephone number: ";
                getline(cin, info[count].telephoneNo);
                while ((info[count].telephoneNo.length() < 10)
                    || (info[count].telephoneNo.length() > 15)) { //input validation check
                    cout << "Invalid input!Please enter the telephone no. in correct digit" << endl;
                    getline(cin, info[count].telephoneNo);
                }

                cout << "Speaking topic: ";
                getline(cin, info[count].speakingTopic);
                while (info[count].speakingTopic.length() == 0) { //input validation check
                    cout << "Invalid input! please enter the speaking topic again" << endl;
                    getline(cin, info[count].speakingTopic);
                }

                cout << "Required fee: ";
                cin >> info[count].feeRequired;
                while (info[count].feeRequired < 0) { //input validation check
                    cout << "Invalid input! Enter the positive value" << endl;
                    cin >> info[count].feeRequired;
                }
                count++;
                break;
            case 2:
                cout << "\n********Modify an existing data of speaker********\n" << endl;
                modifyData(info, count);
                break;
            case 3:
                if (count == 0) cout << "No data are exist!!Try to add new speaker, please" << endl;
                else {
                    cout << "\n*******Display the data stored about speaker*****\n" << endl;
                    displayData(info, count);
                }
                break;
            case 0: cout << "You would like to exit now, Thank you for your time!!!" << endl;
                exit = true;
                break;
        }
        cout << endl;

    } while (!exit);

    //Exit the program
    return 0;

} //close main function

//print the stored data in structure array
void displayData(SpeakersBureau info[], int size) {
    for (int j = 0; j < size; j++) {
        cout << "Information about the #" << j + 1 << " speaker" << endl;
        cout << setw(20) << "Speaker Name: " << info[j].name << endl;
        cout << setw(20) << "Telephone Number: " << info[j].telephoneNo << endl;
        cout << setw(20) << "Speaking Topic: " << info[j].speakingTopic << endl;
        cout << setw(20) << "Required Fee$: " << info[j].feeRequired << endl;
        cout << setw(50) << setfill('-') << " " << endl;
    }
}

//modify the existing data of speaker
void modifyData(SpeakersBureau info[], int size) {
    int speakerNo;     //number of speaker user like to modify
    bool exit = false; //loop tracking variable
    int option;        //which content like to change by user

    cout << "[ Current number of speaker: " << size << "]" << endl;

    if (size > 0) {    //check number of speaker is available to modify
        cout << "Enter the speaker # you would like to update: ";
        cin >> speakerNo;
        while (!(speakerNo > 0 && speakerNo <= size)) {  //input validation check
            cout << "#" << speakerNo << " speaker not exist" << endl;
            cout << "Try again with existing number of speaker: ";
            cin >> speakerNo;
        }
        cout << setw(50) << setfill('-') << " " << endl;

        //menu for changing any content of the element until user like to exit
        do {
            cout << "\nNow choose your option, please:\n" << endl;
            cout << "[1] Modify the speaker name." << endl;
            cout << "[2] Modify the speaker telephone number." << endl;
            cout << "[3] Modify the speaker speaking topic." << endl;
            cout << "[4] Modify the speaker required fee$." << endl;
            cout << "[0] Exit." << endl;
            cout << setw(50) << setfill('-') << " " << endl;
            cout << "Choose your option-> 1,2,3,4 or 0: ";
            cin >> option;
            while (!(option >= 0 && option <= 4)) { //input validation check
                cout << "Invalid input!!! Try with 1, 2, 3, 4 or 0" << endl;
                cin >> option;
            }

            cin.ignore(); //used to ignore one or more character from the input buffer
            //let user to choose their modify options and activity
            switch (option) {

                case 1: // allow user to change name 
                    cout << "Name: ";
                    getline(cin, info[speakerNo - 1].name);
                    while (info[speakerNo - 1].name.length() == 0) {
                        cout << "Invalid input! please enter the name again" << endl;
                        getline(cin, info[speakerNo - 1].name);
                    }
                    cout << setw(50) << setfill('-') << " " << endl; //output formatting
                    break;
                case 2: //let user to change the telephone number of speaker until enter the correct number of digit
                    cout << "Telephone number: ";
                    getline(cin, info[speakerNo - 1].telephoneNo);
                    while ( (info[speakerNo - 1].telephoneNo.length() < 10)
                           || (info[speakerNo - 1].telephoneNo.length() > 15) ) {
                        cout << "Invalid input!Please enter the telephone no. in correct digit" << endl;
                        getline(cin, info[speakerNo - 1].telephoneNo);
                    }
                    cout << setw(50) << setfill('-') << " " << endl;
                    break;
                case 3: //let user to change the speaking topic until enter the valid input
                    cout << "Speaking topic: ";
                    getline(cin, info[speakerNo - 1].speakingTopic);
                    while (info[speakerNo - 1].speakingTopic.length() == 0) {
                        cout << "Invalid input! please enter the speaking topic again" << endl;
                        getline(cin, info[speakerNo - 1].speakingTopic);
                    }
                    cout << setw(50) << setfill('-') << " " << endl;
                    break;
                case 4: //allow user to modify the speaker required fee until enter the positive value
                    cout << "Required fee: ";
                    cin >> info[speakerNo - 1].feeRequired;
                    while (info[speakerNo - 1].feeRequired < 0) {
                        cout << "Invalid input! enter the positive value" << endl;
                        cin >> info[speakerNo - 1].feeRequired;
                    }
                    cout << setw(50) << setfill('-') << " " << endl;
                    break;
                case 0: //allow user to exit the modify menu
                    cout << "You had a great tour on speaker modification!!" << endl;
                    exit = true;
                    break;
            }
        } while (!exit);
    }
    else { //number of speaker not available to modify
        cout << "No data are exist!!Try to add new speaker, please" << endl;
    }
   
}//close the modify function