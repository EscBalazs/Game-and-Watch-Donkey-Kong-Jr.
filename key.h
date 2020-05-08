#ifndef KEY_H
#define KEY_H

#include <QGraphicsRectItem>

class Key: public QGraphicsRectItem
{
public:
    Key();
    void activate();
    void inactivate();
};

#endif // KEY_H
