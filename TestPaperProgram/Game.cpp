#include <iostream>
#include <random>
#include <vector>
#include "Tutor.h"
#include <QRandomGenerator>
#include "TestQuizBuilder.h"
#include "Game.h"
using namespace std;

Game::Game()
{
    mQuizes = {};
    currentAnswer = 0;
    answerResultService = new AnswerResultService();
}

Game::~Game()
{
    //delete resultCounterService ;
}

void Game::BuildQuiz(Tutor& tutor)
{
    TestQuizBuilder* builder = new TestQuizBuilder();
    tutor.set_builder(builder);
    //tutor.BuildShortAnswerQuiz(string quizName, list<Question> questions);
    
    Quiz* p= builder->GetQuiz();
    this->AddQuizToList(p);
    delete p;
    delete builder;
}

void Game::StartGame()
{
    //std::seed_seq sseq(1,this->mQuizes.length());
    //QRandomGenerator generator(sseq);
    this->selectedQuiz = this->mQuizes[0];//TODO random number
}

void Game::NextQuestion(Question question)
{
    if(currentAnswer < (int)question.getAllAnswers().size())
    {
      currentAnswer++;
    }
    //else show messege maybe??
}

void Game::PreviusQuestion(Question question)
{
    if(currentAnswer > (int)question.getAllAnswers().size())
    {
      --currentAnswer;
    }
     //else show messege maybe??
}

void Game::AddQuizToList(Quiz* quiz)
{
    mQuizes.push_back(quiz);
}


//Quiz Game::getRandomQuiz(QVector<Quiz*> quizes)
//{
    /*random_device seed ;
    // generator
   // mt19937 engine( seed( ) ) ;
    // number distribution
   // uniform_int_distribution<int> choose( 0 , quizes.size( ) - 1 ) ;
  //  return quizes[ choose( engine ) ] ;*/
  //  return nullptr;
//};

