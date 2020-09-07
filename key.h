#ifndef KEY_H
#define KEY_H

#include <QPixmap>

class Key: public QPixmap
{
public:
    Key();
    void activate();
    void inactivate();
};

#endif // KEY_H
