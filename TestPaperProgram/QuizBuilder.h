#ifndef QUIZBUILDER_H
#define QUIZBUILDER_H

#include <string>
#include "Quiz.h"
#include "Question.h"
#include <QString>
using namespace std;

class QuizBuilder
{
public:
    QuizBuilder();
    ~QuizBuilder();
    void SetQuizName(QString quizName);
    void AddQuestion(Question question);
    void Reset();
    Quiz* GetQuiz();
};

#endif // QUIZBUILDER_H
