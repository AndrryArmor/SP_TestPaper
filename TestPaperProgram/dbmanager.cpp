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
            "q.question_type, "
            "q.test_id ";

    m_answerFields =
            "a.answer_id, "
            "a.name, "
            "a.question_id, "
            "a.is_correct ";

    m_test_resultFields =
            "tr.test_result_id, "
            "tr.test_id, ",
            "tr.score ",
            "tr.json_question_answers, ",
            "tr.access_date ";

}



DbManager::DbManager(const QString &path):DbManager()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(path);

    if (!m_database.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}


DbManager::~DbManager()
{
    if (m_database.isOpen())
    {
        m_database.close();
    }
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
          QSqlQuery* l_query = new QSqlQuery(m_database);

          l_ret &= createTestsDatabase(*l_query);
          l_ret = l_query->exec("PRAGMA foreign_keys = ON");
          l_ret &= createAnswersDatabase(*l_query);
          l_ret &= createQuestionsDatabase(*l_query);
          l_ret &= createTestResultsDatabase(*l_query);
     }
     return l_ret;
   }


void DbManager::addTestData()
{
    if(getAllQuizes()->count()==0)
    {
    //add quiz
    Quiz *quiz1 = new Quiz();
    quiz1->setQuizName("First quiz for text");
    insertNewQuiz(*quiz1);


    //add questions
    Question* question1 = new Question();
    question1->setQuestionText("1+1=?");
    question1->setQuestionType(QuestionType::ShortAnswer);
    insertNewQuestion(*question1,1);

    Question* question2 =new Question();
    question2->setQuestionText("1+2=?");
    question2->setQuestionType(QuestionType::ShortAnswer);
    insertNewQuestion(*question2,1);

    Question* question3= new Question();
    question3->setQuestionText("1+7=?");
    question3->setQuestionType(QuestionType::ShortAnswer);
    insertNewQuestion(*question2,1);

    //add answers

    Answer* answer1= new Answer();
    answer1->setAnswerText("2");
    answer1->setAnswerState(AnswerState::Correct);
    insertNewAnswer(*answer1,1);
    Answer* answer2= new Answer();
    answer2->setAnswerText("3");
    answer2->setAnswerState(AnswerState::Correct);
    insertNewAnswer(*answer2,2);

    Answer* answer3= new Answer();
    answer3->setAnswerText("8");
    answer3->setAnswerState(AnswerState::Correct);

    Answer* answer4 = new Answer();
    answer4->setAnswerText("4");
    answer4->setAnswerState(AnswerState::InCorrect);

    Answer* answer5 = new Answer();
    answer5->setAnswerText("3");
    answer5->setAnswerState(AnswerState::InCorrect);
    insertNewAnswer(*answer3,3);
    insertNewAnswer(*answer4,3);
    insertNewAnswer(*answer5,3);
    }
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
                      "question_type int NOT NULL,"
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
                  "is_correct int NOT NULL,"
                  "FOREIGN KEY (question_id) REFERENCES questions (question_id)"
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



Quiz* DbManager::hydrateQuiz(QSqlQuery &query)
{
    Quiz* l_quiz = new Quiz();
    l_quiz->setQuizId(query.value(0).toInt());
    l_quiz->setQuizName(query.value(1).toString());
    setQuestionToQuiz(*l_quiz);
    return l_quiz;
}

void DbManager::setQuestionToQuiz(Quiz &quiz)
{

    QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("SELECT  DISTINCT " +m_questionFields +
                       "FROM questions AS q, tests AS t "
                       "WHERE q.test_id = :id");

    l_query->bindValue(":id", quiz.getQuizId());
   // l_query->bindValue("id_test", quiz.getQuizId());

    if (!l_query->exec())
    {
        QT_DEBUG("An error occured in getOneTestResultById:");
        QT_DEBUG(l_query->lastError().text());
    }
    while (l_query->next())
    {
        Question* l_question = hydrateQuestion(*l_query);
        quiz.addQuestionToList(l_question);
    }
}

Question* DbManager::hydrateQuestion(QSqlQuery &query)
{
   Question* l_question = new Question();
    l_question->setQuestionId(query.value(0).toInt());
    l_question->setQuestionText(query.value(1).toString());
    l_question->setQuestionType(QuestionType(qRound(query.value(3).toDouble())));
    setAnswerToQuestion(*l_question);
    return l_question;
}

void DbManager::setAnswerToQuestion(Question &question)
{
    QSqlQuery* l_query = new QSqlQuery(m_database);
    l_query->prepare("SELECT DISTINCT " + m_answerFields +
                    "FROM answers AS a, questions AS q "
                    "WHERE a.question_id = :id_question");
    l_query->bindValue(":id_question", question.getQuestionId());

    if (!l_query->exec())
    {
        QT_DEBUG("An error occured in setAnswerToQuestion:");
        QT_DEBUG(l_query->lastError().text());
    }
    while (l_query->next())
    {
        Answer* l_anwer = hydrateAnswer(*l_query);
        question.addAnswerToList(l_anwer);
    }
}

Answer* DbManager::hydrateAnswer(QSqlQuery &query)
{
    Answer* l_answer = new Answer();
    l_answer->setAnswerId(query.value(0).toInt());
    l_answer->setAnswerText(query.value(1).toString());
    l_answer->setAnswerState(AnswerState(qRound(query.value(3).toDouble())));
    return  l_answer;
}

TestResults* DbManager::hydrateTestResult(QSqlQuery &query)
{
    TestResults* l_test_result = new TestResults();
    l_test_result->setTestResultId(query.value(0).toInt());
    l_test_result->setTestId(query.value(1).toInt());
    l_test_result->setTestResultScore(query.value(2).toDouble());
    l_test_result->setJsonQuestionAnswers(query.value(3).toString());
    l_test_result->setAccessDate(query.value(4).toDateTime());
    return  l_test_result;
}


//getters
 Quiz* DbManager::getOneQuizById(const int id)
 {
      Quiz* l_quiz = new Quiz();
      QSqlQuery* l_query = new QSqlQuery(m_database);
       l_query->prepare("SELECT " +m_testFields +
                         "FROM tests AS t "
                         "WHERE test_id = :id");
       l_query->bindValue(":id", id);
       if (!l_query->exec())
       {
            QT_DEBUG("An error occured in getOneQuizById:");
            QT_DEBUG(l_query->lastError().text());
       }

       if(l_query->next())
       {
              l_quiz = hydrateQuiz(*l_query);
       }
       return l_quiz;

 }

 Answer* DbManager::getOneAnswerById(const int id)
  {
       Answer* l_answer = new Answer();
       QSqlQuery* l_query = new QSqlQuery(m_database);
        l_query->prepare("SELECT " +m_answerFields +
                          "FROM answers AS a "
                          "WHERE answer_id = :id");
        l_query->bindValue(":id", id);
        if (!l_query->exec())
        {
             QT_DEBUG("An error occured in getOneAnswerById:");
             QT_DEBUG(l_query->lastError().text());
        }

        if(l_query->next())
        {
               l_answer = hydrateAnswer(*l_query);
        }
        return l_answer;

  }

 Question* DbManager::getOneQuestionById(const int id)
  {
       Question* l_Question = new Question();
       QSqlQuery* l_query = new QSqlQuery(m_database);
        l_query->prepare("SELECT " +m_questionFields +
                          "FROM questions AS q "
                          "WHERE question_id = :id");
        l_query->bindValue(":id", id);
        if (!l_query->exec())
        {
             QT_DEBUG("An error occured in getOneQuestionById:");
             QT_DEBUG(l_query->lastError().text());
        }

        if(l_query->next())
        {
               l_Question = hydrateQuestion(*l_query);
        }
        return l_Question;

  }

 TestResults* DbManager::getOneTestResultById(const int id)
  {
       TestResults* l_TestResults = new TestResults();
       QSqlQuery* l_query = new QSqlQuery(m_database);
        l_query->prepare("SELECT " +m_test_resultFields +
                          "FROM test_results AS tr "
                          "WHERE test_result_id = :id");
        l_query->bindValue(":id", id);
        if (!l_query->exec())
        {
             QT_DEBUG("An error occured in getOneTestResultById:");
             QT_DEBUG(l_query->lastError().text());
        }

        if(l_query->next())
        {
               l_TestResults =hydrateTestResult(*l_query);
        }
        return l_TestResults;

  }

 //get all

 QVector<Quiz*>* DbManager::getAllQuizes()
 {
     QVector<Quiz*>* l_quizList= new QVector<Quiz*>();
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("SELECT " + m_testFields +
                     "FROM tests AS t");


     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in getAllQuizes():");
         QT_DEBUG(l_query->lastError().text());
     }

     while(l_query->next())
     {
         Quiz* l_quiz= hydrateQuiz(*l_query);
         l_quizList->append(l_quiz);
     }

     return l_quizList;
 }

 QVector<Answer*>* DbManager::getAllAnswers()
 {
     QVector<Answer*>* l_answerList = new QVector<Answer*>();
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("SELECT " + m_answerFields +
                     "FROM answers AS a");


     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in getAllQuizes():");
         QT_DEBUG(l_query->lastError().text());
     }

     while(l_query->next())
     {
         Answer* l_answer = hydrateAnswer(*l_query);
         l_answerList->append(l_answer);
     }

     return l_answerList;
 }

 QVector<Question*>* DbManager::getAllQuestions()
 {
     QVector<Question*>* l_questionsList= new QVector<Question*>();;
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("SELECT " + m_questionFields +
                     "FROM questions AS q");


     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in getAllQuizes():");
         QT_DEBUG(l_query->lastError().text());
     }

     while(l_query->next())
     {
         Question* l_question = hydrateQuestion(*l_query);
        l_questionsList->append(l_question );
     }

     return l_questionsList;
 }


 QVector<TestResults*>* DbManager::getAllTestResults()
 {
     QVector<TestResults*>* l_trList= new QVector<TestResults*>();;
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("SELECT " + m_test_resultFields +
                     "FROM test_results AS tr");


     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in getAllTestResults():");
         QT_DEBUG(l_query->lastError().text());
     }

     while(l_query->next())
     {
         TestResults* l_testResults = hydrateTestResult(*l_query);
         l_trList->append(l_testResults);
     }

     return  l_trList;
 }


 //inserts
 bool DbManager::insertNewQuiz(Quiz &quiz)
 {
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("INSERT INTO tests (name) "
                     "VALUES (:name)");
     l_query->bindValue(":name", quiz.getQuizName());

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in insertNewQuiz:");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }
     quiz.setQuizId(l_query->lastInsertId().toInt());

     return true;
 }

 bool DbManager::insertNewQuestion(Question &question, const int test_id)
 {

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("INSERT INTO questions (name,question_type,test_id) "
                     "VALUES (:name,:question_type,:test_id)");
     l_query->bindValue(":name", question.getQuestionText());
     l_query->bindValue(":question_type", static_cast<int>(question.getQuestionType()));
     l_query->bindValue(":test_id", test_id);

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in insertNewQuestion:");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }
     question.setQuestionId(l_query->lastInsertId().toInt());

     return true;
 }

 bool DbManager::insertNewAnswer(Answer &answer, const int question_id)
 {
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("INSERT INTO answers (name,question_id,is_correct) "
                     "VALUES (:name,:question_id,:is_correct)");
     l_query->bindValue(":name", answer.getAnswerText());
     l_query->bindValue(":is_correct", static_cast<int>(answer.getAnswerState()));
     l_query->bindValue(":question_id", question_id);

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in insertNewQuestion:");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }
     answer.setAnswerId((l_query->lastInsertId().toInt()));

     return true;
 }

 bool DbManager::insertNewTestResult(TestResults &testResult, const int test_id)
 {


     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("INSERT INTO test_results (test_id,score,json_question_answers,access_date) "
                     "VALUES (:test_id,:score,:json_question_answers,:access_date)");
     l_query->bindValue(":score",testResult.getTestResultScore());
     l_query->bindValue(":json_question_answers",testResult.getJsonQuestionAnswers());
     l_query->bindValue(":access_date", testResult.getAccessDate());
     l_query->bindValue(":test_id", test_id);


     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in insertNewTestResult:");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }
     testResult.setTestResultId((l_query->lastInsertId().toInt()));

     return true;
 }

 //deletes
 bool DbManager::deleteQuiz(const int quiz_id)
 {
     if (quiz_id <= 0)
     {
         QT_DEBUG("Cannot delete such quiz:");
         return false;
     }

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("DELETE FROM tests "
                    "WHERE test_id = :id");
     l_query->bindValue(":id", quiz_id);

     if(!l_query->exec())
     {
         QT_DEBUG("An error occured in deleteQuiz:");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }

 bool DbManager::deleteAnswer(const int answer_id)
 {
     if (answer_id <= 0)
     {
         QT_DEBUG("Cannot delete such answer:");
         return false;
     }

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("DELETE FROM answers "
                    "WHERE answer_id = :id");
     l_query->bindValue(":id", answer_id);

     if(!l_query->exec())
     {
         QT_DEBUG("An error occured in deleteAnswer:");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }

 bool DbManager::deleteQuestion(const int question_id)
 {
     if (question_id<= 0)
     {
         QT_DEBUG("Cannot delete such question:");
         return false;
     }

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("DELETE FROM questions "
                    "WHERE question_id = :id");
     l_query->bindValue(":id", question_id);

     if(!l_query->exec())
     {
         QT_DEBUG("An error occured in deleteQuestion");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }
 bool DbManager::deleteTestResult(const int test_result_id)
 {
     if (test_result_id<= 0)
     {
         QT_DEBUG("Cannot delete such question:");
         return false;
     }

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("DELETE FROM questions "
                    "WHERE test_result_id= :id");
     l_query->bindValue(":id", test_result_id);

     if(!l_query->exec())
     {
         QT_DEBUG("An error occured in deleteTestResult");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }

 //update
 bool DbManager::updateQuiz(Quiz &quiz)
 {

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("UPDATE tests "
                     "SET name = :name, "
                     "WHERE quiz_id = :id");
     l_query->bindValue(":name", quiz.getQuizName());
     l_query->bindValue(":id", quiz.getQuizId());

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in updateQuiz");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }

 bool DbManager::updateAnswer(Answer &answer, const int question_id)
 {

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("UPDATE answers "
                     "SET name = :name, "
                     "SET is_correct = :is_correct, "
                     "SET question_id = :question_id "
                     "WHERE answer_id= :id");
     l_query->bindValue(":name", answer.getAnswerText());
     l_query->bindValue(":is_correct", answer.getAnswerState());
     l_query->bindValue(":question_id", question_id);
     l_query->bindValue(":id", answer.getAnswerId());

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in updateQuiz");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }

 bool DbManager::updateQuestion(Question &question, const int test_id)
 {

     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("UPDATE questions "
                     "SET name = :name, "
                     "SET question_type = :question_type, "
                     "SET test_id= :test_id "
                     "WHERE question_id= :id");
     l_query->bindValue(":name", question.getQuestionText());
     l_query->bindValue(":question_type",question.getQuestionType());
     l_query->bindValue(":test_id=",test_id);
     l_query->bindValue(":id", question.getQuestionId());

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in updateQuiz");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }


 bool DbManager::updateTestResult(TestResults &testResult, const int test_id)
 {
     QSqlQuery* l_query = new QSqlQuery(m_database);
     l_query->prepare("UPDATE test_results "
                     "SET test_id = :test_id, "
                     "SET score = :score, "
                     "SET json_question_answers= :json_question_answers "
                     "SET access_date= :access_date "
                     "WHERE test_result_id= :id");
     l_query->bindValue(": test_id", test_id);
     l_query->bindValue(":score",testResult.getTestResultScore());
       l_query->bindValue(":json_question_answers","");
     l_query->bindValue(":access_date=",testResult.getAccessDate());
     l_query->bindValue(":id", testResult.getTestResultId());

     if (!l_query->exec())
     {
         QT_DEBUG("An error occured in updateTestResult");
         QT_DEBUG(l_query->lastError().text());

         return false;
     }

     return true;
 }

