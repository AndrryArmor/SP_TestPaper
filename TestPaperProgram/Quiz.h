#ifndef QUIZ_H
#define QUIZ_H

#include <string>
#include <list>
#include "Question.h"
#include <QString>
#include <QVector>

using namespace std;

class Quiz:public JsonSerializable
{
public:
     Quiz();
    ~Quiz();

    QVector<Question *> getAllQuestions();
    void setQuizName(QString quizName);
    QString  getQuizName();
    void addQuestionToList(Question question);
    //serialization
	void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj) ;
    void setQuizId(int quiz_id);
    int getQuizId();

private:
    QVector<Question *> mQuestions;
    QString mQuizName;
    int mQuizId;
};

#endif // QUIZ_H
