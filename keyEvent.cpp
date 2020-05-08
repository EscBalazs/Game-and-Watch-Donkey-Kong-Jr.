#include <QtDebug>
#include <QTimer>
#include <keyEvent.h>
#include <game.h>

extern Game *game;

void KeyEvent::startSwing()
{
    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(1000);
}

void KeyEvent::move()
{
    if (true == goRight)
    {
        currentKeyPosition++;
    }
    if (false == goRight)
    {
        currentKeyPosition--;
    }

    game->triggerAfterKeyMove(currentKeyPosition);

    if (true == goRight && currentKeyPosition >= 5)
    {
        goRight = false;
    }
    if (false == goRight && currentKeyPosition <= 1)
    {
        goRight = true;
    }
}
