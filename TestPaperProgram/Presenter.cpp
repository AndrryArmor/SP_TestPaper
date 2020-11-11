#include "Presenter.h"
#include "TestQuizBuilder.h"
#include "AnswerResultService.h"

Presenter::Presenter(MainWindow *mainWindow,
                     AnswerResultService *answerResultService,
                     Game *game ,
                     QObject *parent) : QObject(parent)
{
    _mainWindow = mainWindow;
    _answerResultService= answerResultService;
    _game = game;
    QObject::connect(_mainWindow, &MainWindow::testStarted, this, &Presenter::on_TestStarted);
}

Presenter::~Presenter()
{}

void Presenter::on_TestStarted()
{
    _testingWindow = new TestingWindow(_mainWindow);
    _testingWindow->setTest(_game->GetSelectedQuiz());
    _testingWindow->
    QObject::connect(_testingWindow, &TestingWindow::testFinished, this, &Presenter::on_TestFinished);

    _mainWindow->setHidden(true);
    _testingWindow->setVisible(true);
}

void Presenter::on_TestFinished(map<Question *, Answer *> *_userAnswers)
{
    // виклик сервісу перевірки відповіді (відповідь повинна бути дробовою!)
    int result = _answerResultService->GetTotalResult();
    _testingWindow->showTestResult(10);
}
