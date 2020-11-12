#ifndef TESTQUIZBUILDER_H
#define TESTQUIZBUILDER_H

#include <QString>
#include "Quiz.h"
#include "Question.h"
#include "IQuizBuilder.h"
using namespace std;

class TestQuizBuilder : public IQuizBuilder
{
public:
    TestQuizBuilder();
    ~TestQuizBuilder();

    void SetQuizName(QString quizName);
    void AddQuestion(Question* question);
    void Reset();
    Quiz* GetQuiz();

private:
    Quiz* quiz;
};

#endif // TESTQUIZBUILDER_H
