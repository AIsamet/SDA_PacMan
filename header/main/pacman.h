#ifndef PACMAN_H
#define PACMAN_H

#include <SDL2/SDL.h>
#include "../customData/direction.h"
#include "../graphics/gameGraphics.h"
#include "../customData/mazeObstacles.h"
#include "../utils/spriteUtils.h"
#include "main/coordinates.h"
#include "main/maze.h"
#include "main/input.h"

void spawnPacman();
void pacmanEventHandler();
bool isObstacle(struct Coordinates coordinates);
bool isColliding(struct Coordinates coordinates, int hitboxOffset);
int canPacmanMove(Direction direction);
void pacmanBlit(SDL_Rect srcRect);
void drawPacman();
struct Coordinates movePacmanOnGrid(struct Coordinates *pacmanUiPos);


#endif //PACMAN_H
