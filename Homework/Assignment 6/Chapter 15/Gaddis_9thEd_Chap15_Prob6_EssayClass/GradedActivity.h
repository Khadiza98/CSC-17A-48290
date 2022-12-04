/* 
 * File:   Essay.cpp
 * Author: Khadiza Akter
 * Created on November 9, 2022, 8:07 PM
 * Purpose: GradedActivity class specification
 */

#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity {
    private:
        float score; //holds the numeric score of test
    public:
        //constructor
        GradedActivity() {
            score = 0.0f;
        }
        //constructor, accept an argument for the score member
        GradedActivity(float score){this->score = score;}
        void setScore(float s) {score = s;} //mutator function set score
        float getScore() const {return score;} //accessor function return score
        char getLetterGrade() const;
        
};

#endif /* GRADEDACTIVITY_H */

