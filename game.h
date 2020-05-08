#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "monkey.h"
#include "bird.h"
#include "life.h"
#include "key.h"
#include "visual_items/crocodile.h"
#include "monkeymovehandler.h"

struct ActiveVisualGameItem
{
    int8_t id;
    int8_t positionX;
    int8_t positionY;
    bool active;
};

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent *event);
    void createLifeHud(QGraphicsScene *scene);
    void createMonkies(QGraphicsScene *scene);
    void createBirds(QGraphicsScene *scene);
    void createCrocodiles(QGraphicsScene *scene);
    void handleKeyPress(QKeyEvent *event);
    void checkDieByBird(std::int16_t);

    QGraphicsScene *scene;

    MonkeyMoveHandler *monkeyMoveHandler;

    std::int16_t scale = 25;
    std::map<int, Monkey*> monkeyContainer;
    std::map<int, Bird*> birdContainer;
    std::map<int, Life*> lifeContainer;
    std::map<int, Key*> keyContainer;
    std::map<int, Crocodile*>  crocodileContainer;
    std::int16_t currentMonkeyId = 1;
    std::int16_t currentBirdId = 1;
    std::int8_t lifes = 3;

    void triggerAfterKeyMove(int16_t keyPosition);
private:
    void removeLifeAndRestartOrGameOver();

    QWidget * mainWindow;

    void createKeys(QGraphicsScene *scene);
public slots:
    void triggerAfterCrocodileMove(std::int16_t, std::int16_t);
    void triggerBeforeBirdMove(std::int16_t);
    void triggerAfterBirdMove(std::int16_t, std::int16_t);
    void setMonkeyPositionId(std::int16_t);
    template <class ItemType, class ContainerType>
    void generateActiveVisualGameItem(std::list<ActiveVisualGameItem> items, std::map<int, ItemType*> &container);
};

#endif // GAME_H
