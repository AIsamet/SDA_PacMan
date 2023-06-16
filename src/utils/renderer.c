#include "utils/renderer.h"
#include "main/pacman.h"


void initGraphics(){
    drawGameBackground();
    initMaze();
    spawnPacman();
    graphicsHandler();
}

void graphicsHandler(){
    bool quit = false;

    while (!quit) {
        clock_t frameStartTime = clock();
        SDL_FillRect(pWindowSurface, 0, 0);
        drawGameGraphics();
        inputHandler(&quit);
        SDL_UpdateWindowSurface(pWindow);
        maintainFrameRateDelay(frameStartTime, DELAY);
    }
}