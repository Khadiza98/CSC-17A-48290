/* 
 * File:   Car.cpp
 * Author: Khadiza Akter
 * Created on November 2, 2022, 6:03 PM
 * Purpose: Class Car implementation
 */

#include "Car.h"
#include <string>
using namespace std;


//**********************************************
//Definition of Car. This is a constructor,
//accept argument for yearModel, and make.
//**********************************************
Car::Car(int yModel, string mk) {
    yearModel = yModel;
    make = mk;
    speed = 0;
}
//**********************************************
//Definition of accelerator. This function add
//5 to the speed member each time it is called.
//**********************************************
void Car::accelerator() {
    speed += 5;
}
//**********************************************
//Definition of brake. This function subtract
//5 to the speed member each time it is called.
//**********************************************
void Car::brake() {
    if (speed > 0) speed -= 5;
    
}


