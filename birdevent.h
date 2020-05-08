#ifndef BIRDEVENT_H
#define BIRDEVENT_H

#include <QGraphicsRectItem>
#include <QObject>

class BirdEvent: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void startFly();
private:
    std::int16_t currentBirdId = 1;
public slots:
    void move();
};

#endif // BIRDEVENT_H
