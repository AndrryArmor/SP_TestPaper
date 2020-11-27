#ifndef USERTESTSANSWERSWINDOW_H
#define USERTESTSANSWERSWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class UserTestsAnswersWindow;
}

class UserTestsAnswersWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserTestsAnswersWindow(QWidget *parent = nullptr);
    ~UserTestsAnswersWindow();

private slots:
    void on_ButtonGoBack_clicked();

    void on_ListWidgetTestsResults_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::UserTestsAnswersWindow *ui;
};

#endif // USERTESTSANSWERSWINDOW_H
