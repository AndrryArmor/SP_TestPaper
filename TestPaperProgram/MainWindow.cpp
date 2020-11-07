#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TestPaperWindow.h"

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

void MainWindow::on_ButtonQuit_clicked()
{
    exit(0);
}
