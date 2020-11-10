QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Answer.cpp \
    AnswerResultService.cpp \
    Game.cpp \
    JsonSerializer.cpp \
    MainWindow.cpp \
    Presenter.cpp \
    Question.cpp \
    Quiz.cpp \
    TestQuizBuilder.cpp \
    TestingWindow.cpp \
    Tutor.cpp \
    main.cpp \
    serialization/FileManager.cpp \
    serialization/QuizJsonSerializer.cpp

HEADERS += \
    Answer.h \
    AnswerResultService.h \
    Game.h \
    MainWindow.h \
    Presenter.h \
    Question.h \
    Quiz.h \
    QuizBuilder.h \
    TestQuizBuilder.h \
    TestingWindow.h \
    Tutor.h \
    serialization/FileManager.h \
    serialization/JsonSerializable.h \
    serialization/QuizJsonSerializer.h

FORMS += \
    MainWindow.ui \
    TestingWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TestPaperProgram.pro.user
