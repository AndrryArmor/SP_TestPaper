#include "Presenter.h"
#include "IResultCounterService.h"
#include "TestQuizBuilder.h"

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
    // точка костилізації
    _testingWindow = new TestingWindow(_game->GetTestQuizesData(), _mainWindow);

    QObject::connect(_testingWindow, &TestingWindow::testFinished, this, &Presenter::on_TestFinished);

    _testingWindow->setVisible(true);
    _mainWindow->setHidden(true);
}

void Presenter::on_TestFinished(QMap<Question *, Answer *> *userAnswers)
{
    float result = _resultCounterService->countResult(userAnswers);
    _testingWindow->showTestResult(result);
}
