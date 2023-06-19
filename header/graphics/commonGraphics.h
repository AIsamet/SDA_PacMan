#ifndef COMMONGRAPHICS_H
#define COMMONGRAPHICS_H
#include <SDL2/SDL.h>
#include "../utils/sdlUtils.h"
#include "../main/pacman.h"

extern SDL_Rect alphabetSprites[];
extern SDL_Rect alphabetFirstLetter;

extern SDL_Rect numbersSprites[];
extern SDL_Rect numbersFirstNumber;

extern int blinkingCounter;

void initCommonGraphics();
SDL_Rect getCharToSprite(char c);
void getStringToSprite(char *string, SDL_Rect *output);
SDL_Rect getNumberToSpriteFromInt(int number);
SDL_Rect getNumberToSpriteFromChar(char c);
void toUpperCase(char *string);
void drawText(char *string, SDL_Rect position, int textSize);

#endif