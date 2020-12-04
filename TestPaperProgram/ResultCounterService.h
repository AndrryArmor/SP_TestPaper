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
        QMap<Question *, Answer *> *answers = quizAnswer->getUserAnswers();
        QMap<Question *, Answer *>::Iterator answers_iterator = answers->begin();
        for (; answers_iterator != answers->end(); ++answers_iterator)
        {
            if (*answers_iterator != nullptr && (*answers_iterator)->getAnswerState() == AnswerState::Correct
                    && (*answers_iterator)->getAnswerText() != "")
                result++;
        }
        return result;
    }
};

#endif // RESULTCOUNTERSERVICE_H
