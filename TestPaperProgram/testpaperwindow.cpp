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
