/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/16/2022
 * Purpose: stimulates Augment a 1-D array by 1 Element, place 0 in the first
 *          element and copy the rest from the original shifted by 1 index.
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
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int num;             //hold the number of arry size
    int *data = nullptr; //to point the number
    int *data1 = nullptr;//to point the number
    
    //Initialize Variables and Map the inputs/known to the outputs
    cin >> num; //input array size
    data = getData(num); //call function to get input of dynamic array
    data1 = augment(data, num);//call function to get summation of dynamic array
    
    //Display the outputs
    prntAry(data, num); //call print function to print the array
    cout << endl;  
    prntAry(data1, num + 1);//call print function to print the summation array
    
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

//Augment and copy the original array
int *augment(const int *array,int num) {
    
    int *augPtr = nullptr;              //pointer to the array
    if (num > 0) {
        augPtr = new int[num + 1];      //dynamically allocate the array
        
        //populate the augment array with numbers
        augPtr[0] = 0;
        for(int i = 1; i <= num; i++) {
            *(augPtr + i) = array[i-1];
        }
        return augPtr;                  //return pointer to the array
    } else {
        return nullptr;                 //return nullptr if num is 0 or less
    }
}
//print the array
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


