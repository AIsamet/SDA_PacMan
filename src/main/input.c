#include "input.h"

// Check if the user pressed the escape key and quit the game if so by setting the quit flag to true
void checkKeyboardExitEvent(bool* quit) 
{
    int nbKeys;
    const Uint8* keyboardState = SDL_GetKeyboardState(&nbKeys);
    if (keyboardState[SDL_SCANCODE_ESCAPE]) {
        *quit = true;
    }
}

// Check if the user pressed the exit button (window close button) and quit the game if so by setting the quit flag to true
void checkExitEvent(bool* quit) 
{
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
}

void exitEventHandler(bool* quit) 
{
    checkExitEvent(quit);
    checkKeyboardExitEvent(quit);
}

// Check if the user pressed the arrow keys or WASD keys
void pacmanInputHandler(Direction* pacmanWishedDirection_in) 
{
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

// Check if the user pressed the enter key to start the game
void startGameInputHandler(bool* isGameStarted, clock_t* gameStartTime) 
{   
    const Uint8* keys = SDL_GetKeyboardState(NULL);

    if (keys[SDL_SCANCODE_RETURN])
        *isGameStarted = true;
        *gameStartTime = clock();
}