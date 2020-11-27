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
}

Presenter::~Presenter()
{}

void Presenter::on_TestStarted()
{
    Quiz *quiz = new Quiz();
    QString filePath = QFileDialog::getOpenFileName(_mainWindow, "Відкрити тест",
                                                    _appDir + QString("/Tests"),
                                                    "JSON файли (*.json)");
    QuizJsonSerializer::parse(FileManager().LoadFromFile(filePath), quiz);

    // точка костилізації
    _testingWindow = new TestingWindow(quiz, _mainWindow);

    QObject::connect(_testingWindow, &TestingWindow::testFinished, this, &Presenter::on_TestFinished);

    _testingWindow->setVisible(true);
    _mainWindow->setHidden(true);
}

void Presenter::on_TestFinished(QuizAnswer *quizAnswer)
{
    float result = _resultCounterService->countResult(quizAnswer);
    _testingWindow->showTestResult(result);

    FileManager *fileManager = new FileManager();
    QString fileName = "/TestsAnswers/TestAnswer.json";
    fileManager->SaveToFile(QuizJsonSerializer::serialize(*quizAnswer), _appDir + fileName);

}
