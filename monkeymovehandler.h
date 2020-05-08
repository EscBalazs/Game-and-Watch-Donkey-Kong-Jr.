#ifndef MONKEYMOVEHANDLER_H
#define MONKEYMOVEHANDLER_H

#include <QObject>

class MonkeyMoveHandler: public QObject
{
    Q_OBJECT
public:
    std::int16_t move(std::int32_t, std::int16_t currentMonkeyId);
};

#endif // MONKEYMOVEHANDLER_H
