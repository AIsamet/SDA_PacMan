#include "utils/renderer.h"
#include "main/pacman.h"

void initGraphics(){
    initSDL();
    initWindow();
    graphicsHandler();
}

void destroyGraphics()
{
    freeSDL();
}

void graphicsHandler(){
    bool quit = false;

    drawGameBackground();
    initMaze();
    spawnPacman();

    while (!quit) {
        inputHandler(&quit, &pacman_in);
        drawGameGraphics();
        SDL_Delay(20);
        SDL_UpdateWindowSurface(pWindow);
    }

    destroyGraphics();
}