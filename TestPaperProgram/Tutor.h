#ifndef TUTOR_H
#define TUTOR_H

#include <QString>
#include <list>
#include "QuizBuilder.h"
#include "Question.h"
#include "TestQuizBuilder.h"

using namespace std;

class Tutor
{
public:
    Tutor();
    ~Tutor();

    void set_builder(TestQuizBuilder* builder);
    void BuildShortAnswerQuiz(QString quizName,QVector<Question> questions);

private:
    TestQuizBuilder* builder;
};

#endif // TUTOR_H
