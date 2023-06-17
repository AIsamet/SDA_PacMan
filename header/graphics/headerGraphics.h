#ifndef HEADERGRAPHICS_H
#define HEADERGRAPHICS_H
#include <SDL2/SDL.h>
#include "../utils/sdlUtils.h"
#include "../main/pacman.h"


SDL_Rect getCharToSprite(char c);
void getStringToSprite(char *string, SDL_Rect *output);
SDL_Rect getNumberToSpriteFromInt(int number);
SDL_Rect getNumberToSpriteFromChar(char c);
void initHeaderSprites();
void toUpperCase(char *string);
void drawText(char *string, SDL_Rect position, int textSize);
void draw1UP();
void drawHighScore();
void drawGameHeader();

#endif