#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>
#include "serialization/QuizJsonSerializer.h"
#include "Quiz.h"
#include "serialization/FileManager.h"

class TestQuizSerialization
{

void testSerializeAndDeserializeQuestion()
{
   Quiz* quiz = GetTestQuizesData();
   Serialize(quiz);
   Quiz*  deserializedQuiz = Deserialize();
}


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

void Serialize(Quiz* quiz)
{

    QString json = QuizJsonSerializer::serialize(*quiz);
    FileManager::SaveToFile(json.toLatin1().data(),"C:/test/quiz.txt");
	qDebug() << "Successfully stored";
}

Quiz* Deserialize()
{

    Quiz* parsedQuiz;
    QString quizInString = FileManager::LoadFromFile("C:/test/quiz.txt");
    QuizJsonSerializer::parse(quizInString ,  *parsedQuiz);
    qDebug() <<  "'quiz name is " <<parsedQuiz->getQuizName();
	return parsedQuiz;
}
};
