#include "QuizAnswer.h"

QuizAnswer::QuizAnswer()
{
    userAnswers = new QMap<Question *, Answer *>();
}
QuizAnswer::~QuizAnswer()
{}

