#include "ResultCounterService.h"

ResultCounterService::ResultCounterService()
{
}

float ResultCounterService::countResult(QMap<Question *, Answer *> *answers)
{
    float result = 0.0;
    for (auto answer : *answers)
    {
        if (answer->getAnswerState() == AnswerState::Correct)
            result++;
    }
    return result;
}
