#ifndef PRESENTER_H
#define PRESENTER_H

#include "MainWindow.h"
#include "TestPaperWindow.h"
#include "ResultCounterService.h"
#include <QObject>

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(MainWindow *mainWindow,
                           ResultCounterService *resultCounterService = nullptr,
                           QObject *parent = nullptr);
    ~Presenter();
    MainWindow *_mainWindow;

signals:

private slots:
    void on_test_started();
    void on_test_finished(map<Question *, Answer *> *_userAnswers);

private:
    TestPaperWindow *_testPaperWindow;
    ResultCounterService *_resultCounterService;
};

#endif // PRESENTER_H
