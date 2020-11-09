#ifndef TESTINGWINDOW_H
#define TESTINGWINDOW_H

#include "Question.h"
#include "Quiz.h"
#include <QMainWindow>
#include <map>
using namespace std;

namespace Ui {class TestingWindow;}

class TestingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestingWindow(QWidget *parent = nullptr);
    ~TestingWindow();

    void setTestPaper(Quiz *quiz);
    void showTestResult(float points);

signals:
    void testFinished(map<Question *, Answer *> *_userAnswers);

private slots:
    void on_ButtonGoBack_clicked();
    void on_ButtonNext_clicked();
    void on_ButtonFinishTest_clicked();

private:
    Ui::TestingWindow *ui;
    Quiz *_quiz;
    Question *_currentQuestion;
    map<Question *, Answer *> *_userAnswers;
};

#endif // TESTINGWINDOW_H
