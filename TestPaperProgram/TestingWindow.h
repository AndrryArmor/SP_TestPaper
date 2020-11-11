#ifndef TESTINGWINDOW_H
#define TESTINGWINDOW_H

#include "Question.h"
#include "Quiz.h"
#include <QMainWindow>
#include <QRadioButton>
#include <map>
#include <QGroupBox>
using namespace std;

namespace Ui {class TestingWindow;}

class TestingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestingWindow(QWidget *parent = nullptr);
    ~TestingWindow();

    void setTest(Quiz *quiz);
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
    int _currentQuestionNumber;
    map<Question *, Answer *> *_userAnswers;

    void setQuestionProgress(int currentQuestion, int questionCount);
    void setAnswer(QRadioButton *radioButton, QString answer);
};

#endif // TESTINGWINDOW_H
