#include "crocodile.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Crocodile::Crocodile()
{
    setBrush(Qt::white);
}

void Crocodile::activate()
{
    setBrush(Qt::green);
}

void Crocodile::inactivate()
{
    setBrush(Qt::white);
}
