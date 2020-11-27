#ifndef QUIZANSWER_H
#define QUIZANSWER_H
#include "Question.h"
#include "Answer.h"
#include <QMap>

class QuizAnswer
{
public:
    QuizAnswer();
    ~QuizAnswer();

    QMap<Question *, Answer *> *userAnswers;
};
#endif // QUIZANSWER_H
