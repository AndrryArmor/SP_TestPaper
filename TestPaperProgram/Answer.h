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
    void setAnswerId( int anwerId);
    int getAnswerId();


    //serialization
    void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj)const;


private:
    AnswerState mAnswerState;
    QString mAnswerText;
    int m_answer_id;
};

#endif // ANSWER_H
