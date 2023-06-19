#include "graphics/headerGraphics.h"


SDL_Rect src_header = {0, 0, 0, 0}; // To get black background
SDL_Rect header = {HEADER_X_POSITION, HEADER_Y_POSITION, TOTAL_SCREEN_WIDTH, HEADER_SCREEN_HEIGHT};

SDL_Rect oneUpTitleDrawPosition = {ONE_UP_TITLE_X_POSITION, ONE_UP_TITLE_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};
SDL_Rect highScoreTitleDrawPosition = {HIGH_SCORE_TITLE_X_POSITION, HIGH_SCORE_TITLE_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};

SDL_Rect oneUpScoreDrawPosition = {ONE_UP_DRAW_X_POSITION, ONE_UP_DRAW_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};
SDL_Rect highScoreDrawPosition = {HIGH_SCORE_DRAW_X_POSITION, HIGH_SCORE_DRAW_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};


// Draw the 1UP text
void draw1UP()
{
    drawText("1UP", oneUpTitleDrawPosition,15);
}

// Draw the high score text
void drawHighScore()
{
    drawText("HIGH SCORE", highScoreTitleDrawPosition,15);
}

void drawScore(int score)
{
    char scoreString[10];
    sprintf(scoreString, "%d", score);
    drawText(scoreString, oneUpScoreDrawPosition,15);
}

void drawHighScoreNumber(int highScore)
{
    char highScoreString[10];
    sprintf(highScoreString, "%d", highScore);
    drawText(highScoreString, highScoreDrawPosition,15);
}

// Draw the game header
void drawGameHeader()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);
    
    // Draw the black header onto the window surface
    SDL_BlitScaled(plancheSprites, &src_header, pWindowSurface, &header);
    
    // Draw the score title
    if (blinkingCounter % TEXT_BLINKING_SPEED)
        draw1UP();   
    
    // Draw the high score title
    drawHighScore();

    // Draw the score
    drawScore(getScore());

    // Draw the high score
    drawHighScoreNumber(getHighScore());

    blinkingCounter++;
}