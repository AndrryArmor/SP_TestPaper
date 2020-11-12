#ifndef RESULTCOUNTERSERVICE_H
#define RESULTCOUNTERSERVICE_H

#include "IResultCounterService.h"
#include "Question.h"
#include "Answer.h"
#include <QMap>

class ResultCounterService// : IResultCounterService
{
public:
    ResultCounterService();
    ~ResultCounterService();

    float countResult(QMap<Question *, Answer *> *answers) /*override*/;
};

#endif // RESULTCOUNTERSERVICE_H
