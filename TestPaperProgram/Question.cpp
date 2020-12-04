//Question.cpp
#include <iostream>
#include "Question.h"
#include <QString>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
using namespace std;

Question::Question()
{  
    //initializaing data memebers
    mQuestionType = QuestionType::ShortAnswer;
    mAnswers = new QVector<Answer *>();
}

Question::~Question()
{
    //nothing much to do on terms of cleanup
}

void Question::setQuestionText(QString question)
{
    mQuestion = question;
}

void Question::setQuestionType(QuestionType questionType)
{
    mQuestionType = questionType;
}

void Question::addAnswerToList(Answer* answer)
{
    mAnswers->push_back(answer);
};

QVector<Answer*> *Question::getAllAnswers()
{
    return mAnswers;
};

QString Question::getQuestionText()
{
    return mQuestion;
}

QuestionType Question::getQuestionType()
{
    return mQuestionType;
};

class SimpleAnswerQuestion : public Question
{ 
    SimpleAnswerQuestion()
    {
      this->setQuestionType(QuestionType::ShortAnswer);
    }
}; 

class MultipleAnswerQuestion : public Question
{
    MultipleAnswerQuestion ()
    {
      this->setQuestionType(QuestionType::MultiplyChoices);
    }
}; 


void Question::setQuestionId(int questionId)
{
    m_questionId = questionId;
}
int Question::getQuestionId( )
{
    return m_questionId;
}

//serialization
void Question::read(const QJsonObject &jsonObj)
{
    this->setQuestionText(jsonObj["question"].toString());
    this->setQuestionType(QuestionType(qRound(jsonObj["questionType"].toDouble())));
     // json encapsulates the QJsonArray
    QJsonArray jsonArray  = jsonObj["answers"].toArray();
    foreach(QJsonValue jsonAnswer, jsonArray)
    {
        Answer *a = new Answer();
        a->read(jsonAnswer.toObject());
        this->addAnswerToList(a);
    };
};

void Question::write(QJsonObject &jsonObj) const
{
    jsonObj["question"] = this->mQuestion;
    jsonObj["questionType"] = this->mQuestionType;
    QJsonArray jsonArray;
    QList<Answer*> list (this->mAnswers->begin(), this->mAnswers->end());
    foreach (Answer* a , list)
    {
        QJsonObject jsonAnswer;
        a->write(jsonAnswer);
        jsonArray.append(jsonAnswer);
    }
    jsonObj["answers"] = jsonArray;
};

