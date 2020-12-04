#ifndef QUIZ_H
#define QUIZ_H

#include <QString>
#include <QVector>
#include "Question.h"
using namespace std;

class Quiz:public JsonSerializable
{
public:
    Quiz();
    ~Quiz();

    QVector<Question *> *getAllQuestions();
    void setQuizName(QString quizName);
    QString getQuizName();
    void addQuestionToList(Question* question);

private:
    QVector<Question *> *mQuestions;
    QString mQuizName;

    // JsonSerializable interface
public:
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj) const;
};

#endif // QUIZ_H
