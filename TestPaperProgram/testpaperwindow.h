#ifndef TESTPAPERWINDOW_H
#define TESTPAPERWINDOW_H

#include <QMainWindow>

namespace Ui {
class TestPaperWindow;
}

class TestPaperWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestPaperWindow(QWidget *parent = nullptr);
    ~TestPaperWindow();

private slots:
    void on_buttonToMain_clicked();

    void on_buttonNext_clicked();

    void on_buttonFinishTest_clicked();

private:
    Ui::TestPaperWindow *ui;
};

#endif // TESTPAPERWINDOW_H
