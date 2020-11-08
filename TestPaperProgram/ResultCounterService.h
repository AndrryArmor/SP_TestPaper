#ifndef RESULTCOUNTERSERVICE_H
#define RESULTCOUNTERSERVICE_H

#include <iostream>
#include "Question.h"
#include "IResultCounterService.h"
using namespace std;

class ResultCounterService/* : public IResultCounterService*/
{
public:
    ResultCounterService();
    ~ResultCounterService();

    int GetTotalResult()/* override*/;
    void HandleAnsweredQuestion(Question *question)/* override*/;
    void HandleCorrectAnsweredQuestion(Question *question);

private:
    double mTotalResult;
};

#endif // RESULTCOUNTERSERVICE_H
