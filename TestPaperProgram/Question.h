#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <list>
#include "Answer.h"
using namespace std;

enum QuestionType
{
    ShortAnswer,
    MultiplyChoices
};

class Question
{
public:
    Question();
    ~Question();
    void setQuestionText(string question);
    void setQuestionType(QuestionType questionType);
    string getQuestionText();
    QuestionType getQuestionType();
    void addAnswerToList(Answer answer);
    list<Answer> getAllAnswers();

private:
    QuestionType mQuestionType;
    list<Answer> mAnswers;
    string mQuestion;
};

#endif // QUESTION_H
