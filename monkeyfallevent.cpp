#include <QtDebug>
#include <QTimer>
#include <monkeyfallevent.h>
#include <game.h>

extern Game *game;

void MonkeyFallEvent::startFall(std::int16_t monkeyPositionId)
{
    monkeyStartPositionId = game->lifes;
    this->monkeyPositionId = monkeyPositionId;

    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(fall()));

    timer->start(1000);
}

void MonkeyFallEvent::fall()
{
    if (game->lifes != monkeyStartPositionId)
    {
        return;
    }
    game->setMonkeyPositionId(monkeyPositionId);
    this->~MonkeyFallEvent();
}
