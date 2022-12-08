/* 
 * File:   AbsDateTime.h
 * Author: Khadiza Akter
 * Created on December 5, 2022, 6:46 PM
 * Purpose: Abstract DateTime Class Specification
 */

#ifndef ABSDATETIME_H
#define ABSDATETIME_H
#include <string>
using namespace std;

class AbsDateTime {
    public:
        virtual string currentTime()=0;
        virtual string currentDate()=0;

};

#endif /* ABSDATETIME_H */

