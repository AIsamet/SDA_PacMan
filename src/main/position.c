#include "main/position.h"

bool isEqual(struct Position position1, struct Position position2 )
{
    return position1.x == position2.x && position1.y == position2.y;
}