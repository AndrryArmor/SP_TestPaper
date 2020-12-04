#include <iostream>
#include "Quiz.h"
#include <QJsonArray>
using namespace std;

Quiz::Quiz()
{
    //initializaing data memebers
     mQuestions = {};
}

Quiz::~Quiz()
{
    //nothing much to do on terms of cleanup
}

void Quiz::addQuestionToList(Question question)
{
    mQuestions.push_back(&question);
};

QVector<Question *> Quiz::getAllQuestions()
{
    return mQuestions;
};

void  Quiz::setQuizName(QString quizName)
{
    mQuizName = quizName;
};

QString Quiz::getQuizName()
{
    return mQuizName;
};

int Quiz::getQuizId()
{
    return mQuizId;
}

void  Quiz::setQuizId(int quiz_id)
{
    mQuizId = quiz_id;
}

//serialization
void Quiz::read(const QJsonObject &jsonObj)
{	
    this->setQuizName(jsonObj["name"].toString());
     // json encapsulates the QJsonArray
    QJsonArray jsonArray = jsonObj["questions"].toArray();
    foreach(QJsonValue jsonAnswer, jsonArray)
    {
        Question q;
        q.read(jsonAnswer.toObject());
        this->addQuestionToList(q);
    }
}

void Quiz::write(QJsonObject &jsonObj)
{
    jsonObj["name"] = this->getQuizName();
    QJsonArray jsonArray;
    foreach (Question* q, this->getAllQuestions())
    {
        QJsonObject jsonQuestion;
        q->write(jsonQuestion);
        jsonArray.append(jsonQuestion);
    }
    jsonObj["questions"] = jsonArray;
}
