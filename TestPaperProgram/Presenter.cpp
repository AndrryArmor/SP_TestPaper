#include "Presenter.h"
#include "IResultCounterService.h"
#include "TestQuizBuilder.h"
#include "TestQuizSerialization.h"
#include "QuizJsonSerialization.h"
#include <FileManager.h>
#include <QFileDialog>
#include <QDir>
#include <QDate>
#include <QTime>
#include <QTextCodec>
#include "UserTestsAnswersWindow.h"
#include "dbManager.h"

static const QString path = "database.db";

Presenter::Presenter(MainWindow *mainWindow,
                     Game *game,
                     IResultCounterService *resultCounterService,
                     QObject *parent) : QObject(parent)
{
    _game = game;
    _mainWindow = mainWindow;
    _resultCounterService = resultCounterService;
    QDir *dir = new QDir();
    dir->cdUp();
    dir->cd("TestPaperProgram");
    _appDir = dir->absolutePath();
    QObject::connect(_mainWindow, &MainWindow::testStarted, this, &Presenter::on_TestStarted);
    QObject::connect(_mainWindow, &MainWindow::showTestsAnswers, this, &Presenter::on_ShowTestAnswers);
}

Presenter::~Presenter()
{}

void Presenter::on_TestStarted()
{
    Quiz *quiz = new Quiz();
    DbManager db(path);
   if (db.openDatabase())
   {
       quiz = db.getOneQuizById(1);
   }
   else
   {
      QT_DEBUG("Database is not open!");
   }

    /*QString filePath = QFileDialog::getOpenFileName(_mainWindow, "Відкрити тест",
                                                    _appDir + QString("/Tests"),
                                                    "JSON файли (*.json)");
    if (filePath.isNull() || filePath.isEmpty())
        return;

    QuizJsonSerializer::parse(FileManager().LoadFromFile(filePath), quiz);
    */

    _testingWindow = new TestingWindow(quiz, _mainWindow);

    QObject::connect(_testingWindow, &TestingWindow::testFinished, this, &Presenter::on_TestFinished);
    QObject::connect(_testingWindow, &TestingWindow::testClosed, this, &Presenter::on_TestClosed);

    _testingWindow->setVisible(true);
    _mainWindow->setHidden(true);
}

void Presenter::on_TestFinished(QuizAnswer *quizAnswer)
{
    float result = _resultCounterService->countResult(quizAnswer);
    _testingWindow->showTestResult(result);
     DbManager db(path);
    if (db.openDatabase())
    {
        TestResults* testResults = new TestResults();
        testResults->setTestResultScore(result);
        testResults->setTestId(1);
        testResults->setAccessDate(QDateTime::currentDateTime());
        QByteArray array = QuizJsonSerializer::serialize(*quizAnswer);
        QString data = QString::fromStdString(array.toStdString());
        testResults->setJsonQuestionAnswers(data);
        db.insertNewTestResult(*testResults,1);
    }
    else
    {
       QT_DEBUG("Database is not open!");
    }

   /* QString fileFolder = "/TestsAnswers/";
    QDir directory(_appDir + fileFolder);
    QStringList answersFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
    QString fileName = QString("TestAnswer") + QString::number(answersFiles.size() + 1)
                                             + QString(".json");
    FileManager().SaveToFile(QuizJsonSerializer::serialize(*quizAnswer),
                             _appDir + fileFolder + fileName);*/
}

void Presenter::on_TestClosed()
{
    _mainWindow->setVisible(true);
    _testingWindow->~TestingWindow();
}

void Presenter::on_ShowTestAnswers()
{
    QVector<QuizAnswer *> *answers = new QVector<QuizAnswer *>();
    QString fileFolder = "/TestsAnswers/";
    QDir directory(_appDir + fileFolder);
    QStringList answersFiles = directory.entryList(QStringList() << "*.json", QDir::Files);
    for (QString answerFile : answersFiles)
    {
        QuizAnswer *answer = new QuizAnswer();
        QuizJsonSerializer::parse(FileManager().LoadFromFile(_appDir + fileFolder + answerFile), answer);
        answer->setTestName(answer->getTestName() + ": " + answerFile);
        answers->push_back(answer);
    }

    _userTestsAnswersWindow = new UserTestsAnswersWindow(answers, _resultCounterService, _mainWindow);
    QObject::connect(_userTestsAnswersWindow, &UserTestsAnswersWindow::userTestAnswerWindowClosed,
                     this,                    &Presenter::on_UserTestsAnswerWindowClosed);

    _userTestsAnswersWindow->setVisible(true);
    _mainWindow->setHidden(true);
}

void Presenter::on_UserTestsAnswerWindowClosed()
{
    _mainWindow->setVisible(true);
    _userTestsAnswersWindow->~UserTestsAnswersWindow();
}
