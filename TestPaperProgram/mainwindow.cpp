#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testpaperwindow.h"

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
    TestPaperWindow* testWindow = new TestPaperWindow(this);
    this->hide();
    testWindow->show();
}
