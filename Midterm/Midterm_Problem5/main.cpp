/*
 * File:   main.cpp
 * Author: Khadiza Akter
 * Created on October 21, 2022, 12:58 PM
 * Purpose: Calculate factorial for largest number of different data types
            and print largest n, and number n factorial value.
 */
 //System Level Libraries
#include <iostream> //input-output library
using namespace std;

//Function Prototypes
unsigned short int calculateFactorialUSI(int); // calculate the factorial value for unsigned short int
signed short int calculateFactorialSSI(int); // calculate the factorial value for unsigned short int
unsigned int calculateFactorialUI(int); // calculate the factorial value for unsigned int
signed int calculateFactorialSI(int); // calculate the factorial value for signed int
unsigned long int calculateFactorialULI(int); // calculate the factorial value for unsigned long int
signed long int calculateFactorialSLI(int); // calculate the factorial value for signed long int
unsigned long long int calculateFactorialULLI(int); // calculate the factorial value for unsigned long long int
signed long long int calculateFactorialSLLI(int); //calculate the factorial value for signed long long int
float calculateFactorialF(int); // calculate the factorial value for float 
double calculateFactorialD(int); // calculate the factorial value for double
long double calculateFactorialLD(int); // calculate the factorial value for long double


//Execution begins here!
int main(int argc, char** argv) {
    //Display the output
    cout << "For \"singed byte           \" largest n is: 5, and n! is:  " 
         << 120 << endl;
    cout << "For \"unsigned byte         \" largest n is: 5, and n! is:  "
         << 120 << endl;
    cout << "For \"unsigned short int    \" largest n is: 8, and n! is:  "
         << calculateFactorialUSI(8) << endl;
    cout << "For \"signed short int      \" largest n is: 7, and n! is:  "
         << calculateFactorialSSI(7) << endl;
    cout << "For \"unsigned int          \" largest n is: 12, and n! is: "
         << calculateFactorialUI(12) << endl;
    cout << "For \"signed int            \" largest n is: 12, and n! is: "
         << calculateFactorialSI(12) << endl;
    cout << "For \"unsigned long int     \" largest n is: 12, and n! is: "
         << calculateFactorialULI(12) << endl;
    cout << "For \"signed long int       \" largest n is: 12, and n! is: "
         << calculateFactorialSLI(12) << endl;
    cout << "For \"unsigned long long int\" largest n is: 20, and n! is: "
         << calculateFactorialULLI(20) << endl;
    cout << "For \"signed long long int  \" largest n is: 20, and n! is: "
         << calculateFactorialSLLI(20) << endl;
    cout << fixed; // Avoid scientific number print for float, double and long double
    cout << "For \"float                 \" largest n is: 13, and n! is: "
        << calculateFactorialF(13) << endl;
    cout << "For \"double                \" largest n is: 22, and n! is: "
         << calculateFactorialD(22) << endl;
    cout << "For \"long double           \" largest n is: 22, and n! is: "
         << calculateFactorialLD(22) << endl;

    //Exit the program
    return 0;
}

//*****************************************************************
// Definition of function calculateFactorialUSI.Use int as @param                          
// Return the factorial value for unsigned short int                                          
//*****************************************************************
unsigned short int calculateFactorialUSI(int n) {
    unsigned short int factor = 1;
    for (int i = 1; i <= n; ++i) {              // Calculate factorial value
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialSSI.Use int as @param                          
// Return the factorial value for signed short int                                        
//*****************************************************************
signed short int calculateFactorialSSI(int n) {
    signed short int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialUI.Use int as @param                          
// Return the factorial value for unsigned int                                        
//*****************************************************************
unsigned int calculateFactorialUI(int n) {
    unsigned int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialSI.Use int as @param                          
// Return the factorial value for signed int                                        
//*****************************************************************
signed int calculateFactorialSI(int n) {
    signed int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialULI.Use int as @param                          
// Return the factorial value for unsigned long int                                       
//*****************************************************************
unsigned long int calculateFactorialULI(int n) {
    unsigned long int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialSLI.Use int as @param                          
// Return the factorial value for signed long int                                       
//*****************************************************************
signed long int calculateFactorialSLI(int n) {
    signed long int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialULLI.Use int as @param                          
// Return the factorial value for unsigned long long int                                       
//*****************************************************************
unsigned long long int calculateFactorialULLI(int n) {
    unsigned long long int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialSLLI.Use int as @param                          
// Return the factorial value for signed long long int                                       
//*****************************************************************
signed long long int calculateFactorialSLLI(int n) {
    signed long long int factor = 1;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialF,Use int as @param                          
// Return the factorial value for float                                      
//*****************************************************************
float calculateFactorialF(int n) {
    float factor = 1.0;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialD.Use int as @param                          
// Return the factorial value for double                                      
//*****************************************************************
double calculateFactorialD(int n) {
    double factor = 1.0;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}
//*****************************************************************
// Definition of function calculateFactorialLD.Use int as @param                          
// Return the factorial value for long double                                      
//*****************************************************************
long double calculateFactorialLD(int n) {
    long double factor = 1.0;
    for (int i = 1; i <= n; ++i) {
        factor *= i;
    }
    return factor;
}

