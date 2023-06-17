#include "utils/renderer.h"


void initGraphics()
{   
    // Init SDL 
    initSDL();

    // Init SDL game window
    initWindow();

    // Init the maze into the background
    initMaze();

    // Init Pacman
    initPacman();

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

        // Draw the game header
        drawGameHeader();

        // Draw the game graphics
        drawGameGraphics();

        // Draw the game footer
        drawGameFooter();

        // Handle input
        inputHandler(&quit);

        // Update the window surface
        SDL_UpdateWindowSurface(pWindow);
        // Delay the frame rate
        maintainFrameRateDelay(frameStartTime, DELAY);
    }
}