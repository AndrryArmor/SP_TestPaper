#include "TestingWindow.h"
#include "ui_TestingWindow.h"
#include <QMessageBox>
#include <QVector>
#include <list>


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

void TestingWindow::setTest(Quiz *quiz)
{
    _quiz = quiz;
    _currentQuestionNumber = 0;
    on_ButtonNext_clicked();
}

void TestingWindow::setQuestionProgress(int currentQuestion, int questionCount)
{
    ui->LabelQuestionProgress->text() = "Питання " +
            QString::number(currentQuestion) + "/" +
            QString::number(questionCount);
}

void TestingWindow::setAnswer(QRadioButton *radioButton, QString answer)
{
    int ROW_SIZE = 35;
    int rowNumber = 1;
    QStringList strings = answer.split(' ');
    QString resultRow = strings[0];
    for (int i = 1; i < strings.count() && rowNumber < 4; ++i)
    {
        QString newString = resultRow + " " + strings[i];
        if ((newString.count() + rowNumber - 1) / ROW_SIZE < rowNumber)
        {
            resultRow = newString;
        }
        else
        {
            resultRow += '\n' + strings[i];
            rowNumber++;
        }
    }

    radioButton->text() = resultRow;
    if (rowNumber > 3)
        radioButton->setToolTip(answer);
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
    _currentQuestion = _quiz->getAllQuestions()[_currentQuestionNumber];
    QVector<Answer*> currentAnswers = _currentQuestion->getAllAnswers();
    setQuestionProgress(_currentQuestionNumber, _quiz->getAllQuestions().size());

    int answerCount = currentAnswers.size();
    if (answerCount > 0)
           ui->createFirstExclusiveGroup(currentAnswers);
       // setAnswer(ui->RadioButton1stAnswer, currentAnswers[0]->getAnswerText());
    /*if (answerCount > 1)
        setAnswer(ui->RadioButton1stAnswer, currentAnswers[1]->getAnswerText());
    if (answerCount > 2)
        setAnswer(ui->RadioButton1stAnswer, currentAnswers[2]->getAnswerText());
    if (answerCount > 3)
        setAnswer(ui->RadioButton1stAnswer, currentAnswers[3]->getAnswerText());
        */

    _currentQuestionNumber++;
    if (_currentQuestionNumber == (int)_quiz->getAllQuestions().size())
        ui->ButtonNext->setEnabled(false);
}



void TestingWindow::on_ButtonFinishTest_clicked()
{
    emit testFinished(_userAnswers);
    ui->ButtonNext->setEnabled(false);
    ui->ButtonFinishTest->setEnabled(false);
}


