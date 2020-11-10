#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <list>
#include <QVector>
#include "Question.h"
using namespace std;

class Quiz
{
public:
    Quiz();
    ~Quiz();

    QVector<Question *> getAllQuestions();
    void setQuizName(string quizName);
    string  getQuizName();
    void addQuestionToList(Question* question);

private:
    QVector<Question *> mQuestions;
    string mQuizName;
};

#endif // QUIZ_H
