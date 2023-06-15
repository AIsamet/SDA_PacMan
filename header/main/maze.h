#ifndef SDA_PACMAN_MAZE_H
#define SDA_PACMAN_MAZE_H

#include <SDL2/SDL.h>
#include "../main/coordinates.h"
#include "../utils/renderer.h"
#include "../utils/globalVariables.h"
#include "../customData/mazeObstacles.h"

#define PACGUM_X 6
#define PACGUM_Y 6
#define PACGUM_W 26
#define PACGUM_H 26

void initMaze();
void drawPacGum(SDL_Rect pacGum, SDL_Rect superPackGum);
void copyMapArray();
struct Coordinates getUIToGridPosition(struct Coordinates UIPos);
struct Coordinates getGridToUIPosition(struct Coordinates gridPosition);
void drawIntoMaze(SDL_Rect sprite, struct Coordinates positionToDraw, int x, int y, int w, int h);
struct Coordinates searchElementInMazeArray(MazeObstacles element);
void removeElementFromMazeArray(MazeObstacles element);
int getMapArrayValue(int mapArray[27][21] , int x, int y);
int getElementFromMazeArray(struct Coordinates pos);
bool isInArrayRange (struct Coordinates pos);
void setElementInMazeArray(MazeObstacles element, struct Coordinates pos);
bool isObstacle(struct Coordinates coordinates);
bool isColliding(struct Coordinates coordinates, int hitboxOffset);
void displayMaze();


#endif //SDA_PACMAN_MAZE_H
