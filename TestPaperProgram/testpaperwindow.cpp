#include "testpaperwindow.h"
#include "ui_testpaperwindow.h"

TestPaperWindow::TestPaperWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestPaperWindow)
{
    ui->setupUi(this);
}

TestPaperWindow::~TestPaperWindow()
{
    delete ui;
}

void TestPaperWindow::on_buttonToMain_clicked()
{
    this->close();
    ((QMainWindow*)parent())->show();
}

void TestPaperWindow::on_buttonNext_clicked()
{

}

void TestPaperWindow::on_buttonFinishTest_clicked()
{

}
