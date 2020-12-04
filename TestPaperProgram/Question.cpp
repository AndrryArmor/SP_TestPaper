//Question.cpp
#include <iostream>
#include "Answer.h"
#include "Question.h"
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
