#ifndef ANSWER_H
#define ANSWER_H

#include <string>
#include <QString>
#include <jsonserializable.h>
using namespace std;

enum AnswerState 
{
    Correct,
    InCorrect
};

class Answer:JsonSerializable
{
public:
    Answer();
    ~Answer();

    void setAnswerText(QString answerText);
    void setAnswerState(AnswerState answerState);
    QString getAnswerText();
    AnswerState getAnswerState();
    //serialization
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj)const;

private:
    AnswerState mAnswerState;
    QString mAnswerText;
};

#endif // ANSWER_H
