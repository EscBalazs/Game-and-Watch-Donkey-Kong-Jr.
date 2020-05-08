#include <QtDebug>
#include <QTimer>
#include <birdevent.h>
#include <game.h>

extern Game *game;

void BirdEvent::startFly()
{
    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(1000);
}

void BirdEvent::move()
{
    game->triggerBeforeBirdMove(currentBirdId);

    std::int16_t previousBirdId = currentBirdId;
    currentBirdId++;

    if (currentBirdId > 8)
    {
        currentBirdId = 1;
    }

    game->triggerAfterBirdMove(previousBirdId, currentBirdId);
}
