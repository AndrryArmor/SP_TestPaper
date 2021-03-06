#include "TestingWindow.h"
#include "ui_TestingWindow.h"
#include <QMessageBox>
#include <QVector>
#include <list>

TestingWindow::TestingWindow(Quiz *quiz, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestingWindow)
{
    ui->setupUi(this);
    _quiz = quiz;
    //_userAnswers = new QMap<Question *, Answer *>();
    _quizAnswer = new QuizAnswer();
    _quizAnswer->setTestName(quiz->getQuizName());

    setWindowTitle(_quiz->getQuizName());
    _questionIterator = quiz->getAllQuestions()->begin();
    _currentQuestionNumber = 1;
    updateView();
}

TestingWindow::~TestingWindow()
{
    delete ui;
}

void TestingWindow::updateView()
{
    QVector<Answer*> *currentAnswers = (*_questionIterator)->getAllAnswers();
    ui->LabelQuestionName->setText((*_questionIterator)->getQuestionText());
    setQuestionProgress(_currentQuestionNumber, _quiz->getAllQuestions()->size());
    int answerCount = currentAnswers->size();

    ui->RadioButton1stAnswer->setCheckable(false);
    ui->RadioButton2ndAnswer->setCheckable(false);
    ui->RadioButton3rdAnswer->setCheckable(false);
    ui->RadioButton4thAnswer->setCheckable(false);

    ui->RadioButton1stAnswer->setCheckable(true);
    ui->RadioButton2ndAnswer->setCheckable(true);
    ui->RadioButton3rdAnswer->setCheckable(true);
    ui->RadioButton4thAnswer->setCheckable(true);

    ui->RadioButton1stAnswer->setHidden(true);
    ui->RadioButton2ndAnswer->setHidden(true);
    ui->RadioButton3rdAnswer->setHidden(true);
    ui->RadioButton4thAnswer->setHidden(true);

    if (answerCount > 0)
    {
        ui->RadioButton1stAnswer->setVisible(true);
        setAnswer(ui->RadioButton1stAnswer, (*currentAnswers)[0]->getAnswerText());
    }
    if (answerCount > 1)
    {
        ui->RadioButton2ndAnswer->setVisible(true);
        setAnswer(ui->RadioButton2ndAnswer, (*currentAnswers)[1]->getAnswerText());
    }
    if (answerCount > 2)
    {
        ui->RadioButton3rdAnswer->setVisible(true);
        setAnswer(ui->RadioButton3rdAnswer, (*currentAnswers)[2]->getAnswerText());
    }
    if (answerCount > 3)
    {
        ui->RadioButton4thAnswer->setVisible(true);
        setAnswer(ui->RadioButton4thAnswer, (*currentAnswers)[3]->getAnswerText());
    }

    if (_currentQuestionNumber == (int)_quiz->getAllQuestions()->size())
        ui->ButtonNext->setDisabled(true);
}

Answer *TestingWindow::readUserAnswer()
{
    QVector<Answer *> *currentAnswers = (*_questionIterator)->getAllAnswers();
    if (ui->RadioButton1stAnswer->isChecked() == true)
        return (*currentAnswers)[0];
    else if (ui->RadioButton2ndAnswer->isChecked() == true)
        return (*currentAnswers)[1];
    else if (ui->RadioButton3rdAnswer->isChecked() == true)
        return (*currentAnswers)[2];
    else if (ui->RadioButton4thAnswer->isChecked() == true)
        return (*currentAnswers)[3];
    else return nullptr;
}

void TestingWindow::setQuestionProgress(int currentQuestion, int questionCount)
{
    ui->LabelQuestionProgress->setText(QString::number(currentQuestion) + "/" + QString::number(questionCount));
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

    radioButton->setText(resultRow);
    if (rowNumber > 3)
        radioButton->setToolTip(answer);
}

void TestingWindow::showTestResult(float points)
{
    QString resultMessageTitle = "Результат";
    QString resultMessageDescription = "Кількість набраних балів: " + QString::number(points, 'g', 2);
    QMessageBox *resultMessage = new class QMessageBox(QMessageBox::Icon::Information,
                                                       resultMessageTitle,
                                                       resultMessageDescription,
                                                       QMessageBox::Ok,
                                                       this);
    resultMessage->setVisible(true);
}

void TestingWindow::on_ButtonGoBack_clicked()
{
    emit testClosed();
}

void TestingWindow::on_ButtonNext_clicked()
{
    //_userAnswers->insert((*_questionIterator), readUserAnswer());
    _quizAnswer->getUserAnswers()->insert((*_questionIterator), readUserAnswer());
    _questionIterator++;
    _currentQuestionNumber++;
    updateView();
}

void TestingWindow::on_ButtonFinishTest_clicked()
{
    //_userAnswers->insert((*_questionIterator), readUserAnswer());
    _quizAnswer->getUserAnswers()->insert((*_questionIterator), readUserAnswer());
    _questionIterator++;
    while (_questionIterator != _quiz->getAllQuestions()->end())
    {
        _quizAnswer->getUserAnswers()->insert((*_questionIterator), new Answer());
        _questionIterator++;
    }

    //emit testFinished(_userAnswers);
    emit testFinished(_quizAnswer);
    ui->ButtonNext->setDisabled(true);
    ui->ButtonFinishTest->setDisabled(true);
}
