#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "../main/maze.h"
#include "../main/pacman.h"
#include "../utils/globalVariables.h"
#include "../main/game.h"


extern SDL_Rect src_bg;
extern SDL_Rect bg;

extern SDL_Rect ghost_r;
extern SDL_Rect ghost_l;
extern SDL_Rect ghost_d;
extern SDL_Rect ghost_u;
extern SDL_Rect ghost;

extern int pacmanAnimationCount;
extern int pacmanDeathAnimationCount;

void animateGhost();
void drawGameBackground();
void drawGameHeader();
void drawGameFooter();
void drawGameOverGraphics();
void drawWaitGraphics();
void drawGameGraphics();
void maintainFrameRateDelay(clock_t frameStartTime, int frameRate);
void startGameGraphics();

#endif //GAMEGRAPHICS_H