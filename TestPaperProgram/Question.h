#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <QVector>
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
    void addAnswerToList(Answer* answer);
    QVector<Answer*> *getAllAnswers();

private:
    QuestionType mQuestionType;
    QVector<Answer*> *mAnswers;
    string mQuestion;
};

#endif // QUESTION_H
