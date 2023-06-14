#ifndef SDA_PACMAN_MAZE_H
#define SDA_PACMAN_MAZE_H

#include <SDL2/SDL.h>
#include "position.h"
#include "graphics.h"

void initMaze();
void drawPacGum(SDL_Rect pacGum, SDL_Rect superPackGum);
struct Position getGridToUIPosition(struct Position gridPosition);
void drawIntoMaze(SDL_Rect sprite, struct Position positionToDraw, int x, int y, int w, int h);

#endif //SDA_PACMAN_MAZE_H
