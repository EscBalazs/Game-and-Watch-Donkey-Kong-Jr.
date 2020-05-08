#include "key.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Key::Key()
{
    setBrush(Qt::green);
}

void Key::activate()
{
    setBrush(Qt::red);
}

void Key::inactivate()
{
    setBrush(Qt::green);
}
