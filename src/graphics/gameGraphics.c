#include "graphics/gameGraphics.h"


SDL_Rect src_game_bg = { 369,3, 168,216 };
SDL_Rect game_bg = { 0, HEADER_SCREEN_HEIGHT, MAZE_WIDTH, MAZE_HEIGHT };

SDL_Rect ghost_r = { 3,123, 16,16 };
SDL_Rect ghost_l = { 37,123, 16,16 };
SDL_Rect ghost_d = { 105,123, 16,16 };
SDL_Rect ghost_u = { 71,123, 16,16 };
SDL_Rect ghost = { 32,HEADER_SCREEN_HEIGHT + 36, 32,32 };

int ghostAnimationCount = 0;
int pacmanAnimationCount = 0;

// to be removed
void animateGhosts()
{
    // Variable to hold the current ghost sprite rectangle
    SDL_Rect* ghost_in = NULL;

    // Determine the current ghost sprite based on the ghostAnimationCount value
    switch (ghostAnimationCount / 128)
    {
        case 0:
            ghost_in = &(ghost_r); // Right-facing ghost sprite
            ghost.x++; // Move the ghost one unit to the right
            break;
        case 1:
            ghost_in = &(ghost_d); // Down-facing ghost sprite
            ghost.y++; // Move the ghost one unit down
            break;
        case 2:
            ghost_in = &(ghost_l); // Left-facing ghost sprite
            ghost.x--; // Move the ghost one unit to the left
            break;
        case 3:
            ghost_in = &(ghost_u); // Up-facing ghost sprite
            ghost.y--; // Move the ghost one unit up
            break;
    }

    // Increment the ghostAnimationCount value and wrap it around to 0 when it reaches 512
    ghostAnimationCount = (ghostAnimationCount + 1) % 512;

    // Create a copy of the current ghost sprite rectangle
    SDL_Rect ghost_in2 = *ghost_in;

    // Modify the ghost sprite rectangle if it is in the alternate state
    if ((ghostAnimationCount / 4) % 2)
        ghost_in2.x += 17;

    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, true, 0);

    // Draw the appropriate ghost sprite onto the window surface
    SDL_BlitScaled(plancheSprites, &ghost_in2, pWindowSurface, &ghost);
}

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
}

void drawGameGraphics()
{
    // Draw the background image onto the window surface
    drawGameBackground();

    // Draw maze
    drawMazeElements();

    // Animate and draw the ghosts
    animateGhosts();

    // Draw pacman
    drawPacman();

    // Draw arrow
    drawWantedDirectionArrow();

    // Get keyboard events
    pacmanEventHandler();
    pacmanAnimationCount++;
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