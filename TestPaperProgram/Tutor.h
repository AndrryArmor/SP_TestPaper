#ifndef TUTOR_H
#define TUTOR_H

#include <string>
#include <list>
#include "IQuizBuilder.h"
#include "Question.h"
using namespace std;

class Tutor
{
public:
    Tutor();
    ~Tutor();

    void set_builder(IQuizBuilder* builder);
    void BuildShortAnswerQuiz(string quizName, list<Question> questions);

private:
    IQuizBuilder* builder;
};

#endif // TUTOR_H
