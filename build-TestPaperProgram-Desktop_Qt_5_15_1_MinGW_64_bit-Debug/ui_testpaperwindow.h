/********************************************************************************
** Form generated from reading UI file 'testpaperwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPAPERWINDOW_H
#define UI_TESTPAPERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestPaperWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TestPaperWindow)
    {
        if (TestPaperWindow->objectName().isEmpty())
            TestPaperWindow->setObjectName(QString::fromUtf8("TestPaperWindow"));
        TestPaperWindow->resize(400, 600);
        centralwidget = new QWidget(TestPaperWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 381, 16));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        TestPaperWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestPaperWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 20));
        TestPaperWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TestPaperWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TestPaperWindow->setStatusBar(statusbar);

        retranslateUi(TestPaperWindow);

        QMetaObject::connectSlotsByName(TestPaperWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestPaperWindow)
    {
        TestPaperWindow->setWindowTitle(QCoreApplication::translate("TestPaperWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("TestPaperWindow", "\320\237\320\270\321\202\320\260\320\275\320\275\321\217 1/10", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestPaperWindow: public Ui_TestPaperWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPAPERWINDOW_H
