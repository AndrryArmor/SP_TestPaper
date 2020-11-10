#ifndef IQUIZBUILDER_H
#define IQUIZBUILDER_H

#include <string>
#include "Quiz.h"
#include "Question.h"
using namespace std;

class IQuizBuilder
{
public:
    virtual ~IQuizBuilder() =0;
    virtual void SetQuizName(string quizName) =0;
    virtual void AddQuestion(Question* question) =0;
    virtual void Reset() =0;
    virtual Quiz* GetQuiz() =0;
};

#endif // IQUIZBUILDER_H
