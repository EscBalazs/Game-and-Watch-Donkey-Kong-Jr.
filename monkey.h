#ifndef MONKEY_H
#define MONKEY_H

#include <QGraphicsRectItem>

class Monkey: public QGraphicsRectItem
{
public:
    Monkey();
    void activate();
    void inactivate();
};

#endif // MONKEY_H
