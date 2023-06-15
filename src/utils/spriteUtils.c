#include "utils/spriteUtils.h"

struct Coordinates getCellCenter(struct Coordinates coordinates)
{
    struct Coordinates result = {
        coordinates.x + CELL_SIZE / 2,
        coordinates.y + CELL_SIZE / 2,
    };
    return result;
}