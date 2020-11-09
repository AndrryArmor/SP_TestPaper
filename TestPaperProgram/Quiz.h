#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <list>
#include "Question.h"
using namespace std;

class Quiz
{
public:
    Quiz();
    ~Quiz();

    list<Question *> getAllQuestions();
    void setQuizName(string quizName);
    string  getQuizName();
    void addQuestionToList(Question question);

private:
    list<Question *> mQuestions;
    string mQuizName;
};

#endif // QUIZ_H
