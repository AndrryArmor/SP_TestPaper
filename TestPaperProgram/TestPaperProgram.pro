QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Answer.cpp \
    Game.cpp \
    MainWindow.cpp \
    Question.cpp \
    Quiz.cpp \
    ResultCounterService.cpp \
    TestPaperWindow.cpp \
    TestQuizBuilder.cpp \
    Tutor.cpp \
    main.cpp

HEADERS += \
    Answer.h \
    Game.h \
    IQuizBuilder.h \
    IResultCounterService.h \
    MainWindow.h \
    Question.h \
    Quiz.h \
    ResultCounterService.h \
    TestPaperWindow.h \
    TestQuizBuilder.h \
    Tutor.h

FORMS += \
    MainWindow.ui \
    MainWindow.ui \
    TestPaperWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TestPaperProgram.pro.user
