#include "game.h"


// Implement the game logic functions here

void initGame() {
    runGraphics();
    updateGame();
}

void updateGame() {
    bool quit = false;

    while (!quit) {
        handleInput(&quit);
        draw();
        SDL_Delay(20);
        SDL_UpdateWindowSurface(pWindow);
    }
}

void renderGame() {
    // Render the game graphics
}

void handleInputGame() {
    // Handle user input for the game
}