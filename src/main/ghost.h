#ifndef GHOST_H
#define GHOST_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "../main/maze.h"
#include "../utils/globalVariables.h"
#include "../customData/ghostsColors.h"

void initGhost();
void spawnGhost();
void ghostBlit(SDL_Rect srcRect, int ghostIndex);



#endif