#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <QtDebug>
#include <QKeyEvent>
#include "bird.h"
#include "birdevent.h"
#include "game.h"
#include "key.h"
#include "visual_items/crocodile.h"
#include "visual_events/CrocodileEvent.h"
#include "keyEvent.h"
#include "monkey.h"
#include "monkeyfallevent.h"

typedef std::pair<int, Monkey*> MonkeyType;
typedef std::pair<int, Bird*> BirdType;
typedef std::pair<int, Life*> LifeType;
typedef std::pair<int, Key*> KeyType;
typedef std::pair<int, Crocodile*> CrocodileType;

Game::Game(QWidget *parent)
{
    mainWindow = parent;
    scene = new QGraphicsScene();
    createLifeHud(scene);
    createMonkies(scene);
    createBirds(scene);
    createKeys(scene);
    createCrocodiles(scene);
    setScene(scene);

    BirdEvent *birdEvent = new BirdEvent();
    birdEvent->startFly();

    KeyEvent *keyEvent = new KeyEvent();
    keyEvent->startSwing();

    CrocodileEvent *crocodileEvent = new CrocodileEvent();
    crocodileEvent->startMove();

    show();
}

void Game::triggerBeforeBirdMove(std::int16_t currentBirdId)
{
    checkDieByBird(currentBirdId);
}

void Game::triggerAfterBirdMove(std::int16_t previousBirdId, std::int16_t currentBirdId)
{
    birdContainer.at(previousBirdId)->inactivate();
    birdContainer.at(currentBirdId)->activate();
}

void Game::triggerAfterCrocodileMove(std::int16_t previousCrocodiledId, std::int16_t currentCeocodileId)
{
    crocodileContainer.at(previousCrocodiledId)->inactivate();
    crocodileContainer.at(currentCeocodileId)->activate();
}

void Game::triggerAfterKeyMove(int16_t keyPosition)
{
    if (keyPosition > 4)
    {
        keyPosition = 4;
    }
    keyContainer.at(1)->inactivate();
    keyContainer.at(2)->inactivate();
    keyContainer.at(3)->inactivate();
    keyContainer.at(4)->inactivate();
    keyContainer.at(keyPosition)->activate();
}

void Game::checkDieByBird(std::int16_t currentBirdId)
{
    if (currentBirdId == 2 && currentMonkeyId == 2)
    {
        removeLifeAndRestartOrGameOver();
    }
    if (currentBirdId == 3 && currentMonkeyId == 4)
    {
        removeLifeAndRestartOrGameOver();
    }
}

void Game::removeLifeAndRestartOrGameOver()
{
    if (0 == lifes)
    {
        mainWindow->close();
    }

    lifeContainer.at(lifes)->inactivate();
    lifes--;
    setMonkeyPositionId(1);
}

void Game::keyPressEvent(QKeyEvent *event)
{
    monkeyContainer.at(currentMonkeyId)->inactivate();
    handleKeyPress(event);
    monkeyContainer.at(currentMonkeyId)->activate();

    if (4 == currentMonkeyId)
    {
        MonkeyFallEvent *monkeyFallEvent = new MonkeyFallEvent();
        monkeyFallEvent->startFall(3);
    }

    if (10 == currentMonkeyId)
    {
        MonkeyFallEvent *monkeyFallEvent = new MonkeyFallEvent();
        monkeyFallEvent->startFall(9);
    }

    if (17 == currentMonkeyId)
    {
        MonkeyFallEvent *monkeyFallEvent = new MonkeyFallEvent();
        monkeyFallEvent->startFall(16);
    }

    if (19 == currentMonkeyId)
    {
        MonkeyFallEvent *monkeyFallEvent = new MonkeyFallEvent();
        monkeyFallEvent->startFall(18);
    }
}

void Game::setMonkeyPositionId(std::int16_t positionId)
{
    monkeyContainer.at(currentMonkeyId)->inactivate();
    currentMonkeyId = positionId;
    monkeyContainer.at(currentMonkeyId)->activate();
}

void Game::handleKeyPress(QKeyEvent *event)
{
    std::int16_t nextMonkeyId = monkeyMoveHandler->move(event->key(), currentMonkeyId);

    if (nextMonkeyId > 0)
    {
        currentMonkeyId = monkeyMoveHandler->move(event->key(), currentMonkeyId);
    }
}

