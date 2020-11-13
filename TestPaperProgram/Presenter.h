#ifndef PRESENTER_H
#define PRESENTER_H

#include "MainWindow.h"
#include "TestingWindow.h"
#include "IResultCounterService.h"
#include "Game.h"
#include <QObject>

class Presenter : public QObject
{
    Q_OBJECT
public:
    explicit Presenter(MainWindow *mainWindow,
                       Game *game,
                       IResultCounterService *resultCounterService,
                       QObject *parent = nullptr);
    ~Presenter();

signals:

private slots:
    void on_TestStarted();
    void on_TestFinished(QMap<Question *, Answer *> *_userAnswers);

private:
    MainWindow *_mainWindow;
    TestingWindow *_testingWindow;
    Game *_game;
    IResultCounterService *_resultCounterService;
};

#endif // PRESENTER_H
