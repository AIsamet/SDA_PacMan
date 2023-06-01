#include "input.h"


void checkExitEvent(bool* quit, SDL_Event* event) {
    while (SDL_PollEvent(event)) {
        switch (event->type) {
            case SDL_QUIT:
                *quit = true;
                break;
            default:
                break;
        }
    }
}

void checkKeyboardEvent(bool* quit, SDL_Rect** pacman_in) {
    int nbKeys;
    const Uint8* keyboardState = SDL_GetKeyboardState(&nbKeys);
    if (keyboardState[SDL_SCANCODE_ESCAPE]) {
        *quit = true;
    }
    else if (keyboardState[SDL_SCANCODE_LEFT]) {
        movePacmanLeft(pacman_in);
    }
    else if (keyboardState[SDL_SCANCODE_RIGHT]) {
        movePacmanRight(pacman_in);
    }
    else if (keyboardState[SDL_SCANCODE_UP]) {
        movePacmanUp(pacman_in);
    }
    else if (keyboardState[SDL_SCANCODE_DOWN]) {
        movePacmanDown(pacman_in);
    }
}

void inputHandler(bool* quit, SDL_Rect** pacman_in) {
    SDL_Event event;
    checkExitEvent(quit, &event);
    checkKeyboardEvent(quit, pacman_in);
}
