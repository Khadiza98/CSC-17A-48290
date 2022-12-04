/* 
 * File:   Essay.cpp
 * Author: Khadiza Akter
 * Created on November 9, 2022, 8:07 PM
 * Purpose: Essay class specification
 */

#ifndef ESSAY_H
#define ESSAY_H
#include "GradedActivity.h"

class Essay:public GradedActivity {
    private:
        float grammar; //holds points of grammar
        float spelling; //holds points for spelling
        float content; //holds points for content
        float correctLength; ////holds points for correct Length
    public:
        //constructor
        Essay():GradedActivity() {
            grammar = 0.0;
            spelling = 0.0;
            content = 0.0;
            correctLength = 0.0;
        }
        //constructor
        Essay(float gram, float spell, float content, float cLength) {
            set(gram, spell, content, cLength);
        }
        void set(float, float , float, float); //defined in Essay.cpp file
        //accessor function
        float getGrammar() const {return grammar;}
        float getSpelling() const {return spelling;}
        float getContent() const {return content;}
        float getCorrectLength() const {return correctLength;}
};
#endif /* ESSAY_H */

