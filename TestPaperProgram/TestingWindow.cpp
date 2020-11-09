#include "TestingWindow.h"
#include "ui_TestingWindow.h"
#include <QMessageBox>

TestingWindow::TestingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestingWindow)
{
    ui->setupUi(this);
}

TestingWindow::~TestingWindow()
{
    delete ui;
}

void TestingWindow::setTestPaper(Quiz *quiz)
{
    _quiz = quiz;
}

void TestingWindow::showTestResult(float points)
{
    QString resultMessageTitle = "Результат";
    QString resultMessageDescription = "Кількість набраних балів: " + QString::number(points);
    QMessageBox *resultMessage = new class QMessageBox(QMessageBox::Icon::Information,
                                                       resultMessageTitle,
                                                       resultMessageDescription,
                                                       QMessageBox::Ok,
                                                       this);
    resultMessage->setVisible(true);
}

void TestingWindow::on_ButtonGoBack_clicked()
{
    ((QWidget *)parent())->setVisible(true);
    this->destroy();
}

void TestingWindow::on_ButtonNext_clicked()
{

}

void TestingWindow::on_ButtonFinishTest_clicked()
{
    emit testFinished(_userAnswers);
    ui->ButtonNext->setEnabled(false);
    ui->ButtonFinishTest->setEnabled(false);
}
