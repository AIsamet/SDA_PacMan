#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include "utils/sdlUtils.h"
#include "input.h"
#include "maze.h"


// Global variables
extern SDL_Window* pWindow;
extern SDL_Surface* pWindowSurface;
extern SDL_Surface* plancheSprites;
extern SDL_Rect src_bg;
extern SDL_Rect bg;
extern int map_array[27][21];
extern SDL_Rect ghost_r;
extern SDL_Rect ghost_l;
extern SDL_Rect ghost_d;
extern SDL_Rect ghost_u;
extern SDL_Rect ghost;

extern SDL_Rect pacman_spawn;
extern SDL_Rect pacman_eat;
extern SDL_Rect pacman_closed;
extern SDL_Rect pacman_r;
extern SDL_Rect pacman_l;
extern SDL_Rect pacman_d;
extern SDL_Rect pacman_u;
extern SDL_Rect pacman;
extern SDL_Rect* pacman_in;

extern int count;
extern bool isPacmanEating;

// Graphics functions
void initGraphics();
void draw();
void animateGhost();
void animatePacman();
void graphicsHandler();
void destroyGraphics();
void movePacmanLeft(SDL_Rect** pacman_in);
void movePacmanRight(SDL_Rect** pacman_in);
void movePacmanUp(SDL_Rect** pacman_in);
void movePacmanDown(SDL_Rect** pacman_in);
bool isPacmanInMapLimits(double x, double y);
void getCurrentPositionInArray(double* x, double* y); // TEST

#endif