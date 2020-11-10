#ifndef ANSWER_H
#define ANSWER_H
#include "serialization/JsonSerializable.h"
#include <string>
#include <QJsonObject>
#include <QString>

using namespace std;
enum AnswerState 
{
    Correct,
    InCorrect
};

class Answer:public JsonSerializable
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
    void write(QJsonObject &jsonObj);

private:
    AnswerState mAnswerState;
    QString mAnswerText;
};

#endif // ANSWER_H
