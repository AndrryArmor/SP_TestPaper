#include <iostream>
#include "Quiz.h"
using namespace std;

Quiz::Quiz()
{
    //initializaing data memebers
     mQuestions = new QVector<Question *>;
}

Quiz::~Quiz()
{
    //nothing much to do on terms of cleanup
}

void Quiz::addQuestionToList(Question* question)
{
    mQuestions->push_back(question);
};

QVector<Question *> *Quiz::getAllQuestions()
{
    return mQuestions;
};

void Quiz::setQuizName(QString quizName)
{
    mQuizName = quizName;
};

QString Quiz::getQuizName()
{
    return mQuizName;
};
