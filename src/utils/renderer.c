#include "utils/renderer.h"
#include "main/pacman.h"


void initGraphics()
{    
    // Draw the game background
    drawGameBackground();

    // Init the maze into the background
    initMaze();

    // Spawn Pacman
    spawnPacman();

    // Use graphicsHandler to render the game
    graphicsHandler();
}

void graphicsHandler()
{
    bool quit = false;

    while (!quit) 
    {
        // Start the frame timer
        clock_t frameStartTime = clock();

        // Clear the window surface
        SDL_FillRect(pWindowSurface, 0, 0);

        // Draw the game graphics
        drawGameGraphics();

        // Handle input
        inputHandler(&quit);

        // Update the window surface
        SDL_UpdateWindowSurface(pWindow);
        // Delay the frame rate
        maintainFrameRateDelay(frameStartTime, DELAY);
    }
}