/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/29/2022
 * Purpose: Evaluate weather data using structure variable
 */
//System Level Libraries
#include <iostream> //input-output library
#include <string>
#include <iomanip>
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!
struct Weather{
    string month;  //name of months
    float totalRainfall;//
    float highTemp;
    float lowTemp;
    float avgTemp;
    
};

//Function Prototypes
void getData(Weather [], int); //get all data from the user
void calculateAvgRainfall(Weather [], int); //average rainfall of a year in inches
void lowestTemp_Month (Weather [], int, float&);//get lowest temperature and month of a year
void highestTemp_Month (Weather [], int, float&);//get highest temperature and month of a year

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables and constant
    float lowestTemp;           //lowest temperature of a year
    float highestTemp;          //highest temperature of a year
    const int NUM_MONTHS = 12;   //number of months
    Weather months[NUM_MONTHS];  //structure array of 12 months
    
    
    getData(months, NUM_MONTHS);
    calculateAvgRainfall(months, NUM_MONTHS);
    
    //demonstrating lowest temperature
    lowestTemp_Month(months, NUM_MONTHS, lowestTemp);
    
    //demonstrating highest temperature 
    highestTemp_Month(months, NUM_MONTHS, highestTemp);
    //calculate and print Average Temperature for a year
    cout <<"Average Temperature for the year "<<(highestTemp+lowestTemp)/2.0 
         <<" Degrees Fahrenheit" <<endl;
         
    //Exit the program
    return 0;
}

//get all weather statistic data by user
void getData(Weather months[], int size) {
    //loop to get the input for 12 months name, rainfall, low and high temperature
    for (int i=0; i<size; i++) {
        //enter the months 
        cin >> months[i].month;            //take input for month
        cin >> months[i].totalRainfall;    //take input for total rainfall
        cin >> months[i].lowTemp;          //take input for low temperature
        while(months[i].lowTemp < -100 || months[i].lowTemp > 140) { //checking input validation
            //enter the low temperature again
            cin >> months[i].lowTemp;
        }
        cin >> months[i].highTemp;         //take input for high temperature
        while(months[i].highTemp < -100 || months[i].highTemp > 140) { //checking input validation
            // //enter the high temperature again
            cin >> months[i].highTemp;
        }
        
        
    }
}
//average rainfall of a year in inches
void calculateAvgRainfall(Weather months[], int size) {
    float totalRain;            //hold the total rainfall of a year
    float avgRainfall;          //average rainfall of a year
    for (int i=0; i<size; i++) {
        totalRain += months[i].totalRainfall;       //adding total rainfall in a year
    }
    
    avgRainfall = totalRain / 12.0;                                   //calculate average rainfall of a year
    cout << fixed << setprecision(1);                                //display output formatting
    cout<<"Average Rainfall "<<avgRainfall<<" inches/month" <<endl;  //display average rainfall of a year
    
}
//get lowest temperature and month of a year
void lowestTemp_Month (Weather months[], int size, float& lowestTemp) {
    string lowestMonth;          //lowest temperature month
    lowestTemp = months[0].lowTemp;
    for (int i = 0; i < size; i++) {
        if (lowestTemp >= months[i].lowTemp) {
            lowestTemp = months[i].lowTemp;
            lowestMonth = months[i].month;
        }
    }
    cout << fixed << setprecision(0);
    cout<<"Lowest  Temperature "<<lowestMonth<< "  "                  //display Lowest  Temperature and month of a year
        <<lowestTemp<<" Degrees Fahrenheit" << endl;
}
//get high temperature and month of a year
void highestTemp_Month (Weather months[], int size, float &highestTemp) {
    
    string highestMonth;         //high temperature month
    highestTemp = months[0].highTemp; //set highest temp.
    //loop to find highest temperature and month
    for (int i = 0; i < size; i++) {
        if (highestTemp <= months[i].highTemp) {
            highestTemp = months[i].highTemp;
            highestMonth = months[i].month;
        }
    }
     cout<<"Highest Temperature "<<highestMonth<<"  "                 //display highest  Temperature and month of a year
        <<highestTemp<<" Degrees Fahrenheit" << endl;
}
