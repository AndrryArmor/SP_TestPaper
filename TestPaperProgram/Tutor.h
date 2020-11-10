#ifndef TUTOR_H
#define TUTOR_H

#include <string>
#include <QVector>
#include "IQuizBuilder.h"
#include "Question.h"
using namespace std;

class Tutor
{
public:
    Tutor();
    ~Tutor();

    void set_builder(IQuizBuilder* builder);
    void BuildShortAnswerQuiz(string quizName, QVector<Question*> questions);

private:
    IQuizBuilder* builder;
};

#endif // TUTOR_H
