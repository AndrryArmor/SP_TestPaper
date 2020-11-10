#ifndef QUESTION_H
#define QUESTION_H
#include <QString>
#include <QVector>
#include "Answer.h"
#include "serialization/JsonSerializable.h"
#include <QJsonObject>

using namespace std;

enum QuestionType
{
    ShortAnswer,
    MultiplyChoices
};

class Question:public JsonSerializable
{
public:
    Question();
    ~Question();
    void setQuestionText(QString question);
    void setQuestionType(QuestionType questionType);
    QString getQuestionText();
    QuestionType getQuestionType();
    void addAnswerToList(Answer *answer);
    QVector<Answer*> getAllAnswers();
    //serialization
	void read(const QJsonObject &jsonObj);
    void write(QJsonObject &jsonObj);

private:
    QuestionType mQuestionType;
    QVector<Answer*> mAnswers;
    QString mQuestionText;
};



#endif // QUESTION_H