void Game::createLifeHud(QGraphicsScene *scene)
{
    std::list<ActiveVisualGameItem> lives;
    lives.push_front({1, 12, -5, true});
    lives.push_front({2, 13, -5, true});
    lives.push_front({3, 14, -5, true});

    generateActiveVisualGameItem<Life, LifeType>(lives, lifeContainer);
}

void Game::createMonkies(QGraphicsScene *scene)
{
    std::list<ActiveVisualGameItem> monkeys;
    monkeys.push_front({1, 3, 0,  true});
    monkeys.push_front({2, 3, -1, false});
    monkeys.push_front({3, 5, 0,  false});
    monkeys.push_front({4, 5, -1, false});
    monkeys.push_front({5, 7, 0,  false});
    monkeys.push_front({6, 7, -1, false});
    monkeys.push_front({7, 9, 0, false});
    monkeys.push_front({8, 9, -1, false});
    monkeys.push_front({9, 11, 0, false});
    monkeys.push_front({10, 11, -1, false});
    monkeys.push_front({11, 13, 0, false});
    monkeys.push_front({12, 13, -1, false});
    monkeys.push_front({13, 13, -2, false});
    monkeys.push_front({14, 11, -2, false});
    monkeys.push_front({15, 11, -3, false});
    monkeys.push_front({16, 9, -2, false});
    monkeys.push_front({17, 9, -3, false});
    monkeys.push_front({18, 7, -2, false});
    monkeys.push_front({19, 7, -3, false});

    generateActiveVisualGameItem<Monkey, MonkeyType>(monkeys, monkeyContainer);
}

void Game::createBirds(QGraphicsScene *scene)
{
    std::list<ActiveVisualGameItem> birds;
    birds.push_front({1, 1, -1, true});
    birds.push_front({2, 2, -1, false});
    birds.push_front({3, 4, -1, false});
    birds.push_front({4, 6, -1, false});
    birds.push_front({5, 8, -1, false});
    birds.push_front({6, 10, -1, false});
    birds.push_front({7, 12, -1, false});
    birds.push_front({8, 14, -1, false});

    generateActiveVisualGameItem<Bird, BirdType>(birds, birdContainer);
}

void Game::createKeys(QGraphicsScene *scene)
{
    std::list<ActiveVisualGameItem> keys;
    keys.push_front({1, 8, -5, true});
    keys.push_front({2, 9, -5, false});
    keys.push_front({3, 10, -5, false});
    keys.push_front({4, 11, -5, false});

    generateActiveVisualGameItem<Key, KeyType>(keys, keyContainer);
}

void Game::createCrocodiles(QGraphicsScene *scene)
{
    std::list<ActiveVisualGameItem> crocodiles;

    crocodiles.push_front({1, 4, -2, true});
    crocodiles.push_front({2, 6, -2, false});
    crocodiles.push_front({3, 8, -2, false});
    crocodiles.push_front({4, 10, -2, false});
    crocodiles.push_front({5, 12, -2, false});
    crocodiles.push_front({6, 14, -2, false});
    crocodiles.push_front({7, 14, 0, false});
    crocodiles.push_front({8, 12, 0, false});
    crocodiles.push_front({9, 10, 0, false});
    crocodiles.push_front({10, 8, 0, false});
    crocodiles.push_front({11, 6, 0, false});
    crocodiles.push_front({12, 4, 0, false});
    crocodiles.push_front({13, 2, 0, false});

    generateActiveVisualGameItem<Crocodile, CrocodileType>(crocodiles, crocodileContainer);
}

template <class ItemType, class ContainerType>
void Game::generateActiveVisualGameItem(std::list<ActiveVisualGameItem> items, std::map<int, ItemType*> &container)
{
    for(auto const& item: items)
    {
        ItemType *newItem = new ItemType();
        newItem->setRect(0, 0, 10, 10);
        newItem->setPos(item.positionX * scale, item.positionY * scale);
        if (item.active)
        {
            newItem->activate();
        }
        container.insert(ContainerType(item.id, newItem));
        scene->addItem(newItem);
    }
}
