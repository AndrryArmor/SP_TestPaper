#include "dbmanager.h"
#include <QApplication>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QtSql>

DbManager::DbManager()
{
    m_testFields =
            "t.test_id, "
            "t.name ";

    m_questionFields =
            "q.question_id, "
            "q.name, "
            "q.test_id ";

    m_answerFields =
            "a.answer_id, "
            "a.name, "
            "a.question_id, ",
            "a.is_correct ";

    m_test_resultFields =
            "tr.test_result_id, "
            "tr.test_id, ",
            "tr.score ",
            "tr.json_question_answers, ",
            "tr.access_date ";

}

bool DbManager::openDatabase()
{
    return m_database.isOpen();
}

bool DbManager::closeDatabase()
{
     m_database.close();
     return true;
}

bool DbManager::deleteDatabase()
{
    closeDatabase();
    return QFile::remove(m_database.databaseName());
}

bool DbManager::initDatabase()
{
     bool l_ret = false;
     if (m_database.isOpen())
         {
          QSqlQuery l_query(m_database);
          l_ret &= createTestsDatabase(l_query);
          l_ret = l_query.exec("PRAGMA foreign_keys = ON");
          l_ret &= createAnswersDatabase(l_query);
          l_ret &= createQuestionsDatabase(l_query);
          l_ret &= createTestResultsDatabase(l_query);
     }
     return l_ret;
   }



bool DbManager::createTestsDatabase(QSqlQuery &query)
{
    query.prepare("CREATE TABLE IF NOT EXISTS  tests ("
                  "test_id integer PRIMARY KEY,"
                  "name text NOT NULL"
                  ")");

      if (!query.exec()) {
           QT_DEBUG("Error occured on creating table tests");
           QT_DEBUG(query.lastError().text());
           return false;
      }
       return true;
}

bool DbManager::createQuestionsDatabase(QSqlQuery &query)
{
    query.prepare("CREATE TABLE IF NOT EXISTS  questions ("
                      "question_id integer PRIMARY KEY,"
                      "name text NOT NULL,"
                      "test_id integer,"
                      "FOREIGN KEY (test_id) REFERENCES tests (test_id)"
                              "ON DELETE CASCADE ON UPDATE NO ACTION"
                 ")");

    if (!query.exec()) {
         QT_DEBUG("Error occured on creating table questions");
         QT_DEBUG(query.lastError().text());
         return false;
    }
     return true;
}


bool DbManager::createAnswersDatabase(QSqlQuery &query)
{
    query.prepare("CREATE TABLE IF NOT EXISTS  answers ("
                  "answer_id integer PRIMARY KEY,"
                  "name text NOT NULL,"
                  "question_id integer,"
                  "is_correct bool,"
                  "FOREIGN KEY (question_id) REFERENCES questions (test_id)"
                          "ON DELETE CASCADE ON UPDATE NO ACTION"
             ")");

    if (!query.exec()) {
         QT_DEBUG("Error occured on creating table answers");
         QT_DEBUG(query.lastError().text());
         return false;
    }
     return true;
}


bool DbManager::createTestResultsDatabase(QSqlQuery &query)
{
    query.prepare("CREATE TABLE IF NOT EXISTS  test_results ("
                  "test_result_id integer PRIMARY KEY,"
                  "test_id integer,"
                  "score float NOT NULL,"
                  "json_question_answers TEXT,"
                  "access_date timestamp,"
                  "FOREIGN KEY (test_id) REFERENCES test (test_id)"
                          "ON DELETE CASCADE ON UPDATE NO ACTION"
              ")");

    if (!query.exec()) {
         QT_DEBUG("Error occured on creating table test_results");
         QT_DEBUG(query.lastError().text());
         return false;
    }
     return true;
}

QVector<Quiz*>* DbManager::getAllQuizes()
{
    QVector<Quiz*>* l_quizList;
    QSqlQuery l_query(m_database);
    l_query.prepare("SELECT " + m_testFields +
                    "FROM tests AS t ");
    if (!l_query.exec())
    {
        QT_DEBUG("Error occurred in getAllMovies():");
        QT_DEBUG(l_query.lastError().text());
    }
    while(l_query.next())
    {
        Quiz* l_quiz = hydrateQuiz(l_query);
        l_quizList.append(l_quiz);
    }
     return l_quizList;
}

Quiz* DbManager::hydrateQuiz(QSqlQuery &query)
{
    Quiz* l_quiz;
    l_quiz->setQuizId(query.value(0).toInt());
    l_quiz->setQuizName(query.value(1).toString());
    return l_quiz;
}

}

