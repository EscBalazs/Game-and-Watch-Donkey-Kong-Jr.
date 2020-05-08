#include <monkeymovehandler.h>

std::int16_t MonkeyMoveHandler::move(std::int32_t key, std::int16_t currentMonkeyId)
{
    if (currentMonkeyId == 1 && key == Qt::Key_Right)
    {
        return 3;
    }
    if (currentMonkeyId == 1 && key == Qt::Key_Space)
    {
        return 2;
    }


    if (currentMonkeyId == 2 && key == Qt::Key_Down)
    {
        return 1;
    }
    if (currentMonkeyId == 2 && key == Qt::Key_Right)
    {
        return 4;
    }


    if (currentMonkeyId == 3 && key == Qt::Key_Left)
    {
        return 1;
    }
    if (currentMonkeyId == 3 && key == Qt::Key_Right)
    {
        return 5;
    }
    if (currentMonkeyId == 3 && key == Qt::Key_Space)
    {
        return 4;
    }


    if (currentMonkeyId == 5 && key == Qt::Key_Left)
    {
        return 3;
    }
    if (currentMonkeyId == 5 && key == Qt::Key_Right)
    {
        return 7;
    }
    if (currentMonkeyId == 5 && key == Qt::Key_Space)
    {
        return 6;
    }


    if (currentMonkeyId == 6 && key == Qt::Key_Down)
    {
        return 5;
    }


    if (currentMonkeyId == 7 && key == Qt::Key_Left)
    {
        return 5;
    }
    if (currentMonkeyId == 7 && key == Qt::Key_Right)
    {
        return 9;
    }
    if (currentMonkeyId == 7 && key == Qt::Key_Space)
    {
        return 8;
    }


    if (currentMonkeyId == 8 && key == Qt::Key_Down)
    {
        return 7;
    }


    if (currentMonkeyId == 9 && key == Qt::Key_Left)
    {
        return 7;
    }
    if (currentMonkeyId == 9 && key == Qt::Key_Right)
    {
        return 11;
    }
    if (currentMonkeyId == 9 && key == Qt::Key_Space)
    {
        return 10;
    }


    if (currentMonkeyId == 11 && key == Qt::Key_Left)
    {
        return 9;
    }
    if (currentMonkeyId == 11 && key == Qt::Key_Up)
    {
        return 12;
    }


    if (currentMonkeyId == 12 && key == Qt::Key_Down)
    {
        return 11;
    }
    if (currentMonkeyId == 12 && key == Qt::Key_Up)
    {
        return 13;
    }


    if (currentMonkeyId == 13 && key == Qt::Key_Left)
    {
        return 14;
    }
    if (currentMonkeyId == 13 && key == Qt::Key_Down)
    {
        return 12;
    }


    if (currentMonkeyId == 14 && key == Qt::Key_Left)
    {
        return 16;
    }
    if (currentMonkeyId == 14 && key == Qt::Key_Right)
    {
        return 13;
    }
    if (currentMonkeyId == 14 && key == Qt::Key_Space)
    {
        return 15;
    }


    if (currentMonkeyId == 15 && key == Qt::Key_Down)
    {
        return 14;
    }


    if (currentMonkeyId == 15 && key == Qt::Key_Left)
    {
        return 17;
    }


    if (currentMonkeyId == 16 && key == Qt::Key_Left)
    {
        return 18;
    }
    if (currentMonkeyId == 16 && key == Qt::Key_Right)
    {
        return 14;
    }
    if (currentMonkeyId == 16 && key == Qt::Key_Space)
    {
        return 17;
    }


    if (currentMonkeyId == 18 && key == Qt::Key_Right)
    {
        return 16;
    }
    if (currentMonkeyId == 18 && key == Qt::Key_Space)
    {
        return 19;
    }


    return 0;
}
