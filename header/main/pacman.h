#ifndef PACMAN_H
#define PACMAN_H

#include <SDL2/SDL.h>
#include "../customData/direction.h"
#include "main/position.h"
#include "main/maze.h"
#include "main/input.h"

void spawnPacman();
void pacmanEventHandler();

#endif //PACMAN_H
