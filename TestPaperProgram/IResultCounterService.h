#ifndef IRESULTCOUNTERSERVICE_H
#define IRESULTCOUNTERSERVICE_H

#include <iostream>
#include "Question.h"
using namespace std;

class IResultCounterService
{
public:
    virtual ~IResultCounterService() =0;

    virtual int GetTotalResult() =0;
    virtual void HandleAnsweredQuestion(Question question) =0;
};

#endif // IRESULTCOUNTERSERVICE_H
