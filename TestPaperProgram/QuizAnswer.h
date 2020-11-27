#ifndef QUIZANSWER_H
#define QUIZANSWER_H
#include "Question.h"
#include "Answer.h"
#include <QMap>

class QuizAnswer : public JsonSerializable
{
public:
    QuizAnswer();
    ~QuizAnswer();

    QMap<Question *, Answer *> *userAnswers;

    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj) const;
};
#endif // QUIZANSWER_H
