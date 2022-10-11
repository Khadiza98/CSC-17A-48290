/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created 9/22/2022
 * Purpose: demonstrates reading in a dynamic array.and output the reverse
 *          sorted dynamic array by sorting.
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
int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);     //Sort in reverse order
void prntDat(const int *,int);     //Print the array
//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int num;              //used to read the size of array
    int *data1 = nullptr; //pointer to the array
    int *data2 = nullptr; //pointer to the array
    int *data3 = nullptr; //pointer to the array
    
    
    //Initialize Variables and Map the inputs/known to the outputs
    cin >> num;           //read the size of array
    //Fill the array
    data1 = getData(num);
    //sort the array
    data2 = sort(data1, num);
    //Sort in reverse order
    data3 = reverse(data2, num);
    //Print the array
    prntDat(data2, num);
    cout << endl;
    prntDat(data3, num);
    
    //free the memory
    delete []data1;
    delete []data2;
    delete []data3;
    
    //Exit the program
    return 0;
}

//Fill the array
int *getData(int &num) {
    int i;  //loop counter variable
    int *arr = nullptr;
    if (num > 0) {
        arr = new int[num]; //allocate dynamic memory of array
        for (i = 0; i < num; i++) { //loop through the number of input
            cin >> arr[i]; //read in array
        }
        return arr;
    } else {
        return nullptr;
    }
} 
//Sort smallest to largest
int *sort(const int *array,int num) {
    int i, j;               //loop counter variable
    int temp;               //used to hold temporary value
    int *arr = nullptr;     //used to copy the array
    
    //converting constant int array into another int array/pointer
    if (num > 0) { //check condition is satisfy to do sort
        arr = new int[num]; //allocate dynamic memory of array
        for (int k=0; k<num; k++) {
            arr[k] = array[k]; //copy the array to arr pointer
        }
        
        //sorting the array
        for (i = 0; i<num-1; i++) { 
            for (j = i+1; j<num; j++){
                if(arr[i]>arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
                
            }
            
        }
        return arr; //return pointer to the array
        
    } else { 
        return nullptr; //return nullptr if condition not satisfy
    }
}
//Sort in reverse order
int *reverse(const int *array,int num) {
    int *arr = nullptr; //point to int value
    int count = 0;      //counter variable for dynamic array/pointer
    if (num > 0) {
        arr = new int[num];
        for (int i = num-1; i >= 0; i--) {
            arr[count] = array[i];
            count++;
        }
        return arr;
    }
    return nullptr;
} 
//Print the array
void prntDat(const int *array,int num) {
    for (int i = 0; i < num; i++) {
        if (i != (num-1)) {
            cout << array[i] << " "; 
        } else {
            cout << array[i];
        }
        
    }
}

