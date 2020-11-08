#include "Question.h"
#include "ResultCounterService.h"

/*ResultCounterService::ResultCounterService()
{
    mTotalResult = 0;
}

ResultCounterService::~ResultCounterService()
{}

int ResultCounterService::GetTotalResult()
{
    return this->mTotalResult;
}

void ResultCounterService::HandleAnsweredQuestion(Question *question)
{
    for(Answer answer : question->getAllAnswers())
    {
        if(answer.getAnswerState()== AnswerState::Correct)
        {
            HandleCorrectAnsweredQuestion(question);
        }
    }
}

void ResultCounterService::HandleCorrectAnsweredQuestion(Question *question)
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
}*/
