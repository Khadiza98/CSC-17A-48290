/* 
 * File:   Date.h
 * Author: Khadiza Akter
 * Created on November 2, 2022, 6:06 PM
 * Purpose: Class Car specification.
 */

#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car {
    private:
        int yearModel; //Hold the car's year model
        string make;  //Hold the make of car 
        int speed;    //Hold the current speed of car
        
    public:
        //constructor
        Car(int, string);
        // Accessor function
        int getYearModel() const {return yearModel;}
        string getCarMake() const {return make;}
        int getSpeed() const {return speed;}
        // mutator function
        void accelerator(); //Add 5 to the speed member each time it is called
        void brake(); //subtract 5 to the speed member each time it is called
        

};

#endif /* CAR_H */

