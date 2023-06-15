#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../utils/renderer.h"
#include "../customData/direction.h"


void inputHandler(bool* quit, SDL_Rect** pacman_in);
void pacmanInputHandler(SDL_Event* event, Direction* pacmanWishedDirection_in);
void checkExitEvent(bool* quit, SDL_Event* event);
void checkKeyboardEvent(bool* quit);


#endif