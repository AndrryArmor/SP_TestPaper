#ifndef IRESULTCOUNTERSERVICE_H
#define IRESULTCOUNTERSERVICE_H

#include <iostream>
#include "Question.h"
using namespace std;

class IResultCounterService
{
public:
    virtual ~IResultCounterService() {};

    virtual float countResult(QMap<Question *, Answer *> *answers) {};
    //virtual void HandleAnsweredQuestion(Question *question) =0;
};

#endif // IRESULTCOUNTERSERVICE_H
