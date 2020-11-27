#include "UserTestsAnswersWindow.h"
#include "ui_UserTestsAnswersWindow.h"

UserTestsAnswersWindow::UserTestsAnswersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserTestsAnswersWindow)
{
    ui->setupUi(this);
}

UserTestsAnswersWindow::~UserTestsAnswersWindow()
{
    delete ui;
}

void UserTestsAnswersWindow::on_ButtonGoBack_clicked()
{

}

void UserTestsAnswersWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{

}
