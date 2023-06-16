#ifndef SDLUTILS_H
#define SDLUTILS_H

#include <SDL2/SDL.h>
#include "globalVariables.h"

extern SDL_Window* pWindow;
extern SDL_Surface* pWindowSurface;
extern SDL_Surface* plancheSprites;

void initSDL();
void initWindow();
void freeSDL();

#endif //SDLUTILS_H
