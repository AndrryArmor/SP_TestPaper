#ifndef RESULTCOUNTERSERVICE_H
#define RESULTCOUNTERSERVICE_H

#include "IResultCounterService.h"
#include "Question.h"
#include "Answer.h"
#include <QMap>

class ResultCounterService : public IResultCounterService
{
public:
    ResultCounterService();
    ~ResultCounterService();

    float countResult(QMap<Question *, Answer *> *answers) override
    {
        float result = 0.0;
        for (auto answer : *answers)
        {
            if (answer != nullptr && answer->getAnswerState() == AnswerState::Correct)
                result++;
        }
        return result;
    }
};

#endif // RESULTCOUNTERSERVICE_H
