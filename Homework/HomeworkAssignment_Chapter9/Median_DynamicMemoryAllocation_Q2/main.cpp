/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/16/2022
 * Purpose: Calculates the Median by creating a dynamic float array 2 larger in 
            size than the dynamic integer array.

 */
//System Level Libraries
#include <iostream> //input-output library
#include <cmath> //round()
#include <iomanip> //setprecision()
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
int *getData(int &);       //Return the array size and the array
void prntDat(int *,int);   //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *,int); //Print the median Array

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int num;               //used to hold the size of array
    int *data1 = nullptr;  //to point the numbers
    float *data2 = nullptr;//to point the numbers
    
    //Initialize Variables
    cin >> num;
    //Display the outputs and map the inputs/known to the outputs
    data1 = getData(num);
    prntDat(data1, num);
    
    data2 = median(data1, num);
    prntMed(data2, num+2);
    //free the memory
    delete []data1;
    delete []data2;
    //Exit the program
    return 0;
}
//Return the array size and the array
int *getData(int &num) {
    int i;                         //loop counter variable
    int *arr = nullptr;            //array to hold the numbers
    if (num > 0) {
        arr = new int[num];        //dynamically allocate the array
        //populate the array with number of inputs
        for(i = 0; i < num; i++) {
            cin >> *(arr+i);
        }
        return arr;                //return pointer to the array
    }
    return nullptr;                //return nullptr if num is 0 or less
}

//Print the integer array
void prntDat(int *array,int num) {
    for (int i = 0; i < num; i++) {
        if (i != (num-1)) cout << array[i] << " ";
        else              cout << array[i];
    }
    cout << endl;
}

//Fill the median Array with the Float array size, the median, and the integer array data
float *median(int *array,int num) {
    int i;                                //loop counter variable
    float median = 0.0f;                  //hold median 
    int evenPart;                         //hold one part of even median
    float *medianArr = nullptr;           //pointer to the array
    int fArrySize = num + 2;              //float array size
    if (fArrySize > 0 && num > 0) {
        medianArr = new float[fArrySize]; //dynamically allocate the array
        
        if (num % 2 != 0) {               //check the number of element odd
            median = round(num / 2.00);   //if num is odd then need to round up such as,num is 5, median = 3
        } else {
            evenPart = (num / 2.00);
            median = (array[evenPart]+array[evenPart-1]) / 2.00;
        }
        
        //Fill the median Array with the Float array size, median, and the integer array
        for (i = 0; i < fArrySize; i++) {
            if (i == 0){
                medianArr[i] = fArrySize;
            }else if (i == 1) {
                medianArr[i] = median;
            }
            else {
                medianArr[i] = array[i - 2];
            }
        }
        
       return  medianArr;                  //return pointer to the array
    }
    return nullptr;                        //return nullptr if num is 0 or less
}

//Print the median Array
void prntMed(float *array, int num) {
    int i = 0; //loop counter variable
    for (i = 0; i < num; i++) { //loop through the size of array
        if (i == 0) {
            cout << array[i] << " "; //print element without 2 decimal place
        } else{    
            cout << fixed << setprecision(2);
            if(i != num-1) {
                cout << array[i] << " "; //print element with 2 decimal place, and space until the last element
            } else {
                cout << array[i]; //print the last position element
            }
            
        }
    }
}
