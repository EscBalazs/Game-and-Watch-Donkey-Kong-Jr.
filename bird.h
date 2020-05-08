#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsRectItem>

class Bird: public QGraphicsRectItem
{
public:
    Bird();
    void activate();
    void inactivate();
};

#endif // BIRD_H
