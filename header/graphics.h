#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "input.h"


// Global variables
extern SDL_Window* pWindow;
extern SDL_Surface* win_surf;
extern SDL_Surface* plancheSprites;
extern SDL_Rect src_bg;
extern SDL_Rect bg;
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

// Graphics functions
void initWindow();
void initSDL();
void initGraphics();
void draw();
void animateGhost();
void graphicsHandler();
void destroyGraphics();
void movePacmanLeft(SDL_Rect** pacman_in);
void movePacmanRight(SDL_Rect** pacman_in);
void movePacmanUp(SDL_Rect** pacman_in);
void movePacmanDown(SDL_Rect** pacman_in);
bool isPacmanInMapLimits(int x, int y);

#endif