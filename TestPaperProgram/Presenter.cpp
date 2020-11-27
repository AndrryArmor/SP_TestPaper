#include "Presenter.h"
#include "IResultCounterService.h"
#include "TestQuizBuilder.h"
#include "TestQuizSerialization.h"
#include <QFileDialog>
#include <QDir>
#include "QuizJsonSerialization.h"
#include <FileManager.h>

Presenter::Presenter(MainWindow *mainWindow,
                     Game *game,
                     IResultCounterService *resultCounterService,
                     QObject *parent) : QObject(parent)
{
    _game = game;
    _mainWindow = mainWindow;
    _resultCounterService = resultCounterService;
    QObject::connect(_mainWindow, &MainWindow::testStarted, this, &Presenter::on_TestStarted);
}

Presenter::~Presenter()
{}

void Presenter::on_TestStarted()
{
    Quiz *quiz = new Quiz();
    QDir dir(QDir::currentPath());
    QString filePath = QFileDialog::getOpenFileName(_mainWindow, tr("Відкрити тест"),
                                                    dir.relativeFilePath("../TestPaperProgram/Tests"),
                                                    tr("JSON файли (*.json)"));
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
}
