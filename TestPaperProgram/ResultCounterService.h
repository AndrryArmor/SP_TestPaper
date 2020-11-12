#ifndef RESULTCOUNTERSERVICE_H
#define RESULTCOUNTERSERVICE_H

#include "Question.h"
#include "Answer.h"
#include <QMap>

class ResultCounterService
{
public:
    ResultCounterService();
    ~ResultCounterService();

    float countResult(QMap<Question *, Answer *> *answers);
};

#endif // RESULTCOUNTERSERVICE_H
