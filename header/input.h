#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "graphics.h"


void inputHandler(bool* quit, SDL_Rect* pacman_in);
void movePacmanLeft(SDL_Rect* pacman_in);
void movePacmanRight(SDL_Rect* pacman_in);
void movePacmanUp(SDL_Rect* pacman_in);
void movePacmanDown(SDL_Rect* pacman_in);


#endif