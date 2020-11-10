#include <iostream>
#include "TestQuizBuilder.h"
using namespace std;

TestQuizBuilder::TestQuizBuilder()
{
    this->Reset();
}

TestQuizBuilder::~TestQuizBuilder()
{
    delete quiz;
}

void TestQuizBuilder::Reset()
{
    this->quiz = new Quiz();
}

void TestQuizBuilder::AddQuestion(Question question)
{
    this->quiz->addQuestionToList(question);
}

void TestQuizBuilder::SetQuizName(QString quizName)
{
    this->quiz->setQuizName(quizName);
}

Quiz* TestQuizBuilder::GetQuiz()
{
    Quiz* result= this->quiz;
     this->Reset();
    return result;
}


/*#include <iostream>
#include <functional>
#include <iterator>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <random>

    private:
    void prepareAnswers(list<string> answers)
    {
      vector<reference_wrapper<const string>> wrappedAnswers(answers.cbegin(), answers.cend());
      random_device rd;
      mt19937 generator(rd());
      shuffle(wrappedAnswers.begin(), wrappedAnswers.end(), generator);
      return wrappedAnswers;
    }

    
    //factory method
    template<typename T>
    Question* CreateQuestion(QuestionType questionType)
    {
        Question *pQuestion = NULL;
        switch(questionType)       
        {
            case (QuestionType::ShortAnswer)
                pQuestion = new CNameVerifier(_Parameter);
                break;
            case (QuestionType::MultiplyChoices)
                pQuestion = new CIntegerVerifier(_Parameter);
                break;     
            case (QuestionType::TrueFalse)       
                pQuestion = new CIntegerVerifier(_Parameter);
                break;     
        }

        return pQuestion;
    }   
};
*/
