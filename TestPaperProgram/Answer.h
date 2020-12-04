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
    void setAnswerId( int anwerId);
    int getAnswerId();

private:
    AnswerState mAnswerState;
    QString mAnswerText;
    int m_answer_id;
};

#endif // ANSWER_H
