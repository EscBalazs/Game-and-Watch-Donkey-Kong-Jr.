#include "bird.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Bird::Bird()
{
    setBrush(Qt::white);
}

void Bird::activate()
{
    setBrush(QColor(145, 113, 83));
}

void Bird::inactivate()
{
    setBrush(Qt::white);
}
