#ifndef GAME_H
#define GAME_H

#include <string>
#include <QVector>
#include "ResultCounterService.cpp"
#include "Quiz.h"
#include "Question.h"
#include "Tutor.h"
using namespace std;

class Game
{
public:
    Game();
    ~Game();

    void BuildQuiz(Tutor& tutor);
    void StartGame();
    void NextQuestion(Question question);
    void PreviusQuestion(Question question);
    void AddQuizToList(Quiz* quiz);

private:
    QVector<Quiz*> mQuizes;
    Quiz* selectedQuiz;
    int currentAnswer;
    Quiz* getRandomQuiz(QVector<Quiz*> quizes);
    ResultCounterService* resultCounterService;
};

#endif // GAME_H
