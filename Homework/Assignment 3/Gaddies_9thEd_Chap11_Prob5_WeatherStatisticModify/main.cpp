/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/21/2022
 * Purpose: displaying and calculating weather data using structure variable and
 *          enum data type
 */
 //System Level Libraries
#include <iostream> //input-output library
#include <iomanip> //setprecision()
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!
//structure declare
struct Weather {

    float totalRainfall, //total rainfall in inches
        highTemp,      //highest temperature in Degrees Fahrenheit
        lowTemp,       //lowest temperature in Degrees Fahrenheit
        avgTemp;       //average temperature

};
enum Month { January, February, March, April, May, June };

//Function Prototypes

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables and constant
    float lowestTemp = 0.0f;           //lowest temperature initialized with default value
    float highestTemp = 0.0f;          //highest temperature in Degrees Fahrenheit initialized with default value
    float totaRain = 0.0f;             //used to hold total rainfall of months initialized with default value
    float avgRainfall = 0.0f;          //used to store average rainfall initialized with default value
    float totalHigh = 0.0f;            //add total high temperature initialized with default value
    float totalLow = 0.0f;             //add total low temperature initialized with default value
    const int NUM_MONTHS = 6;          //number of months
    Weather months[NUM_MONTHS];        // array of structure
    int count;                         //loop counter variable


    //loop to get the input for 12 months name, rainfall, low and high temperature
    for (count = January; count <= June; count = count + 1) {

        cout << "Enter the total rainfall for the month:" << endl;
        cin >> months[count].totalRainfall;    //take input for total rainfall

        cout << "Enter the high temp:" << endl;
        cin >> months[count].highTemp;         //take input for high temperature
        //checking input validation
        while (months[count].highTemp < -100 || months[count].highTemp > 140) {
            //enter the high temperature again
            cin >> months[count].highTemp;
        }

        totalHigh += months[count].highTemp; //calculate total high temperature

        cout << "Enter the low temp:" << endl;
        cin >> months[count].lowTemp;          //take input for low temperature
        //checking input validation
        while (months[count].lowTemp < -100 || months[count].lowTemp > 140) {
            //enter the low temperature again
            cin >> months[count].lowTemp;
        }
        totalLow += months[count].lowTemp;   //calculate total low temperature;

        totaRain += months[count].totalRainfall; //adding total rainfall of months
    }

    cout << fixed << setprecision(2);                                //display output formating
    avgRainfall = totaRain / NUM_MONTHS;                             //calculate average rainfall
    cout << "Average monthly rainfall:" << avgRainfall << endl;            //display average rainfall

    //demonstrating highest temperature 
    highestTemp = months[0].highTemp; //set highest temp.
    for (count = January; count <= June; count = count + 1) {
        if (highestTemp <= months[count].highTemp) {
            highestTemp = months[count].highTemp;
        }
    }
    cout << fixed << setprecision(0);
    cout << "High Temp:" << highestTemp << endl;                //display highest Temperature


    //demonstrating lowest temperature
    lowestTemp = months[0].lowTemp;
    for (count = January; count <= June; count = count + 1) {
        if (lowestTemp >= months[count].lowTemp) {
            lowestTemp = months[count].lowTemp;
        }
    }

    cout << "Low Temp:" << lowestTemp << endl;             //display Lowest Temperature


    cout << fixed << setprecision(1);
    cout << "Average Temp:" << (totalHigh + totalLow) / 12.0; //calculate and print Average Temperature

    //Exit the program
    return 0;
}
