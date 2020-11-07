#ifndef ANSWER_H
#define ANSWER_H

#include <string>
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

    void setAnswerText(string answerText);
    void setAnswerState(AnswerState answerState);
    string getAnswerText();
    AnswerState getAnswerState();

private:
    AnswerState mAnswerState;
    string mAnswerText;
};

#endif // ANSWER_H
