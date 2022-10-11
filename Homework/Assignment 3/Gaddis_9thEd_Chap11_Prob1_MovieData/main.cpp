/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/28/2022
 * Purpose: simulating movie data and display in clear formatted using structure
 */
//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!
//declare structure
struct MovieData{
    string title,                       //title of movie
           director;                    //name of director
    unsigned short yearReleased,        //year of movie released
                   runningTimeInMins;   //movie running time
};
//Function Prototypes
void displayMovieInfo(const MovieData*, int); //print movie information in clear format

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables and initialize
    int numOfMovies;
    MovieData *data; //pointer to the array
    
    cout <<"This program reviews structures" <<endl;
    cout <<"Input how many movies, the Title of the Movie, Director,"
         <<" Year Released, and the Running Time in (minutes)."<<endl;
         
    cin >> numOfMovies; // input number of movies
    cout << endl;
    data = new MovieData[numOfMovies]; //dynamically allocate array of structures
    for (int i = 0; i < numOfMovies; i++) {
        cin.ignore();                  //to ignore one or more chars from input buffer
        getline(cin, data[i].title);    //input name of 1st movie
        getline(cin, data[i].director); //input director name of 1st movie
        cin >> data[i].yearReleased;    //year of movie released input
        cin >> data[i].runningTimeInMins;//movie time input
    }
   
    displayMovieInfo(data, numOfMovies); //calling displayMovieInfo fuction to print movie data
    
    delete[] data;
    //Exit the program
    return 0;
}
//This function display movies data in clear format and manner
void displayMovieInfo(const MovieData* data, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Title:     " << data[i].title << endl;
        cout << "Director:  " << data[i].director <<endl;
        cout << "Year:      " << data[i].yearReleased <<endl;
        cout << "Length:    " << data[i].runningTimeInMins <<endl;
        if (i != size-1) {
            cout << endl;
        }
    }
   
}
