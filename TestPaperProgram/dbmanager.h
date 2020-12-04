#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include <Quiz.h>
#include <QString>

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
       Quiz* hydrateQuiz(QSqlQuery &query)
       //quizes
       Quiz* getOneQuizById(const int id);
       QVector<Quiz*>* getAllQuizes();
       bool insertNewQuiz(Quiz &quiz);
       bool updateQuiz(Quiz &quiz);
       bool deleteQuiz(Quiz &quiz);

       //answers
       Answer* getOneAnswerById(const int id);
       QVector<Answer*>* getAllAnswers();
       bool insertNewAnswer(Answer &answer);
       bool updateAnswer(Answer &answer);
       bool deleteAnswer(Answer &answer);

       //questions
       Question* getOneQuestionById(const int id);
       QVector<Question*>* getAllQuestions();
       bool insertNewQuestion(Question &question);
       bool updateQuestion(Question &question);
       bool deleteQuestion(Question &question);
       //testResults

private:
    QSqlDatabase m_database;
    QString m_testFields;
    QString m_answerFields;
    QString m_questionFields;
    QString m_test_resultFields;

};

#endif // DBMANAGER_H
