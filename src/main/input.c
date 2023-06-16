#include "main/input.h"


void checkKeyboardEvent(bool* quit) {
    int nbKeys;
    const Uint8* keyboardState = SDL_GetKeyboardState(&nbKeys);
    if (keyboardState[SDL_SCANCODE_ESCAPE]) {
        *quit = true;
    }
}

void pacmanInputHandler(SDL_Event* event, Direction* pacmanWishedDirection_in) {
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A])
        *pacmanWishedDirection_in = DIRECTION_LEFT;
    else if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D])
        *pacmanWishedDirection_in = DIRECTION_RIGHT;
    else if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_W])
        *pacmanWishedDirection_in = DIRECTION_UP;
    else if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_S])
        *pacmanWishedDirection_in = DIRECTION_DOWN;
}

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

void inputHandler(bool* quit) {
    SDL_Event event;
    checkExitEvent(quit, &event);
    checkKeyboardEvent(quit);
}