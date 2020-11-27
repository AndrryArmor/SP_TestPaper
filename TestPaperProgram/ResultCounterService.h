#ifndef RESULTCOUNTERSERVICE_H
#define RESULTCOUNTERSERVICE_H

#include "IResultCounterService.h"
#include "Question.h"
#include "Answer.h"
#include <QuizAnswer.h>

class ResultCounterService : public IResultCounterService
{
public:
    ResultCounterService();
    ~ResultCounterService();

    float countResult(QuizAnswer *quizAnswer) override
    {
        float result = 0.0;
        for (auto answer : *(quizAnswer->userAnswers))
        {
            if (answer != nullptr && answer->getAnswerState() == AnswerState::Correct)
                result++;
        }
        return result;
    }
};

#endif // RESULTCOUNTERSERVICE_H
