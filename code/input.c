#include "input.h"


void inputHandler(bool* quit, SDL_Rect* pacman_in) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *quit = true;
                break;
            default:
                break;
        }
    }

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


void movePacmanLeft(SDL_Rect* pacman_in) {
    pacman.x -= 4;
}

void movePacmanRight(SDL_Rect* pacman_in) {
    pacman.x += 4;
}

void movePacmanUp(SDL_Rect* pacman_in) {
    pacman.y -= 4;
}

void movePacmanDown(SDL_Rect* pacman_in) {
    pacman.y += 4;
}