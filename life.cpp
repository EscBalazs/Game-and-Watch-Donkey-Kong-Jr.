#include "life.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Life::Life()
{
    setBrush(Qt::black);
}

void Life::activate()
{
    setBrush(Qt::black);
}

void Life::inactivate()
{
    setBrush(Qt::lightGray);
}
