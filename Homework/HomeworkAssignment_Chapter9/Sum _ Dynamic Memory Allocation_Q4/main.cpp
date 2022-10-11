/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/13/2022
 * Purpose: Demonstrates summation of dynamic array
 */
//System Level Libraries
#include <iostream> //input-output library
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
int *getData(int &);//Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array
//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int num;
    int *data = nullptr; //to point the number
    int *data1 = nullptr;//to point the number
    
    //Initialize Variables and Map the inputs/known to the outputs
    
    cin >> num; //input array size
    data = getData(num); //call function to get input of dynamic array
    data1 = sumAry(data, num);//call function to get summation of dynamic array
    
    //Display the outputs
    prntAry(data, num); //call print function to print the array
    cout << endl;  
    prntAry(data1, num);//call print function to print the summation array
    
    //free the memory
    delete []data;
    delete []data1;
    //Exit the program
    return 0;
}
//Return the array size and the array from the inputs
int *getData(int &num) {
    int *arrPtr = nullptr;              //pointer to the array
    
    if (num > 0) {
        arrPtr = new int[num];          //dynamically allocate the array
        
        //populate the array with input
        for (int i = 0; i < num; i++) { 
            cin >> arrPtr[i];           
        }
        return arrPtr;                  //return pointer to the array
    } else {
        return nullptr;                 //return nullptr if num is 0 or less
    }
}
//Return the array with successive sums
int *sumAry(const int *data,int num) {
    int sumOfint  = 0;    //used to hold the sum of array
   int *sumPtr = nullptr; //pointer to the array
    
    if (num > 0) {
        sumPtr = new int[num];//dynamically allocate the array
        //populate summation array with the sum of array's element
        for (int i = 0; i < num; i++) {
            sumOfint += data[i];
            sumPtr[i] = sumOfint;
        }
        
        return sumPtr; //return pointer to the array
    } else {
        
        return nullptr; //return nullptr if num is 0 or less
    }
}
//Print the array
void prntAry(const int *array,int num) {
    //loop through the num to print the array element
    for (int i = 0; i < num; i++) {
        if (i != (num-1)) {
            cout << array[i] << " "; 
        } else {
            cout << array[i];
        }
        
    }
}

