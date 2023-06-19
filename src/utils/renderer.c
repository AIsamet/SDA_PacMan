#include "utils/renderer.h"


void initGraphics()
{   
    // Init SDL 
    initSDL();

    // Init SDL game window
    initWindow();

    // Init common graphics
    initCommonGraphics();

    // Init the maze
    initMaze();

    // Init Pacman
    initPacman();

    // Init the ghosts
    initGhost();

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

        // Start the game loop
        startGameLoop();

        // Handle game exit input
        exitEventHandler(&quit);

        // Update the window surface
        SDL_UpdateWindowSurface(pWindow);
        // Delay the frame rate
        maintainFrameRateDelay(frameStartTime, GAME_FRAMERATE);
    }
}