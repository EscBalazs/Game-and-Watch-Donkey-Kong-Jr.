#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QGraphicsRectItem>
#include <QObject>

class KeyEvent: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    void startSwing();
private:
    std::int16_t currentKeyPosition = 1;
    bool goRight {true};
public slots:
    void move();
};

#endif // BIRDEVENT_H
