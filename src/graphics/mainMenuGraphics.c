#include "graphics/mainMenuGraphics.h"

SDL_Rect src_mainMenuBackground = {SOURCE_MAIN_MENU_BACKGROUND_X_POSITION, SOURCE_MAIN_MENU_BACKGROUND_Y_POSITION, SOURCE_MAIN_MENU_BACKGROUND_WIDTH, SOURCE_MAIN_MENU_BACKGROUND_HEIGHT}; // Yellow background
SDL_Rect mainMenuBackground = {0, 0, MAIN_MENU_SCREEN_WIDTH, MAIN_MENU_SCREEN_HEIGHT};

SDL_Rect src_logo = {SOURCE_LOGO_X_POSITION, SOURCE_LOGO_Y_POSITION, SOURCE_LOGO_WIDTH, SOURCE_LOGO_HEIGHT};
SDL_Rect logo = {LOGO_X_POSITION, LOGO_Y_POSITION, LOGO_WIDTH, LOGO_HEIGHT};

SDL_Rect playInstructionPostion = {PLAY_INSTRUCTION_X_POSITION, PLAY_INSTRUCTION_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};

// Draw the main menu graphics
void drawMainMenuGraphics()
{
    // Draw the yellow background onto the window surface
    SDL_BlitScaled(plancheSprites, &src_mainMenuBackground, pWindowSurface, &mainMenuBackground);
    // Draw the logo
    SDL_BlitScaled(plancheSprites, &src_logo, pWindowSurface, &logo);
    // Draw the play instruction
    //drawText("PRESS SPACE TO PLAY", playInstructionPostion, 25);
}