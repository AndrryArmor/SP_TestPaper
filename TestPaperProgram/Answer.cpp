//Answer.cpp
#include <iostream>
#include <QString>
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

void Answer::setAnswerText(QString answerText)
{
    mAnswerText = answerText;
};

void Answer::setAnswerState(AnswerState answerState)
{
    mAnswerState = answerState;
};

QString Answer::getAnswerText()
{
    return mAnswerText;
};

AnswerState Answer::getAnswerState()
{
    return mAnswerState;
};

void Answer::setAnswerId( int anwerId)
{
    m_answer_id = anwerId;
}
int Answer::getAnswerId()
{
    return m_answer_id ;
}

