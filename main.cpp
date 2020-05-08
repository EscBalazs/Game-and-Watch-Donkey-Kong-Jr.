#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <monkey.h>
#include <game.h>

Game *game;

int main(int argc, char ** argv)
{
    QApplication app(argc, argv);

    game = new Game();
    game->setGeometry(100, 100, 500, 500);

    return app.exec();
}
