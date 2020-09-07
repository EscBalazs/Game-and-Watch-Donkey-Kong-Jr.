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
    game->setFixedSize(488, 326);

    QPixmap background = game->getSprite().copy(576, 93, 488, 326);
    QPalette palette;
    palette.setBrush(game->backgroundRole(), QBrush(background));
    game->setPalette(palette);


    return app.exec();
}
