#include "VisualMapper.h"
#include <QBitmap>
#include <QPainter>

VisualMapper::VisualMapper(
        QGraphicsScene *&scene,
        QPixmap &sprite,
        Container *keyContainer,
        Container *lifeContainer)
{
    mSprite = sprite;
    mScene = scene;
    mKeyContainer = keyContainer;
    mLifeContainer = lifeContainer;
};

void VisualMapper::map()
{
    std::list<ActiveVisualPixmapItem> keys;
    keys.push_front({1, 74, -265, mSprite.copy(425, 140, 37, 50), true});
    keys.push_front({2, 111, -258, mSprite.copy(465, 150, 20, 50), false});
    keys.push_front({3, 121, -258, mSprite.copy(485, 150, 35, 50), false});
    keys.push_front({4, 131, -258, mSprite.copy(520, 150, 45, 50), false});
    generateActiveVisualPixmapItem(keys, *mKeyContainer);

    std::list<ActiveVisualPixmapItem> lives;
    lives.push_front({1, 350, -255, mSprite.copy(480, 200, 40, 40), true});
//    lives.push_front({2, 147, -300, mSprite.copy(452, 140, 17, 50), true});
//    lives.push_front({3, 155, -297, mSprite.copy(465, 140, 35, 50), true});
    generateActiveVisualPixmapItem(lives, *mLifeContainer);
}

void VisualMapper::generateActiveVisualPixmapItem(
        std::list<ActiveVisualPixmapItem> items,
        Container &container
        )
{
    for(auto & item: items)
    {
        QPixmap x(item.image.size());
        x.fill(Qt::green);

        QGraphicsPixmapItem *graphicItem = new QGraphicsPixmapItem(item.image);
        graphicItem->setOffset(item.positionX, item.positionY);
        graphicItem->setVisible(item.active);

        QGraphicsPixmapItem *graphicX = new QGraphicsPixmapItem(x);
        graphicX->setOffset(item.positionX, item.positionY);
        graphicX->setOpacity(0.2);

        container.insert(VisualGameItemContainerType(item.id, graphicItem));
        mScene->addItem(graphicX);
        mScene->addItem(graphicItem);
    }
}
