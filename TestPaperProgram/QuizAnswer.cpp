#include "QuizAnswer.h"
#include <QJsonArray>

QuizAnswer::QuizAnswer()
{
    _userAnswers = new QMap<Question *, Answer *>();
}
QuizAnswer::~QuizAnswer()
{}

QString QuizAnswer::getTestName()
{
    return _testName;
}

void QuizAnswer::setTestName(QString testName)
{
    _testName = testName;
}

QMap<Question *, Answer *> *QuizAnswer::getUserAnswers()
{
    return _userAnswers;
}

void QuizAnswer::setUserAnswers(QMap<Question *, Answer *> *userAnswers)
{
    _userAnswers = userAnswers;
}

//serialization
void QuizAnswer::read(const QJsonObject &jsonObj)
{
     // json encapsulates the QJsonArray
    QJsonArray jsonQuestions = jsonObj["questions"].toArray();
    QJsonArray jsonAnswers = jsonObj["answers"].toArray();
    // json encapsulates the QJsonArray
    this->setTestName(jsonObj["testname"].toString());
    for(int i = 0; i < jsonQuestions.size(); i++)
    {
        Question *question = new Question();
        Answer *answer = new Answer();
        question->read(jsonQuestions[i].toObject());
        answer->read(jsonAnswers[i].toObject());
        _userAnswers->insert(question, answer);
    }
}

void QuizAnswer::write(QJsonObject &jsonObj) const
{
    QJsonArray jsonQuestions;
    QJsonArray jsonAnswers;

    jsonObj["testname"] = _testName;
    QMap<Question *, Answer *>::Iterator it;
    for(it = _userAnswers->begin(); it != _userAnswers->end(); it++)
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
