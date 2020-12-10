#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include <Quiz.h>
#include <QString>
#include <TestResults.h>

#include <QtSql/qsqldatabase.h>

class DbManager
{
     #define DATE_FORMAT "dd.MM.yyyy"
public:
       DbManager();
       bool openDatabase();
       bool closeDatabase();
       bool initDatabase();
       bool deleteDatabase();
       bool createTestsDatabase(QSqlQuery &query);
       bool createQuestionsDatabase(QSqlQuery &query);
       bool createAnswersDatabase(QSqlQuery &query);
       bool createTestResultsDatabase(QSqlQuery &query);
       QSqlError lastError();
       DbManager(const QString& path);
       ~DbManager();


       //hydrate
       Quiz* hydrateQuiz(QSqlQuery &query);
       Answer* hydrateAnswer(QSqlQuery &query);
       TestResults* hydrateTestResult(QSqlQuery &query);
       Question* hydrateQuestion(QSqlQuery &query);

       //quizes
       Quiz* getOneQuizById(const int id);
       QVector<Quiz*>* getAllQuizes();
       bool insertNewQuiz(Quiz &quiz);
       bool updateQuiz(Quiz &quiz);
       bool deleteQuiz(const int quiz_id);


       //answers
       Answer* getOneAnswerById(const int id);
       QVector<Answer*>* getAllAnswers();
       bool insertNewAnswer(Answer &answer, const int question_id);
       bool updateAnswer(Answer &answer);
       bool deleteAnswer(const int answer_id);
       bool updateAnswer(Answer &answer, const int question_id);

       //questions
       Question* getOneQuestionById(const int id);
       QVector<Question*>* getAllQuestions();
       bool insertNewQuestion(Question &question, const int test_id);
       bool updateQuestion(Question &question);
       bool deleteQuestion(const int question_id);
       bool updateQuestion(Question &question, const int test_id);
       //testResults
       TestResults* getOneTestResultById(const int id);
       QVector<TestResults*>* getAllTestResults();
       bool insertNewTestResult(TestResults &testResult, const int test_id);
       bool deleteTestResult(const int test_result_id);
       bool updateTestResult(TestResults &testResult, const int test_id);


private:
    QSqlDatabase m_database;
    QString m_testFields;
    QString m_answerFields;
    QString m_questionFields;
    QString m_test_resultFields;
    void setQuestionToQuiz(Quiz &quiz);
    void  setAnswerToQuestion(Question &question);

};

#endif // DBMANAGER_H
