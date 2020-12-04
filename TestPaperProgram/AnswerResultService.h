#ifndef ANSWERRESULTSERVICE_H
#define ANSWERRESULTSERVICE_H

#include <iostream>
#include "Question.h"
using namespace std;

class AnswerResultService
{
public:
    AnswerResultService();
    ~AnswerResultService();
    int GetTotalResult()/* override*/;
    void HandleAnsweredQuestion(Question *question);/* override*/
    void HandleCorrectAnsweredQuestion(Question *question);
private:
    double mTotalResult;
};


#endif // ANSWERRESULTSERVICE_H
