/* Додаток для тестування (кодова назва: SmarTest)
 * Автори додатку: студенти 3 курсу КПІ, групи ІТ-81
 * Ачілов Андрій
 * Тищенко Ірина
 * Юхимчук Анастасія
 */

#include <QApplication>
#include <iostream>
#include "MainWindow.h"
#include "Game.h"
#include "Presenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;
    AnswerResultService *service = new AnswerResultService();
    Game *game = new Game();
    game->StartGame();
    Presenter *presenter = new Presenter(&mainWindow);

    mainWindow.setVisible(true);
    return a.exec();
}
