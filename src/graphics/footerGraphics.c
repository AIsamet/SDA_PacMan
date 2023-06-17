#include "graphics/footerGraphics.h"


SDL_Rect src_footer = {0, 0, 0, 0};
SDL_Rect footer = {0, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT, TOTAL_SCREEN_WIDTH, FOOTER_SCREEN_HEIGHT};

SDL_Rect src_arrow = {99, 69, 9, 9};
SDL_Rect arrow = {LIVES_ARROW_X_POSITION, LIVES_ARROW_Y_POSITION, LIVES_ARROW_SIZE, LIVES_ARROW_SIZE};

SDL_Rect destPacmanLives[3] = { 
    { PACMAN_LIVES_X_DISPLAY_OFFSET , HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE},
    { PACMAN_LIVES_X_DISPLAY_OFFSET + 40, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE},
    { PACMAN_LIVES_X_DISPLAY_OFFSET + 80, HEADER_SCREEN_HEIGHT + MAZE_HEIGHT + PACMAN_LIVES_Y_DISPLAY_OFFSET , CELL_SIZE, CELL_SIZE}
};

SDL_Rect livesTextPosition = {LIVES_TEXT_X_POSITION, LIVES_TEXT_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};

void drawLivesText()
{
    // Draw the lives text
    drawText("LIVES ", livesTextPosition, 15);

    // Draw the arrow
    SDL_BlitScaled(plancheSprites, &src_arrow, pWindowSurface, &arrow);
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

    // Draw the lives text
    drawLivesText();

    // Draw pacman lives
    drawPacmanLives();
}