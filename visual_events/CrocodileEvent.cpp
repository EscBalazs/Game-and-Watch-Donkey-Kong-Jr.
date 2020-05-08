#include <QtDebug>
#include <QTimer>
#include <visual_events/CrocodileEvent.h>
#include <game.h>

extern Game *game;

void CrocodileEvent::startMove()
{
    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(1000);
}

void CrocodileEvent::move()
{
    std::int16_t previousCrocodiledId = currentCrocodiledId;
    currentCrocodiledId++;

    if (currentCrocodiledId > 13)
    {
        currentCrocodiledId = 1;
    }

    game->triggerAfterCrocodileMove(previousCrocodiledId, currentCrocodiledId);
}
