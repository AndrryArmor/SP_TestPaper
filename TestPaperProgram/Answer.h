#ifndef ANSWER_H
#define ANSWER_H

#include <string>
#include <QString>
using namespace std;

enum AnswerState 
{
    Correct,
    InCorrect
};

class Answer
{
public:
    Answer();
    ~Answer();

    void setAnswerText(QString answerText);
    void setAnswerState(AnswerState answerState);
    QString getAnswerText();
    AnswerState getAnswerState();

private:
    AnswerState mAnswerState;
    QString mAnswerText;
};

#endif // ANSWER_H
