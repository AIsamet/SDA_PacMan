#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../utils/renderer.h"
#include "../customData/direction.h"
#include "../main/game.h"


void checkKeyboardExitEvent(bool* quit);
void checkExitEvent(bool* quit);
void exitEventHandler(bool* quit);
void pacmanInputHandler(Direction* pacmanWishedDirection_in);
void mainMenuInputHandler(bool *mainMenuQuit_in);

#endif