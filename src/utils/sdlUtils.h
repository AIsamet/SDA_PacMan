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
void printRectValues(SDL_Rect rect);
void extractSpritesIterativelyWithOffsets(SDL_Rect inputSprite, SDL_Rect *outputSpriteArray, int numberOfSprites, int xOffset, int yOffset);

#endif //SDLUTILS_H