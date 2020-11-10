#include "AnswerResultService.h"

AnswerResultService::AnswerResultService()
{
    mTotalResult = 0;
}

AnswerResultService::~AnswerResultService()
{}

int AnswerResultService::GetTotalResult()
{
    return this->mTotalResult;
}

void AnswerResultService::HandleAnsweredQuestion(Question *question)
{
    for(Answer answer : question->getAllAnswers())
    {
        if(answer.getAnswerState()== AnswerState::Correct)
        {
            HandleCorrectAnsweredQuestion(question);
        }
    }
}

void AnswerResultService::HandleCorrectAnsweredQuestion(Question *question)
{
    //move to question
    if(question->getQuestionType()== QuestionType::MultiplyChoices)
    {
        int countOfCorrectAnswers =0;
        for(Answer answer : question->getAllAnswers())
        {
            if(answer.getAnswerState()==AnswerState::Correct)
            {
                countOfCorrectAnswers++;
            }
        }
        this->mTotalResult+=(double)1/countOfCorrectAnswers;
    }
    else
    {
        this->mTotalResult++;
    }
}

