#ifndef PRESENTER_H
#define PRESENTER_H

#include "MainWindow.h"
#include "TestingWindow.h"
#include "UserTestsAnswersWindow.h"
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

private slots:
    void on_TestStarted();
    void on_TestFinished(QuizAnswer *_quizAnswer);
    void on_TestClosed();
    void on_ShowTestAnswers();
    void on_UserTestsAnswerWindowClosed();

private:
    MainWindow *_mainWindow;
    TestingWindow *_testingWindow;
    UserTestsAnswersWindow *_userTestsAnswersWindow;
    Game *_game;
    IResultCounterService *_resultCounterService;
    QString _appDir;
};

#endif // PRESENTER_H
