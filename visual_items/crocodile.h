#ifndef CROCODILE_H
#define CROCODILE_H

#include <QGraphicsRectItem>

class Crocodile: public QGraphicsRectItem
{
public:
    Crocodile();
    void activate();
    void inactivate();
};

#endif // CROCODILE_H
