#ifndef HEADERGRAPHICS_H
#define HEADERGRAPHICS_H
#include <SDL2/SDL.h>
#include "../utils/sdlUtils.h"
#include "../main/pacman.h"


void initHeaderSprites();
SDL_Rect charToAlphabet(char c);
void stringToAlphabet(char *string, SDL_Rect *output);
void drawGameHeader();

#endif