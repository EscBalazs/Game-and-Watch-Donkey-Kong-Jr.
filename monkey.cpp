#include "monkey.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Monkey::Monkey()
{
    setBrush(Qt::lightGray);
}

void Monkey::activate()
{
    setBrush(Qt::blue);
}

void Monkey::inactivate()
{
    setBrush(Qt::lightGray);
}
