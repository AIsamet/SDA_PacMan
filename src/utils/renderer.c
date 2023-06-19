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

        // Draw the main menu if the game has not started
        if(!getIsGameStarted())
        {
            // Draw the main menu graphics
            drawMainMenuGraphics();
            // Handle game start input
            startGameInputHandler(&isGameStarted, &gameStartTime);
        }
        else
        {     
            // Draw the game header
            drawGameHeader();
 
            // Check if the game is running or not
            if (!getIsGameRunning())
            {
                // Draw waiting screen if the game is not running
                drawWaitGraphics();
            }
            else
            {
                // Draw the game graphics if the game is running
                drawGameGraphics();
            }
            
            // Draw the game footer
            drawGameFooter();
        }

        // Handle game exit input
        exitEventHandler(&quit);

        // Update the window surface
        SDL_UpdateWindowSurface(pWindow);
        // Delay the frame rate
        maintainFrameRateDelay(frameStartTime, GAME_FRAMERATE);
    }
}