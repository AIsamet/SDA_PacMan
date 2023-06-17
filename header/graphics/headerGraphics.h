#ifndef HEADERGRAPHICS_H
#define HEADERGRAPHICS_H
#include <SDL2/SDL.h>
#include "../utils/sdlUtils.h"
#include "../main/pacman.h"


SDL_Rect getCharSprite(char c);
void stringToSprite(char *string, SDL_Rect *output);
void initHeaderSprites();
void drawText(char *string, SDL_Rect position, int textSize);
void drawScoreTitle();
void toUpperCase(char *string);
void drawGameHeader();

#endif