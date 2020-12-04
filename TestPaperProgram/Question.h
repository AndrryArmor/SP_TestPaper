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
    void setQuestionId(int questionId);
    int getQuestionId( );

private:
    QuestionType mQuestionType;
    QVector<Answer*> *mAnswers;
    QString mQuestion;
    int m_questionId;
};

#endif // QUESTION_H
