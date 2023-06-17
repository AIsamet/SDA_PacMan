#include "graphics/footerGraphics.h"


SDL_Rect src_footer = {0, 0, 0, 0};
SDL_Rect footer = {0, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT, TOTAL_SCREEN_WIDTH, FOOTER_SCREEN_HEIGHT};

SDL_Rect destPacmanLives[3] = { 
    { 0 + PACMAN_LIVES_X_DISPLAY_OFFSET , HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE},
    { 32 + PACMAN_LIVES_X_DISPLAY_OFFSET, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE},
    { 64 + PACMAN_LIVES_X_DISPLAY_OFFSET, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE}
};

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