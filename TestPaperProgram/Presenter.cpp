#include "Presenter.h"
#include "TestQuizBuilder.h"
#include "AnswerResultService.h"

Presenter::Presenter(MainWindow *mainWindow,
                     AnswerResultService *answerResultService,
                     QObject *parent) : QObject(parent)
{
    _mainWindow = mainWindow;
    _answerResultService= answerResultService;
    QObject::connect(_mainWindow, &MainWindow::testStarted, this, &Presenter::on_TestStarted);
}

Presenter::~Presenter()
{}

void Presenter::on_TestStarted()
{
    _testingWindow = new TestingWindow(_mainWindow);
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
