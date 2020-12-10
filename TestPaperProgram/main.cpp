/* Додаток для тестування (кодова назва: SmarTest)
 * Автори додатку: студенти 3 курсу КПІ, групи ІТ-81
 * Ачілов Андрій
 * Тищенко Ірина
 * Юхимчук Анастасія
 */

#include <dbmanager.h>
#include <QApplication>
#include <TestQuizSerialization.h>
#include <iostream>
#include "MainWindow.h"
#include "Game.h"
#include "Presenter.h"
#include "ResultCounterService.h"


static const QString path = "database.db";


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DbManager db(path);

    if (db.openDatabase())
    {

        db.initDatabase();
        db.addTestData();
    }
    else
    {
       QT_DEBUG("Database is not open!");
    }

    MainWindow mainWindow;
    IResultCounterService *service = new ResultCounterService();
    Game *game = new Game();
    Presenter *presenter = new Presenter(&mainWindow, game, service);

    mainWindow.setVisible(true);

    return a.exec();
}





