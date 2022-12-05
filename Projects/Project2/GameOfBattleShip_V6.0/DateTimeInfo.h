/* 
 * File:   DateTimeInfo.h
 * Author: Khadiza Akter
 * Created on November 29, 2022, 8:24 PM
 * Purpose: Specification file of DateTimeInfo template class
 */

#ifndef DATETIMEINFO_H
#define DATETIMEINFO_H
#include<string>
using namespace std;

// Declare a Template class for date time information of game
template <class T>
class DateTimeInfo {  
    private:
        T dateOfPlay;      // Playing date
        T startTimeOfPlay; // Starting time of play
        T endTimeOfPlay;   // Ending time of play
    public:
        T getDateOfPlay() const { return dateOfPlay; } // Return the date of play
        void setDateOfPlay(T dPlay) { dateOfPlay = dPlay; }
        T getStartTimePlay() const { return startTimeOfPlay; } // Return the date of play
        void setStartTimePlay(T sPlay) { startTimeOfPlay = sPlay; }
        T getEndTimeOfPlay() const { return endTimeOfPlay; } // Return the date of play
        void setEndTimeOfPlay(T ePlay) { endTimeOfPlay = ePlay; }

};

#endif /* DATETIMEINFO_H */

