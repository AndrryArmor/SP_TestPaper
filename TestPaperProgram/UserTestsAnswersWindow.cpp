#include "UserTestsAnswersWindow.h"
#include "ui_UserTestsAnswersWindow.h"
#include <QtAlgorithms>
#include "IResultCounterService.h"
using namespace std;

UserTestsAnswersWindow::UserTestsAnswersWindow(QVector<QuizAnswer *> *quizAnswer,
                                               IResultCounterService *resultCounterService,
                                               QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserTestsAnswersWindow)
{
    ui->setupUi(this);
    _quizAnswers = *quizAnswer;
    _resultCounterService = resultCounterService;

    QVector<QuizAnswer *>::Iterator quizAnswers_iterator = _quizAnswers.begin();
    for(; quizAnswers_iterator != _quizAnswers.end(); quizAnswers_iterator++)
    {
        ui->ListWidgetTestsResults->addItem(new QListWidgetItem((*quizAnswers_iterator)->getTestName(),
                                                                ui->ListWidgetTestsResults));
    }

    ui->TableWidgetTestAnswers->setColumnCount(3);
    ui->TableWidgetTestAnswers->setHorizontalHeaderLabels({"Питання тесту", "Відповідь користувача", "Стан відповіді"});
}

UserTestsAnswersWindow::~UserTestsAnswersWindow()
{
    delete ui;
}

void UserTestsAnswersWindow::on_ButtonGoBack_clicked()
{
    emit userTestAnswerWindowClosed();
}

void UserTestsAnswersWindow::on_ListWidgetTestsResults_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    while (ui->TableWidgetTestAnswers->rowCount() > 0)
        ui->TableWidgetTestAnswers->removeRow(0);

    int currentRow = ui->ListWidgetTestsResults->row(current);
    QMap<Question *, Answer *> *testAnswers = _quizAnswers[currentRow]->getUserAnswers();
    QMap<Question *, Answer *>::Iterator answer_iterator = testAnswers->begin();
    for(int i = 0; answer_iterator != testAnswers->end(); answer_iterator++)
    {
        QString s = answer_iterator.value()->getAnswerText();
        QTableWidgetItem *itemUserAnswer = new QTableWidgetItem(answer_iterator.value()->getAnswerText());
        QTableWidgetItem *itemQuestionName = new QTableWidgetItem(answer_iterator.key()->getQuestionText());
        QString answerState;
        if (answer_iterator.value()->getAnswerText() != "" &&
                answer_iterator.value()->getAnswerState() == AnswerState::Correct)
        {
            answerState = "+";
        }
        else
        {
            answerState = "-";
        }
        QTableWidgetItem *itemAnswerState = new QTableWidgetItem(answerState);

        ui->TableWidgetTestAnswers->setRowCount(i + 1);
        ui->TableWidgetTestAnswers->setItem(i, 0, itemQuestionName);
        ui->TableWidgetTestAnswers->setItem(i, 1, itemUserAnswer);
        ui->TableWidgetTestAnswers->setItem(i, 2, itemAnswerState);
        i++;
    }
    int result = _resultCounterService->countResult(_quizAnswers[currentRow]);
    int testCount = _quizAnswers[currentRow]->getUserAnswers()->size();
    ui->LabelTestResult->setText("Результат тесту: " + QString::number(result) + "/" + QString::number(testCount));
}
