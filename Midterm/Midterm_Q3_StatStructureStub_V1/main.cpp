/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Driver program to test out the statistics problem.
 */

//Libraries
#include <iostream>//I/O
using namespace std;

//User Libraries
#include "Array.h"
#include "Stats.h"

//No Global Constants

//Function Prototypes I supply
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure

//Functions you are to supply
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure

//Execution begins here
int main(int argc, char*argv[]) {
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right
    return 0;
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"Stat function to be completed by the student"<<endl;
 
    Stats *stats=new Stats;                 //Dynamically allocate the structure variable                     
    int count[array->size] = {0};           //static array to count the frequency of mode number, initialized with default value
    int tempModeSet[array->size] = {0};     //static temporary array to hold the set of mode number                
    bool countCheck[array->size];           // counter check array to track a value already counted or not
    
    //Find the max Frequency
    //loop through the sorted array to count the frequency of mode number
    for(int i=0;i<array->size;i++){ 
      countCheck[i] = false;                // set count check as false for each value
   }
   for(int i=0; i<array->size; i++){        // count the frequency of the array
      if(countCheck[i]== true){             // do not count once already check
         continue;
      }
      int cnt = 1;
      for(int j = i+1; j<array->size; j++){ // nested loop for checking the count increment
         if (array->data[i] == array->data[j]){         // check if value equal
            countCheck[j] = true;       // set true that already consider for counting
            cnt++;                      // increase the count
         }
      }
      count[i] = cnt;                   // set the count
    }
    
    stats->modFreq = 0;//used to store mode frequency
    for(int i = 0; i < array->size; i++) {  // find the maxFrequency
        if(count[i] > stats->modFreq) {
            stats->modFreq = count[i];
        }
    }
    //average of the array
    stats->avg = 0;
    float total = 0.0f; //to hold the summation of the elements of array
    for (int i = 0; i < array->size; i++) {
        total += array->data[i];
    }
    stats->avg = (total / array->size); //calculate the average of the array and store to the structure member
    
   //find the median of the array
    stats->median=0;                      //hold median
    int evenPart;                         //hold even part of median
    int oddPart;                          //hold odd part of median
    if ( array->size > 0) {
        
        if (array->size % 2 != 0) {         //check the number of elements odd
            oddPart = array->size / 2.00;   
            stats->median = array->data[oddPart];        
        } else {                            //when number of elements even
            evenPart = (array->size / 2.00);
            stats->median = (array->data[evenPart]+array->data[evenPart-1]) / 2.00;
        }
    }
    
    //Find the number of modes and set the modes to modeSet array
    int j = 0;
    int nModes=0;
    for(int i = 0; i < array->size; i++) {
        if (count[i] == stats->modFreq && count[i] >= 2) {  // if count is equal to maxFrequency and more than two
           nModes ++;                                       // increase the mode
            tempModeSet[j] = array->data[i];                // add the value to the temporary mode array
                    j++;
        }
    }
   
    stats->mode=new Array; //Dynamically allocate array
    stats->mode->size=0;   //point to the size of array
    
    if(nModes!=0)stats->mode->data=new int[nModes];//Dynamically allocated memory of array
    stats->mode->size = nModes; //set number of modes to mode->size
    
    //Fill the mode array and loop through the number of modes
    for(int k = 0; k < nModes; k++) {
            stats->mode->data[k] = tempModeSet[k]; // store elements of temporary mode array to the mode array 
    }
    
    return stats; //return structure
   
}