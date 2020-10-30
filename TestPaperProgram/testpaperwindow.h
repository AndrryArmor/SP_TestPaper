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

private:
    Ui::TestPaperWindow *ui;
};

#endif // TESTPAPERWINDOW_H
