/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 9/14/2022
 * Purpose:  Create a 2-D array 1 row and 1 column larger than the array to copy
             with 0's in the 1st row and column but filled with the other rows 
             and columns using the original array.
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
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

//Execution begins here!
int main(int argc, char** argv) {
    //Declare Variables
    int rows, cols;//used to hold number of rows, and cols
    int **numbers; //to point the number
    int **numbers_2; //to point the number
    
    //Initialize Variables
    cin >> rows >> cols;
    //Get the Matrix Data
    numbers = getData(rows, cols);
    //Augment the original array
    numbers_2 = augment(numbers, rows, cols);
    
    //Print the Matrix
    printDat(numbers, rows, cols);
    cout << endl;
    printDat(numbers_2, rows+1, cols+1);
    //Destroy the Matrix, i.e., reallocate memory
    destroy(numbers, rows);
    destroy(numbers_2, rows+1);
    
    //Exit the program
    return 0;
}

//Get the Matrix Data
int **getData(int &rows,int &cols) {
    int i, j; //loop counter variable
    int **arr; //array to hold the numbers
    if (rows > 0 && cols > 0) {
        arr = new int*[rows]; //Allocating the row space in heap dynamically
        //Allocating the column space in heap dynamically
        for(i = 0; i < rows; i++){
            arr[i] = new int[cols];
        }
        //populate the 2d array with numbers
        for(i = 0; i < rows; i++) {
           for(j = 0; j < cols; j++) {
               cin >> arr[i][j];
           }
        }
        return arr; //return pointer to the array
    }
    return nullptr; //return nullptr if rows and cols 0 or less than
}

//Augment the original array
int **augment(const int * const *array,int rows,int cols) {
    int i,j;//loop counter variable
    int **augarr;//pointer to the array
    
    if (rows > 0 && cols > 0) {
        //Allocating the row space in heap dynamically
        augarr = new int * [rows+1];
        //Allocating the column space in heap dynamically
        for (i = 0; i < rows+1; i++) {
          augarr[i] = new int[cols+1];
        }
        //populate augment array with the 0 for 1st row and cols, but filled  
        //   with the other rows  and columns using the original array
        for (i = 0; i <= rows; i++) {
            for(j = 0; j <= cols; j++) {
                if(i == 0 || j == 0){
                    augarr[i][j] = 0;
                }else {
                    augarr[i][j] = array[i-1][j-1];
                }
                
            }
            
        }
        return augarr; //return pointer to the array
    }
    return nullptr; //return nullptr if rows and cols 0 or less than
}

//Print the Matrix
void printDat(const int * const *arr,int rows,int cols){
    int i, j;//loop counter variable
    for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++){
                if (j != cols-1) {        //check for formatting the output with space or not
                    cout << arr[i][j] << " ";
                } else {
                    cout << arr[i][j];
                }
            }
            if(i < rows-1) cout << endl;
    }
}

//Destroy the Matrix, i.e., reallocate memory
void destroy(int **array,int rows) {
  //Free the memory after the use of array
  for (int i = 0; i < rows; i++) {
    delete[] array[i];
  }
}


