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
    mAnswers = {};
}

Question::~Question()
{
    //nothing much to do on terms of cleanup
}

void Question::setQuestionText(QString question)
{
    mQuestionText = question;
};

void Question::setQuestionType(QuestionType questionType)
{
    mQuestionType = questionType;
};

void Question::addAnswerToList(Answer *answer)
{
    mAnswers.push_back(answer);
};

QString  Question::getQuestionText()
{
    return mQuestionText;
};

QVector<Answer*> Question::getAllAnswers()
{
    return mAnswers;
};



QuestionType Question::getQuestionType()
{
    return mQuestionType;
};

//serialization
void Question::read(const QJsonObject &jsonObj)
{

    this->setQuestionText(jsonObj["question"].toString());
    this->setQuestionType(QuestionType(qRound(jsonObj["questionType"].toDouble())));
     // json encapsulates the QJsonArray
    QJsonArray jsonArray  = jsonObj["answers"].toArray();
    foreach(QJsonValue jsonAnswer, jsonArray)
    {
        Answer* a;
        a->read(jsonAnswer.toObject());
        this->addAnswerToList(a);
    };
};

void Question::write(QJsonObject &jsonObj)
{
    jsonObj["question"] = this->mQuestionText;
    jsonObj["questionType"] = this->mQuestionType;
    QJsonArray jsonArray;
    foreach (Answer* a , this->getAllAnswers())
    {
        QJsonObject jsonAnswer;
        a->write(jsonAnswer);
        jsonArray.append(jsonAnswer);
    }
    jsonObj["answers"] = jsonArray;
};

/*class SimpleAnswerQuestion : public Question
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
*/
