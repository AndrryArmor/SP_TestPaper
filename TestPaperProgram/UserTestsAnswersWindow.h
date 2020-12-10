#ifndef USERTESTSANSWERSWINDOW_H
#define USERTESTSANSWERSWINDOW_H

#include "QuizAnswer.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>
#include "IResultCounterService.h"

namespace Ui {
class UserTestsAnswersWindow;
}

class UserTestsAnswersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserTestsAnswersWindow(QVector<QuizAnswer *> *quizAnswer,
                                    IResultCounterService *resultCounterService,
                                    QWidget *parent = nullptr);
    ~UserTestsAnswersWindow();

signals:
    void userTestAnswerWindowClosed();

private slots:
    void on_ButtonGoBack_clicked();
    void on_ListWidgetTestsResults_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::UserTestsAnswersWindow *ui;
    QVector<QuizAnswer *> _quizAnswers;
    IResultCounterService *_resultCounterService;
};

#endif // USERTESTSANSWERSWINDOW_H
