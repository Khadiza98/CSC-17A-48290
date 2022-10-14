/* 
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on 10/10/2022
 * Purpose:  Compare 1 and 2 Dimensional vectors
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions and Array Dimension


//Function Prototypes Here
void prntVec(const vector<int> &,int);//print 1D vector
void prntVec(const vector< vector<int> > &,int,int);//print 2D vector
void fillVec(vector<int> &,int,int); //fill the 1D vector
void fillVec(vector< vector<int> > &,int,int);//fill the 2D vector
void fillVec(vector< vector<int> > &,vector<int> &,int,int);//fill the 1D and 2D vector
void swap(int &,int &);
void smlLst(vector<int> &,int); 
void mrkSort(vector<int> &); //sort the vector element

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize=4;//Row size for both 1 and 2D vector
    int colsize=3;//The column size for a 2 dimensional vector
    vector<int>aVector(rowsize);
    vector<int>bVector(rowsize);
    vector<int>cVector(rowsize);
    vector< vector<int>> table(rowsize, vector<int> (colsize));
    int lowRng=100,highRng=999;
    int perLine=4;
        
    //Fill each parallel vector
    fillVec(aVector,highRng,lowRng);
    fillVec(bVector,highRng/10,lowRng/10);
    fillVec(cVector,highRng/100,lowRng/100);
    
    //Sort the vector the for all positions
    mrkSort(aVector);
    mrkSort(bVector);
    mrkSort(cVector);
    
    //Fill the 2-D vector
    fillVec(table,rowsize,colsize);
    fillVec(table,aVector,rowsize,0);
    fillVec(table,bVector,rowsize,1);
    fillVec(table,cVector,rowsize,2);
    
    //Print the values in the array
    prntVec(aVector,perLine);
    prntVec(bVector,perLine);
    prntVec(cVector,perLine);
    prntVec(table,rowsize,colsize);
    

    //Exit
    return 0;
}

//****************************************************************
//Definition of function fillVec                                 *
//This function fill 2D vector with the 1D vector element        *
//****************************************************************
void fillVec(vector< vector<int> > &a,vector<int> &c,int rowSize,int wchCol){
    for(int row=0;row<rowSize;row++){
        a[row][wchCol]=c[row];
    }
}

//****************************************************************
//Definition of function fillVec                                 *
//This function fill 1D vector with random value                 *
//****************************************************************
void fillVec(vector<int> &a,int hr,int lr){
    for(int indx=0;indx<a.size();indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}
//****************************************************************
//Definition of function fillVec                                 *
//This function fill 2D vector with 0's                          *
//****************************************************************
void fillVec(vector< vector<int> > &a,int rows,int cols){
    //Fill it with 0's
    for(int row=0;row<rows;row++){
        for(int col=0;col<cols;col++){
            a[row][col]=0;
        }
    }
}
//****************************************************************
//Definition of function prntVec                                 *
//This function print 2D vector values in right format           *
//argument pass by reference but const since need to only display*
//****************************************************************
void prntVec(const vector< vector<int> > &a,int rowsize,int colsize){
     cout<<endl<<"The Vector Values"<<endl;
    for(int row=0;row<rowsize;row++){
        for(int col=0;col<colsize;col++){
            cout<<setw(4)<<a[row][col];
        }
        cout<<endl;
    }
}
//****************************************************************
//Definition of function prntVec                                 *
//This function print 1D vector values in right format           *
//argument pass by reference but const since need to only display*
//****************************************************************
void prntVec(const vector<int> &a,int perLine){
    //Print the values in the array
    cout<<endl<<"The Vector Values"<<endl;
    for(int indx=0;indx<a.size();indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}
//****************************************************************
//Definition of function mrkSort                                 *
//This function sort 1D vector values in ascending order         *
//call other function smlLst()inside to sort the vector          * 
//argument pass by reference since need to change the values     *
//****************************************************************
void mrkSort(vector<int> &a){
    for(int pos=0;pos<a.size()-1;pos++){
        smlLst(a,pos);
    }
}
//**********************************************************************
//Definition of function smlLst                                        *
//This function help to sort 1D vector values from smallest to largest *
//**********************************************************************
void smlLst(vector<int> &a,int pos){
    for(int i=pos+1;i<a.size();i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}
//***********************************************************************
//Definition of function swap                                           *
//This function helps to sort 1D vector by swapping one value to another*
//***********************************************************************
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}