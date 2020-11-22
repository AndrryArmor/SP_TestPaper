#include <iostream>
#include "Quiz.h"
#include <QJsonArray>

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


//serialization
void Quiz::read(const QJsonObject &jsonObj)
{

    this->setQuizName(jsonObj["name"].toString());
     // json encapsulates the QJsonArray
    QJsonArray jsonArray = jsonObj["questions"].toArray();
    // json encapsulates the QJsonArray

    foreach(QJsonValue jsonAnswer, jsonArray)
    {
        Question q;
        q.read(jsonAnswer.toObject());
        this->addQuestionToList(&q);
    }
}

void Quiz::write(QJsonObject &jsonObj) const
{
    jsonObj["name"] = this->mQuizName;
    QJsonArray jsonArray;

    QList<Question*> list (this->mQuestions->begin(), this->mQuestions->end());
    foreach (Question *q, list)
    {
        QJsonObject jsonQuestion;
        q->write(jsonQuestion);
        jsonArray.append(jsonQuestion);
    }
    jsonObj["questions"] = jsonArray;
}

