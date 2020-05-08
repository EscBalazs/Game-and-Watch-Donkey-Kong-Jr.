#ifndef CROCODILEEVENT_H
#define CROCODILEEVENT_H
#include <QGraphicsRectItem>
#include <QObject>

class CrocodileEvent: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void startMove();
private:
    std::int16_t currentCrocodiledId = 1;
public slots:
    void move();
};

#endif // CROCODILEEVENT_H
