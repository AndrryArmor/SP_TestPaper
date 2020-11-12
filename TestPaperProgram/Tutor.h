#ifndef TUTOR_H
#define TUTOR_H

#include <string>
#include <QVector>
#include "TestQuizBuilder.h"
#include "Question.h"
using namespace std;

class Tutor
{
public:
    Tutor();
    ~Tutor();

    void set_builder(TestQuizBuilder* builder);
    void BuildShortAnswerQuiz(string quizName, QVector<Question*> questions);

private:
    IQuizBuilder* builder;
};

#endif // TUTOR_H
