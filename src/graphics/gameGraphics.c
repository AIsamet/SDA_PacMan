#include "gameGraphics.h"


SDL_Rect src_game_bg = { 369,3, 168,216 };
SDL_Rect game_bg = { 0, HEADER_SCREEN_HEIGHT, MAZE_WIDTH, MAZE_HEIGHT };

SDL_Rect src_readyImg = { SOURCE_READY_X_POSITION, SOURCE_READY_Y_POSITION, SOURCE_READY_WIDTH, SOURCE_READY_HEIGHT };
SDL_Rect readyImg = { READY_X_POSITION, READY_Y_POSITION, READY_WIDTH, READY_HEIGHT };

int pacmanAnimationCount = 0;
int pacmanDeathAnimationCount = 0;

void drawGameBackground()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the background image onto the window surface
    SDL_BlitScaled(plancheSprites, &src_game_bg, pWindowSurface, &game_bg);
}


void drawWaitGraphics()
{
    // Draw the background image onto the window surface
    drawGameBackground();

    // Draw maze
    drawMazeElements();

    // Spawn pacman
    spawnPacman();

    // Draw arrow
    drawWantedDirectionArrow();

    // Get direction input 
    pacmanEventHandler();

    // Spawn the ghosts
    spawnGhost(); // TEST

    // Draw ready image
    if (blinkingCounter % TEXT_BLINKING_SPEED)
    {
    SDL_BlitScaled(plancheSprites, &src_readyImg, pWindowSurface, &readyImg);
    }
}

void drawGameGraphics()
{
    // Draw the background image onto the window surface
    drawGameBackground();

    // Draw maze
    drawMazeElements();

    // Draw pacman
    drawPacman();

    // Spawn the ghosts
    spawnGhost(); // TEST

    // Draw arrow
    drawWantedDirectionArrow();

    // Get keyboard events
    pacmanEventHandler();
    pacmanAnimationCount++;
    pacmanDeathAnimationCount++;
}

// function to maintain a specified frame rate
void maintainFrameRateDelay(clock_t frameStartTime, int frameRate)
{
    // Calculate the duration of the current frame in milliseconds
    const int64_t frameDurationMs = (clock() - frameStartTime) * 1000 / CLOCKS_PER_SEC;

    // Calculate the desired frame delay in milliseconds based on the desired frames per second (FPS)
    const int desiredFrameDelayInMs = 1000 / frameRate;

    // Calculate the remaining delay needed to maintain the desired frame rate
    const int64_t remainingDelay = desiredFrameDelayInMs - frameDurationMs;

    // If there is still time remaining before the next frame, delay the execution
    if (remainingDelay > 0)
        SDL_Delay((Uint32)remainingDelay);
}

void startGameGraphics()
{
    bool gameQuit = false;

    while (!getIsGameOver() && !gameQuit)
    {

        // Start the frame timer
        clock_t frameStartTime = clock();

        // Clear the window surface
        SDL_FillRect(pWindowSurface, 0, 0);
      
        // Draw the game header
        drawGameHeader();

        // Check if the game is running or not
        if (gameReadyTimer.isRunning)
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
    
        // Handle game exit input
        exitEventHandler(&gameQuit);

        // Update the window surface
        SDL_UpdateWindowSurface(pWindow);
        
        // Delay the frame rate
        maintainFrameRateDelay(frameStartTime, GAME_FRAMERATE);

        // Update the game timer
        Timer_update(&gameReadyTimer);
    }
}