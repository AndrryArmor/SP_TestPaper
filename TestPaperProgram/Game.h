#ifndef GAME_H
#define GAME_H

#include <string>
#include <list>

#include "Quiz.h"
#include "Question.h"
#include "Tutor.h"
#include "AnswerResultService.h"
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
    Quiz * GetSelectedQuiz();
    Quiz* GetTestQuizesData()
    {
        Question* question1 = new Question();
        question1->setQuestionText("1+1=?");
        question1->setQuestionType(QuestionType::ShortAnswer);
        Answer* answer1= new Answer();
        answer1->setAnswerText("2");
        answer1->setAnswerState(AnswerState::Correct);
        question1->addAnswerToList(answer1);

        //question 2
        Question* question2 =new Question();
        question2->setQuestionText("1+2=?");
        question2->setQuestionType(QuestionType::ShortAnswer);
        Answer* answer2= new Answer();
        answer2->setAnswerText("3");
        answer2->setAnswerState(AnswerState::Correct);
        question2->addAnswerToList(answer2);

        //question 3

        Question* question3= new Question();
        question3->setQuestionText("1+7=?");
        question3->setQuestionType(QuestionType::ShortAnswer);
        Answer* answer3= new Answer();
        answer3->setAnswerText("8");
        answer3->setAnswerState(AnswerState::Correct);
        question3->addAnswerToList(answer3);
        Answer* answer4 = new Answer();
        answer4->setAnswerText("4");
        answer4->setAnswerState(AnswerState::InCorrect);
        question3->addAnswerToList(answer4);
        Answer* answer5 = new Answer();
        answer5->setAnswerText("3");
        answer5->setAnswerState(AnswerState::InCorrect);
        question3->addAnswerToList(answer5);

        Quiz* quiz1  = new Quiz();
        quiz1->setQuizName("First quiz for text");
        quiz1->addQuestionToList(question1);
        quiz1->addQuestionToList(question2);
        quiz1->addQuestionToList(question3);

       return quiz1;
    }

private:
    QVector<Quiz*> mQuizes;
    Quiz* selectedQuiz;
    int currentAnswer;
    Quiz* getRandomQuiz(list<Quiz*> quizes);
    AnswerResultService* answerResultService;
};

#endif // GAME_H
