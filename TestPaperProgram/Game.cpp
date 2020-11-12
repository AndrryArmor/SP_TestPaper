#include <iostream>
#include <random>
#include <vector>
#include "Game.h"
#include "ResultCounterService.h"
#include "TestQuizBuilder.cpp"
#include "IQuizBuilder.h"
#include "Tutor.h"
using namespace std;

Game::Game()
{
    mQuizes = {};
    currentAnswer = 0;
    //resultCounterService = new ResultCounterService();
}

Game::~Game()
{
    //delete resultCounterService ;
}

void Game::BuildQuiz(Tutor& tutor)
{
    /*IQuizBuilder* builder = new TestQuizBuilder();
    tutor.set_builder(builder);
    //tutor.BuildShortAnswerQuiz(string quizName, QVector<Question> questions);
    
    Quiz* p= builder->GetQuiz();
    this->AddQuizToList(p);
    delete p;
    delete builder;*/
}

void Game::StartGame()
{
    this->selectedQuiz = getRandomQuiz(this->mQuizes);
}

void Game::NextQuestion(Question question)
{
    if(currentAnswer < (int)question.getAllAnswers()->size())
    {
      currentAnswer++;
    }
    //else show messege maybe??
}

void Game::PreviusQuestion(Question question)
{
    if(currentAnswer > (int)question.getAllAnswers()->size())
    {
      --currentAnswer;
    }
     //else show messege maybe??
}

void Game::AddQuizToList(Quiz* quiz)
{
    mQuizes.push_back(quiz);
}

Quiz* Game::getRandomQuiz(QVector<Quiz*> quizes)
{
    /*random_device seed ;
    // generator
    mt19937 engine( seed( ) ) ;
    // number distribution
    uniform_int_distribution<int> choose( 0 , quizes.size( ) - 1 ) ;
    return quizes[ choose( engine ) ] ;*/
    return nullptr;
};

Quiz* Game::GetTestQuizesData()
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
