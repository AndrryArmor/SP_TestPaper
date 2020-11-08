#ifndef TESTPAPERWINDOW_H
#define TESTPAPERWINDOW_H

#include "Question.h"
#include "Quiz.h"
#include <QMainWindow>
#include <map>
using namespace std;

namespace Ui { class TestPaperWindow; }

class TestPaperWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestPaperWindow(QWidget *parent = nullptr);
    ~TestPaperWindow();

    void setTestPaper(Quiz *quiz);    
    void showTestResult(float points);

signals:
    void testFinished(map<Question *, Answer *> *_userAnswers);

private slots:
    void on_buttonToMain_clicked();
    void on_buttonNext_clicked();
    void on_buttonFinishTest_clicked();

private:
    Ui::TestPaperWindow *ui;
    Quiz *_quiz;
    Question *_currentQuestion;
    map<Question *, Answer *> *_userAnswers;
};

#endif // TESTPAPERWINDOW_H
