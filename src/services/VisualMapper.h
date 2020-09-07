#ifndef VISUALMAPPER_H
#define VISUALMAPPER_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

struct ActiveVisualPixmapItem
{
    int8_t id;
    int16_t positionX;
    int16_t positionY;
    QPixmap image;
    bool active;
};

typedef std::pair<int, QGraphicsPixmapItem*> VisualGameItemContainerType;
typedef std::map<int, QGraphicsPixmapItem*> Container;

class VisualMapper
{
public:
    VisualMapper(
            QGraphicsScene *&scene,
            QPixmap &sprite,
            std::map<int, QGraphicsPixmapItem*> *keyContainer,
            std::map<int, QGraphicsPixmapItem*> *liveContainer);
    void map();

private:
    QGraphicsScene *mScene;
    QPixmap mSprite;
    std::map<int, QGraphicsPixmapItem*> *mKeyContainer, *mLifeContainer;

    void generateActiveVisualPixmapItem(
            std::list<ActiveVisualPixmapItem> items,
            std::map<int, QGraphicsPixmapItem*> &container
            );
};

#endif // VISUALMAPPER_H
