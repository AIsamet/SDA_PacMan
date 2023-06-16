#ifndef GAMEGRAPHICS_H
#define GAMEGRAPHICS_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "../main/maze.h"
#include "../main/pacman.h"
#include "../utils/globalVariables.h"


extern SDL_Rect src_bg;
extern SDL_Rect bg;

extern SDL_Rect ghost_r;
extern SDL_Rect ghost_l;
extern SDL_Rect ghost_d;
extern SDL_Rect ghost_u;
extern SDL_Rect ghost;

extern int ghostAnimationCount;
extern int pacmanAnimationCount;

void animateGhost();
void drawGameBackground();
void drawGameGraphics();
void maintainFrameRateDelay(clock_t frameStartTime, Uint32 desiredFrameDelayInMs);


#endif //GAMEGRAPHICS_H