#include "graphics/headerGraphics.h"


SDL_Rect src_header = {0, 0, 0, 0};
SDL_Rect header = {0, 0, TOTAL_SCREEN_WIDTH, HEADER_SCREEN_HEIGHT};

void drawGameHeader()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the black header onto the window surface
    SDL_BlitScaled(plancheSprites, &src_header, pWindowSurface, &header);
}