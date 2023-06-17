#include "graphics/headerGraphics.h"


SDL_Rect src_header = {0, 0, 0, 0}; // To get black background
SDL_Rect header = {HEADER_X_POSITION, HEADER_Y_POSITION, TOTAL_SCREEN_WIDTH, HEADER_SCREEN_HEIGHT};

SDL_Rect oneUpDrawPosition = {ONE_UP_X_POSITION, ONE_UP_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};
SDL_Rect highScorePosition = {HIGH_SCORE_X_POSITION, HIGH_SCORE_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};

// Draw the 1UP text
void draw1UP()
{
    drawText("1UP", oneUpDrawPosition,15);
}

// Draw the high score text
void drawHighScore()
{
    drawText("HIGH SCORE", highScorePosition,15);
}

// Draw the game header
void drawGameHeader()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);
    
    // Draw the black header onto the window surface
    SDL_BlitScaled(plancheSprites, &src_header, pWindowSurface, &header);
    
    // Draw the score title
    draw1UP();    
    
    // Draw the high score title
    drawHighScore();
}