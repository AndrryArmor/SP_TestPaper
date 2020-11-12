#ifndef PRESENTER_H
#define PRESENTER_H

#include "MainWindow.h"
#include "TestingWindow.h"
#include "ResultCounterService.h"
#include "Game.h"
#include <QObject>

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(MainWindow *mainWindow,
                       Game *game,
                       ResultCounterService *resultCounterService = nullptr,
                       QObject *parent = nullptr);
    ~Presenter();
    MainWindow *_mainWindow;

signals:

private slots:
    void on_TestStarted();
    void on_TestFinished(QMap<Question *, Answer *> *_userAnswers);

private:
    Game *_game;
    TestingWindow *_testingWindow;
    ResultCounterService *_resultCounterService;
};

#endif // PRESENTER_H
