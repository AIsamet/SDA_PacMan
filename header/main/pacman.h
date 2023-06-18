#ifndef PACMAN_H
#define PACMAN_H
#include <SDL2/SDL.h>
#include "../customData/direction.h"
#include "../customData/mazeObstacles.h"
#include "../graphics/gameGraphics.h"
#include "../utils/spriteUtils.h"
#include "main/coordinates.h"
#include "main/maze.h"
#include "main/input.h"


void initPacman();
void spawnPacman();
void pacmanEventHandler();
int canPacmanMove(Direction direction);
void pacmanBlit(SDL_Rect srcRect);
void updateUnderPacmanGridElement();
int getPacmanCurrentAnimationIndex();
void updatePacmanDirection(Direction pacmanWantedDirection);
SDL_Rect getPacmanSprite(Direction direction, int animationIndex);
void drawPacman();
SDL_Rect getWantedDirectionArrowSprite(Direction direction);
void drawWantedDirectionArrow();

#endif //PACMAN_H