#ifndef TESTINGWINDOW_H
#define TESTINGWINDOW_H

#include "Question.h"
#include "Quiz.h"
#include "QuizAnswer.h"
#include <QMainWindow>
#include <QRadioButton>
#include <QMap>
using namespace std;

namespace Ui {class TestingWindow;}

class TestingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestingWindow(Quiz *quiz, QWidget *mainWindow, QWidget *parent = nullptr);
    ~TestingWindow();
    void updateView();
    Answer *readUserAnswer();
    void showTestResult(float points);

signals:
    //void testFinished(QMap<Question *, Answer *> *_userAnswers);
    void testFinished(QuizAnswer *_quizAnswers);

private slots:
    void on_ButtonGoBack_clicked();
    void on_ButtonNext_clicked();
    void on_ButtonFinishTest_clicked();

private:
    Ui::TestingWindow *ui;
    QWidget *_mainWindow;
    Quiz *_quiz;
    QVector<Question *>::Iterator _questionIterator;
    Question *_currentQuestion;
    int _currentQuestionNumber;
    QMap<Question *, Answer *> *_userAnswers;
    QuizAnswer *_quizAnswer;

    void setQuestionProgress(int currentQuestion, int questionCount);
    void setAnswer(QRadioButton *radioButton, QString answer);
};

#endif // TESTINGWINDOW_H
