#include "QuizAnswer.h"
#include <QJsonArray>

QuizAnswer::QuizAnswer()
{
    userAnswers = new QMap<Question *, Answer *>();
}
QuizAnswer::~QuizAnswer()
{}

//serialization
void QuizAnswer::read(const QJsonObject &jsonObj)
{
     // json encapsulates the QJsonArray
    QJsonArray jsonQuestions = jsonObj["questions"].toArray();
    QJsonArray jsonAnswers = jsonObj["answers"].toArray();
    // json encapsulates the QJsonArray

    for(int i = 0; i < jsonQuestions.size(); i++)
    {
        Question *question = new Question();
        Answer *answer = new Answer();
        question->read(jsonQuestions[i].toObject());
        answer->read(jsonAnswers[i].toObject());
        this->userAnswers->insert(question, answer);
    }
}

void QuizAnswer::write(QJsonObject &jsonObj) const
{
    QJsonArray jsonQuestions;
    QJsonArray jsonAnswers;
    QMap<Question *, Answer *>::Iterator it;
    for(it = userAnswers->begin(); it != userAnswers->end(); it++)
    {
        QJsonObject jsonQuestion;
        QJsonObject jsonAnswer;
        Question *question = &(*it.key());
        Answer *answer = &(*it.value());
        question->write(jsonQuestion);
        if (answer == nullptr)
            answer = new Answer();
        answer->write(jsonAnswer);
        jsonQuestions.append(jsonQuestion);
        jsonAnswers.append(jsonAnswer);
    }
    jsonObj["questions"] = jsonQuestions;
    jsonObj["answers"] = jsonAnswers;
}
