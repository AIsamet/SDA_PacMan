#ifndef POSITION_H
#define POSITION_H

#include <stdbool.h>
#include "customData/direction.h"

struct Position
{
    int x;
    int y;
};

bool isEqual(struct Position position1, struct Position position2);

#endif