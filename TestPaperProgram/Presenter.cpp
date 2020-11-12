#include "Presenter.h"
#include "ResultCounterService.h"
#include "TestQuizBuilder.h"

Presenter::Presenter(MainWindow *mainWindow,
                     Game *game,
                     ResultCounterService *resultCounterService,
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

void Presenter::on_TestFinished(QMap<Question *, Answer *> *_userAnswers)
{
    // виклик сервісу перевірки відповіді (відповідь повинна бути дробовою!)
    //int result = _resultCounterService->GetTotalResult();
    _testingWindow->showTestResult(_userAnswers->size());
}
