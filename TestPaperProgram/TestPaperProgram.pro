
QT       += core gui \
            sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += с++11
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
    QuizAnswer.cpp \
    QuizJsonSerialization.cpp \
    ResultCounterService.cpp \
    TestQuizBuilder.cpp \
    TestQuizSerialization.cpp \
    TestingWindow.cpp \
    Tutor.cpp \
    dbmanager.cpp \
    main.cpp \
    testresults.cpp \
    UserTestsAnswersWindow.cpp

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
    QuizAnswer.h \
    QuizJsonSerialization.h \
    ResultCounterService.h \
    TestQuizBuilder.h \
    TestQuizSerialization.h \
    TestingWindow.h \
    Tutor.h \
    dbmanager.h \
    testresults.h \
    UserTestsAnswersWindow.h

FORMS += \
    MainWindow.ui \
    TestingWindow.ui \
    UserTestsAnswersWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TestPaperProgram.pro.user \
    Tests/MathTest.json
