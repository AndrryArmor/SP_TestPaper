#include "ui_MainWindow.h"
#include "TestingWindow.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonStartTest_clicked()
{
    emit testStarted();
}

void MainWindow::on_ButtonQuit_clicked()
{
    exit(0);
}

void MainWindow::on_ButtonViewTestResults_clicked()
{
    emit showTestsAnswers();
}
