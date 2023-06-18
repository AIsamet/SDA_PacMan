#include "main/coordinates.h"


bool isEqual(struct Coordinates coordinates1, struct Coordinates coordinates2)
{
    return coordinates1.x == coordinates2.x && coordinates1.y == coordinates2.y;
}

void sumCoordinatesWithOffset(struct Coordinates* coordinates, Direction direction, int offset)
{
    if (direction == DIRECTION_RIGHT)
    {
        coordinates->x += offset;
    }
    else if (direction == DIRECTION_LEFT)
    {
        coordinates->x -= offset;
    }
    else if (direction == DIRECTION_UP)
    {
        coordinates->y -= offset;
    }
    else if (direction == DIRECTION_DOWN)
    {
        coordinates->y += offset;
    }
}
