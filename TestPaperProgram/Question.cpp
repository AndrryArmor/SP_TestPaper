//Question.cpp
#include <iostream>
#include "Answer.h"
#include "Question.h"
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

void Question::setQuestionText(string question)
{
    mQuestion = question;
}

void Question::setQuestionType(QuestionType questionType)
{
    mQuestionType = questionType;
}

void Question::addAnswerToList(Answer answer)
{
    mAnswers.push_back(answer);
};

list<Answer> Question::getAllAnswers()
{
    return mAnswers;
};

string Question::getQuestionText()
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
