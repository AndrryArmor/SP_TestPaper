#include "Tutor.h"

Tutor::Tutor()
{
}

Tutor::~Tutor()
{
}

void Tutor::set_builder(IQuizBuilder* builder)
{
    this->builder=builder;
}

void Tutor::BuildShortAnswerQuiz(string quizName, list<Question> questions)
{
    this->builder->SetQuizName(quizName);
    for (Question question : questions) 
    {
        this->builder->AddQuestion(question);
    }       
}

