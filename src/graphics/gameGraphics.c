#include "graphics/gameGraphics.h"


// scale x4 for all sprites
SDL_Rect src_header = {0, 0, 0, 0};
SDL_Rect header = {0, 0, TOTAL_SCREEN_WIDTH, HEADER_SCREEN_HEIGHT};

SDL_Rect src_game_bg = { 369,3, 168,216 };
SDL_Rect game_bg = { 0, HEADER_SCREEN_HEIGHT, MAZE_WIDTH, MAZE_HEIGHT };

SDL_Rect src_footer = {0, 0, 0, 0};
SDL_Rect footer = {0, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT, TOTAL_SCREEN_WIDTH, FOOTER_SCREEN_HEIGHT};

SDL_Rect destPacmanLives[3] = { 
    { 0 + PACMAN_LIVES_X_DISPLAY_OFFSET , HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE},
    { 32 + PACMAN_LIVES_X_DISPLAY_OFFSET, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE},
    { 64 + PACMAN_LIVES_X_DISPLAY_OFFSET, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE}
};

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

void drawGameHeader()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the black header onto the window surface
    SDL_BlitScaled(plancheSprites, &src_header, pWindowSurface, &header);
}

void drawPacmanLives()
{
    // Get pacman sprite
    SDL_Rect pacman = getPacmanSprite(PACMAN_DEFAULT_DIRECTION, PACMAN_DEFAULT_ANIMATION);
    int pacmanLives = getPacmanLives();

    // Draw each pacman lives
    for(int lives = 0; lives < pacmanLives; lives++)
    {
        SDL_Rect dest = destPacmanLives[lives];

        // Set the color key for transparent pixels in the sprite sheet
        SDL_SetColorKey(plancheSprites, false, 0);

        SDL_BlitScaled(plancheSprites, &pacman, pWindowSurface, &dest);
    }
}

void drawGameFooter()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the black footer onto the window surface
    SDL_BlitScaled(plancheSprites, &src_footer, pWindowSurface, &footer);

    // Draw pacman lives
    drawPacmanLives();
}

void drawGameGraphics()
{
    // Draw the information header
    drawGameHeader();

    // Draw the background image onto the window surface
    drawGameBackground();

    // Draw the footer information for pacman lives
    drawGameFooter();

    // Draw maze
    generateMaze();

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

void maintainFrameRateDelay(clock_t frameStartTime, Uint32 desiredFrameDelayInMs)
{
    // Calculate the duration of the frame
    clock_t frameEndTime = clock();
    clock_t frameDuration = frameEndTime - frameStartTime;
    int64_t frameDurationMs = (frameDuration * 1000) / CLOCKS_PER_SEC;

    // Calculate the remaining delay needed to maintain the desired frame rate
    int64_t remainingDelay = desiredFrameDelayInMs - frameDurationMs;

    // If there is still time remaining, delay the execution
    if (remainingDelay > 0)
        SDL_Delay(SDL_static_cast(Uint32, remainingDelay));
}