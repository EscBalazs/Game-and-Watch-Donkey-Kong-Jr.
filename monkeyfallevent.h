#ifndef MONKEYFALLEVENT_H
#define MONKEYFALLEVENT_H

#include <QGraphicsRectItem>
#include <QObject>

class MonkeyFallEvent: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void startFall(std::int16_t);
private:
    std::int16_t monkeyPositionId;
    std::int16_t monkeyStartPositionId;
public slots:
    void fall();
};

#endif // MONKEYFALLEVENT_H
