/* 
 * File:   DateTimeInfo.h
 * Author: Khadiza Akter
 * Created on December 5, 2022, 7:08 PM
 * Purpose: Specification of DateTimeInfo template class
 */

#ifndef DATETIMEINFO_H
#define DATETIMEINFO_H

template <class T>
class DateTimeInfo {   // Declare a class for date time information of game
private:
    T dateOfPlay;      // Playing date
    T startTimeOfPlay; // Starting time of play
    T endTimeOfPlay;   // Ending time of play
public:
    //Mutator functions
    void setDateOfPlay(T dPlay) { dateOfPlay = dPlay; }
    void setStartTimePlay(T sPlay) { startTimeOfPlay = sPlay; }
    void setEndTimeOfPlay(T ePlay) { endTimeOfPlay = ePlay; }
    //Accessor functions
    T getDateOfPlay() const { return dateOfPlay; } // Return the date of play
    T getStartTimePlay() const { return startTimeOfPlay; } // Return the date of play
    T getEndTimeOfPlay() const { return endTimeOfPlay; } // Return the date of play

};

#endif /* DATETIMEINFO_H */

