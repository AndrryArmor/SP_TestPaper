#include <QCoreApplication>
#include <QFile>
#include <QDataStream>
#include <QString>
#include <QDebug>

#include "Quiz.h"
#include "FileManager.h"

void TestQuizSerialization::testSerializeAndDeserializePerson()
{
   Quiz quiz = GetTestQuizesData();
   Serialize(quiz);
   Quiz  deserializedQuiz = Deserialize();
}


Quiz GetTestQuizesData()
{
    Question question1;
    question1->setQuestionText("1+1=?")
    question1->setQuestionType(QuestionType::ShortAnswer);
    Answer answer1;
    answer->setAnswerText("2");
    answer->setAnswerState(AnswerState::Correct);
    question1->addAnswerToList(answer1);

    //question 2
     Question question2;
    question2->setQuestionText("1+2=?")
    question2->setQuestionType(QuestionType::ShortAnswer);
    Answer answer2;
    answer->setAnswerText("3");
    answer->setAnswerState(AnswerState::Correct);
    question2->addAnswerToList(answer2);

    //question 3

    Question question3;
    question3->setQuestionText("1+7=?")
    question3->setQuestionType(QuestionType::ShortAnswer);
    Answer answer3;
    answer->setAnswerText("8");
    answer->setAnswerState(AnswerState::Correct);
    question3->addAnswerToList(answer3);
     Answer answer4;
    answer->setAnswerText("4");
    answer->setAnswerState(AnswerState::InCorrect);
    question3->addAnswerToList(answer4);
    Answer answer5;
    answer->setAnswerText("3");
    answer->setAnswerState(AnswerState::InCorrect);
    question3->addAnswerToList(answer5);

    Quiz quiz1;
	quiz1->setQuizName("First quiz for text");
    quiz1->addQuestionToList(question1);
    quiz1->addQuestionToList(question2);
    quiz1->addQuestionToList(question3);

   return quiz1;
}

void Serialize(Quiz* quiz)
{

	QString json = QuizJsonSerializer::serialize(quiz);
	FileManager::SaveToFile(json.toStdString(),"/Desktop/Project/AppData/quiz.txt");
	qDebug() << "Successfully stored";
}

Quiz Deserialize()
{

    Quiz parsedQuiz;
	var quizInString = FileManager::LoadFromFile("/Desktop/Project/AppData/quiz.txt");
    QuizJsonSerializer::parse(quizInString ,  parsedQuiz);
    qDebug() <<  "'quiz name is " <<parsedQuiz.getQuizName();
	return parsedQuiz;

}
