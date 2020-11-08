#include "Presenter.h"
#include "ResultCounterService.h"

Presenter::Presenter(MainWindow *mainWindow,
                     ResultCounterService *resultCounterService,
                     QObject *parent) : QObject(parent)
{
    _mainWindow = mainWindow;
    _resultCounterService = resultCounterService;
    QObject::connect(_mainWindow, &MainWindow::testStarted, this, &Presenter::on_test_started);
}

Presenter::~Presenter()
{}

void Presenter::on_test_started()
{
    _testPaperWindow = new TestPaperWindow(_mainWindow);
    QObject::connect(_testPaperWindow, &TestPaperWindow::testFinished, this, &Presenter::on_test_finished);

    _mainWindow->setHidden(true);
    _testPaperWindow->setVisible(true);
}

void Presenter::on_test_finished(map<Question *, Answer *> *_userAnswers)
{
    // виклик сервісу перевірки відповіді (відповідь повинна бути дробовою!)
    //int result = _resultCounterService->GetTotalResult();
    _testPaperWindow->showTestResult(10);
}
