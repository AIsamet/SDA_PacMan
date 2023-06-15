#ifndef COORDINATES_H
#define COORDINATES_H

#include <stdbool.h>
#include "customData/direction.h"

struct Coordinates
{
    int x;
    int y;
};

bool isEqual(struct Coordinates coordinates1, struct Coordinates coordinates2);
void sumCoordinatesWithOffset(struct Coordinates* coordinates, Direction direction, int offset);

#endif