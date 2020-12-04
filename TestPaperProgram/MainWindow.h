#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TestingWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void testStarted();
    void showTestsAnswers();

private slots:
    void on_ButtonStartTest_clicked();
    void on_ButtonViewTestResults_clicked();
    void on_ButtonQuit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
