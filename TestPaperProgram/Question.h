#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
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
    void setQuestionText(QString question);
    void setQuestionType(QuestionType questionType);
    QString getQuestionText();
    QuestionType getQuestionType();
    void addAnswerToList(Answer* answer);
    QVector<Answer*> *getAllAnswers();

private:
    QuestionType mQuestionType;
    QVector<Answer*> *mAnswers;
    QString mQuestion;
};

#endif // QUESTION_H
