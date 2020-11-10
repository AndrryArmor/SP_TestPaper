#include "Tutor.h"

Tutor::Tutor()
{
}

Tutor::~Tutor()
{
}

void Tutor::set_builder(TestQuizBuilder* builder)
{
    this->builder=builder;
}

void Tutor::BuildShortAnswerQuiz(QString quizName, QVector<Question> questions)
{
    this->builder->SetQuizName(quizName);
    for (Question question : questions) 
    {
        this->builder->AddQuestion(question);
    }       
}

