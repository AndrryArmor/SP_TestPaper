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

    QString getTestName();
    void setTestName(QString testName);

    QMap<Question *, Answer *> *getUserAnswers();
    void setUserAnswers(QMap<Question *, Answer *> *userAnswers);

    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj) const;

private:
    QString _testName;
    QMap<Question *, Answer *> *_userAnswers;

};
#endif // QUIZANSWER_H
