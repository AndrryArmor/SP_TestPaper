#ifndef TESTRESULTS_H
#define TESTRESULTS_H

#include <QDateTime>
#include <QString>



class TestResults
{
public:
    TestResults();
    void setJsonQuestionAnswers(QString jsonQuestionAnswers);
    QString  getJsonQuestionAnswers();
    void setTestResultId(int testResultId);
    int getTestResultId();
    void setTestResultScore(double testResultScore);
    double  getTestResultScore();
    void setTestId(int testId);
    int getTestId();
    void setAccessDate(QDateTime dateTime);
    QString getAccessDate();

private:
     int m_testResultId;
     int m_testId;
     double  m_score;

     QString  m_jsonQuestionAnswers;
     QDateTime mAccessDate;

};

#endif // TESTRESULTS_H
