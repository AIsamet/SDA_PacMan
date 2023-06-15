#include "utils/renderer.h"

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

    while (!quit) {
        inputHandler(&quit, &pacman_in);
        drawGameGraphics();
        SDL_Delay(20);
        SDL_UpdateWindowSurface(pWindow);
    }

    destroyGraphics();
}