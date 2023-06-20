#include "mainMenuGraphics.h"

SDL_Rect src_mainMenuBackground = {0, 0, 0, 0}; // To get black background
SDL_Rect mainMenuBackground = {0, 0, MAIN_MENU_SCREEN_WIDTH, MAIN_MENU_SCREEN_HEIGHT};

SDL_Rect src_logo = {SOURCE_LOGO_X_POSITION, SOURCE_LOGO_Y_POSITION, SOURCE_LOGO_WIDTH, SOURCE_LOGO_HEIGHT};
SDL_Rect logo = {LOGO_X_POSITION, LOGO_Y_POSITION, LOGO_WIDTH, LOGO_HEIGHT};

SDL_Rect playInstructionPostion = {PLAY_INSTRUCTION_X_POSITION, PLAY_INSTRUCTION_Y_POSITION, PLAY_INSTRUCTION_WIDTH, PLAY_INSTRUCTION_HEIGHT};

SDL_Rect src_mainMenuImg = {SOURCE_MAIN_MENU_IMG_X_POSITION, SOURCE_MAIN_MENU_IMG_Y_POSITION, SOURCE_MAIN_MENU_IMG_WIDTH, SOURCE_MAIN_MENU_IMG_HEIGHT};
SDL_Rect mainMenuImg = {MAIN_MENU_IMG_X_POSITION, MAIN_MENU_IMG_Y_POSITION, MAIN_MENU_IMG_WIDTH, MAIN_MENU_IMG_HEIGHT};

// Draw the main menu graphics
void drawMainMenuGraphics()
{
    // Draw the yellow background onto the window surface
    SDL_BlitScaled(plancheSprites, &src_mainMenuBackground, pWindowSurface, &mainMenuBackground);
    // Draw the logo
    SDL_BlitScaled(plancheSprites, &src_logo, pWindowSurface, &logo);

    // Draw the play instruction
    if (blinkingCounter % TEXT_BLINKING_SPEED)
    {
    drawText("PRESS ENTER TO PLAY", playInstructionPostion, 20);
    }

    // Draw image
    SDL_BlitScaled(plancheSprites, &src_mainMenuImg, pWindowSurface, &mainMenuImg);

    blinkingCounter++;
}

void startMainMenu()
{
    bool mainMenuQuit = false;

    while (!mainMenuQuit)
    {
        // Start the frame timer
        clock_t frameStartTime = clock();

        // Clear the window surface
        SDL_FillRect(pWindowSurface, 0, 0);
        
        // Draw the main menu graphics
        drawMainMenuGraphics();

        // Handle main menu input
        mainMenuInputHandler(&mainMenuQuit);

        // Update the window surface
        SDL_UpdateWindowSurface(pWindow);
        
        // Delay the frame rate
        maintainFrameRateDelay(frameStartTime, GAME_FRAMERATE);
    }

}