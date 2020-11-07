//Answer.cpp
#include <iostream>
#include "Answer.h"
using namespace std;

Answer::Answer()
{
    //initializaing data memebers
     mAnswerState = Correct;
}

Answer::~Answer()
{
    //nothing much to do on terms of cleanup
}

void Answer::setAnswerText(string answerText)
{
    mAnswerText = answerText;
};

void Answer::setAnswerState(AnswerState answerState)
{
    mAnswerState = answerState;
};

string Answer::getAnswerText()
{
    return mAnswerText;
};

AnswerState Answer::getAnswerState()
{
    return mAnswerState;
};
