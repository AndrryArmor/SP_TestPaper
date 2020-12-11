#include "testresults.h"

TestResults::TestResults()
{

}

void TestResults::setJsonQuestionAnswers(QString jsonQuestionAnswers)
{

    m_jsonQuestionAnswers= jsonQuestionAnswers;
}
QString TestResults::getJsonQuestionAnswers()
{
    return m_jsonQuestionAnswers;
}
void TestResults::setTestResultId(int testResultId)
{
m_testResultId = testResultId;
}
int TestResults::getTestResultId()
{
    return  m_testResultId;
}
void TestResults::setTestResultScore(double testResultScore)
{
   m_score = testResultScore;
}
double TestResults::getTestResultScore()
{
    return m_score;
}
void TestResults::setTestId(int testId)
{
    m_testId = testId;
}
int TestResults::getTestId()
{
    return m_testId;
}
void TestResults::setAccessDate(QDateTime dateTime)
{
   mAccessDate = dateTime;
}


QString TestResults::getAccessDate()
{
    return mAccessDate.toString();
}
