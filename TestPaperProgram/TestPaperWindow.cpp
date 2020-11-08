#include "ui_TestPaperWindow.h"
#include "TestPaperWindow.h"
#include <QMessageBox>

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

void TestPaperWindow::setTestPaper(Quiz *quiz)
{
    _quiz = quiz;
}

void TestPaperWindow::showTestResult(float points)
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

void TestPaperWindow::on_buttonToMain_clicked()
{
    ((QWidget *)parent())->setVisible(true);
    this->destroy();
}

void TestPaperWindow::on_buttonNext_clicked()
{

}

void TestPaperWindow::on_buttonFinishTest_clicked()
{
    emit testFinished(_userAnswers);
    ui->buttonNext->setEnabled(false);
    ui->buttonFinishTest->setEnabled(false);
}
