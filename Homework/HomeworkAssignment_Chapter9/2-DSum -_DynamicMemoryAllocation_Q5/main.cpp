/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/13/2022
 * Purpose: Demonstrates grand summation of 2D dynamic array
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
int **getData(int &,int &);              //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);            //De-allocate memory
int sum(const int * const *, int,int);   //Return the Sum

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int rows, cols, sumReturn = 0; //used to hold row, col and total sum of them
    int **data; //to point the number
    
    
    //Initialize Variables 
    cin >> rows >> cols; //input array size
    data = getData(rows, cols); //call function to get input of dynamic array
    prntDat(data, rows, cols);//call print function to print the array
    
    sumReturn = sum(data, rows, cols);//Return the Sum
    destroy(data, rows, cols); //De-allocate memory
    cout << sumReturn;
    
    
    
    //Exit the program
    return 0;
}
//Return the 2-D array and its size.
int **getData(int &rows,int &cols) {
    int i, j; //loop counter variable
    int **arr; //pointer to the array
    if(rows > 0 && cols > 0) {
        //Allocating the row space in heap dynamically
        arr = new int * [rows];
        //Allocating the column space in heap dynamically
        for (i = 0; i < rows; i++) {
          arr[i] = new int[cols];
        }
       //read into the array
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++){
                cin >> arr[i][j];
            }
        }
        return arr; //return pointer to the array
    }
    return nullptr; //return nullptr if rows and cols less than 0
}    

//Print the 2-D Array
void prntDat(const int* const *arr,int rows,int cols) {
    int i, j;//loop counter variable
    for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++){
                if (j != cols-1) {        //check for formatting the output with space or not
                    cout << arr[i][j] << " ";
                } else {
                    cout << arr[i][j];
                }
            }
            cout << endl;
    }
}
      
//Return the Sum
int sum(const int * const *arr, int rows,int cols) {
    
    int i, j, sum = 0; //loop counter and summation variable
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++){
            sum += arr[i][j];
        }    
    }
    return sum;
}   
//De-allocate memory
void destroy(int **array,int rows,int cols) {
  //Free the memory after the use of array
  for (int i = 0; i < rows; i++) {
    delete[] array[i];
  }
}
