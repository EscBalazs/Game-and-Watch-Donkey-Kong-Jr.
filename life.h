#ifndef LIFE_H
#define LIFE_H

#include <QGraphicsRectItem>

class Life: public QGraphicsRectItem
{
public:
    Life();
    void activate();
    void inactivate();
};

#endif // LIFE_H
