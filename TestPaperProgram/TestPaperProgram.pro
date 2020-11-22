QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=
          console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Answer.cpp \
    FileManager.cpp \
    Game.cpp \
    MainWindow.cpp \
    Presenter.cpp \
    Question.cpp \
    Quiz.cpp \
    QuizJsonSerialization.cpp \
    ResultCounterService.cpp \
    TestQuizBuilder.cpp \
    TestQuizSerialization.cpp \
    TestingWindow.cpp \
    Tutor.cpp \
    main.cpp

HEADERS += \
    Answer.h \
    FileManager.h \
    Game.h \
    IQuizBuilder.h \
    IResultCounterService.h \
    JsonSerializable.h \
    MainWindow.h \
    Presenter.h \
    Question.h \
    Quiz.h \
    QuizJsonSerialization.h \
    ResultCounterService.h \
    TestQuizBuilder.h \
    TestQuizSerialization.h \
    TestingWindow.h \
    Tutor.h

FORMS += \
    MainWindow.ui \
    TestingWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TestPaperProgram.pro.user
