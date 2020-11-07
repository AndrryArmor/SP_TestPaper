#ifndef RESULTCOUNTERSERVICE_H
#define RESULTCOUNTERSERVICE_H

#include <iostream>
#include "Question.h"
#include "IResultCounterService.h"
using namespace std;

class ResultCounterService : public IResultCounterService
{
public:
    ResultCounterService();
    ~ResultCounterService();

    virtual int GetTotalResult();
    void HandleAnsweredQuestion(Question question);
    void HandleCorrectAnsweredQuestion(Question question);

private:
    double mTotalResult;
};

#endif // RESULTCOUNTERSERVICE_H
