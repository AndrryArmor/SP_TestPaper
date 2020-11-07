#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    Game * game = new Game();
    game->StartGame();

    return 0;
}
