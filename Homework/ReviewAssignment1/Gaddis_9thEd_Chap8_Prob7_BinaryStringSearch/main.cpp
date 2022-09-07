/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on September 6, 2022, 1:00 AM
 * Purpose: Sorting array of string for binary search.
 */
//System Level Libraries
#include <iostream> //input-output library
#include <string> // to work with string
using namespace std;

//User Defined Libraries

//Global Constants, not Global Variables
//These are recognized constants from the sciences
//Physics/Chemistry/Engineering and Conversions between
//systems of units!

//Function Prototypes
void printOrginalArray(string[], int); //display the actual array element 
void bubbleSort(string[], int); //sort the array
void printSortedArray(string[], int); //display the sorted array
int binarySearch(string[], string, int); //search the position of userName


//Execution begins here!
int main(int argc, char** argv) {
//Initialize Random Seed once here!
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                               "Taylor, Terri", "Johnson, Jill", 
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                               "James, Jean", "Weaver, Jim", "Pore, Bob", 
                               "Rutherford, Greg", "Javens, Renee", 
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };
    //Declare Variables
    string userName;
    int position;
    
    
    //Map the inputs/known to the outputs
    
    ///print unsorted array
    printOrginalArray(names, NUM_NAMES); 
    //sort the array
    bubbleSort(names, NUM_NAMES);  
    //display sorted array
    printSortedArray(names, NUM_NAMES); 
    
    //Search for a name
    cout << "Enter a name to search: ";
    getline(cin, userName);
    position = binarySearch(names, userName, NUM_NAMES);
    
    //Display the result
    if (position != -1) {
        cout << "\nUsername is found at position " << position << endl;
    } else {
        cout << "Username is not found!!!" << endl;
    }
    //Exit the program
    return 0;
}

/*
 * This function print the unsorted array of string
 * @Param nameList where stores the unsorted elements, size of array
 * @Return none
 */
void printOrginalArray(string nameList[], int arraySize) {
    cout << "The elements of unsorted array are: " << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << i << " " << nameList[i] << endl;
    }
 
    cout << endl;
}
/*
 * This function sort the one dimensional array of string
 * @Param arrayNames where stores the elements, size of array
 * @Return none
 */
void bubbleSort(string arrayNames[], int size){
    string temp;
    for (int i = 0; i < size - 1; i++) {
        for (int index = 0; index < size - i - 1; index++) {
            if (arrayNames[index] > arrayNames[index + 1] ) {  //swap the value if condition satisfy

                temp = arrayNames[index];                      // store the current in temporary variable
                arrayNames[index] = arrayNames[index + 1];     // assign the index + 1 position value into the index position 
                arrayNames[index + 1] = temp;                  // assign the temp value into the index+1 position
            }
           
        }
    } 
}
/*
 * This function print the sorted array of string
 * @Param nameList where stores the elements of sorted array, size of array
 * @Return none
 */
void printSortedArray(string nameList[], int arraySize) {
    cout << "\nThe elements of sorted array are: " << endl;
    
    for (int i = 0; i < arraySize; i++) {
        cout << i << " " << nameList[i] << endl;
    }
    cout << endl;
}
/*
 * This function search a user value in a array through the binary search. 
 * @Param nameList where stores the elements of sorted array, userInput 
 * to search, size of array
 * @Return position of the search value(userInput)
 */
int binarySearch(string nameList[], string userInput, int arraySize) {
    int first = 0,
        last = arraySize - 1,
        middle,
        position = -1;
    bool found = false;
    while (!found && (first <= last) )
    {
        middle = (first + last) / 2;        //(0 + 19) / 2 = 8, for first search

        if (nameList[middle] == userInput)  //if userInput is in Middle
        {
            position = middle;
            found = true;
        }
        else if (nameList[middle] > userInput) //if userInput is in Lower Half
            last = middle - 1;  
        else                                   // if userInput is in Upper Half
            first = middle + 1;
        
    }
    return position;
    
}
