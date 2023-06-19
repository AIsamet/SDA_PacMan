#include "sdlUtils.h"


// Global graphics variables
SDL_Window* pWindow = NULL;
SDL_Surface* pWindowSurface = NULL;
SDL_Surface* plancheSprites = NULL;

void initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) 
    {
        fprintf(stderr, "Echec de l'initialisation de la SDL %s", SDL_GetError());
        return;
    }
}

void initWindow()
{
    // Create the game window with the title "PacMan" and the specified dimensions
    pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, TOTAL_SCREEN_WIDTH, TOTAL_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Get the surface associated with the window for drawing
    pWindowSurface = SDL_GetWindowSurface(pWindow);

    // Load the sprite sheet containing the game graphics from the specified BMP file
    plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
}

void freeSDL()
{
    // Free the window surface
    SDL_FreeSurface(pWindowSurface);

    // Free the sprite sheet surface
    SDL_FreeSurface(plancheSprites);

    // Destroy the window
    SDL_DestroyWindow(pWindow);

    // Quit SDL
    SDL_Quit();
}

void printRectValues(SDL_Rect rect)
{
    printf("x: %d, y: %d, w: %d, h: %d\n", rect.x, rect.y, rect.w, rect.h);
}

void extractSpritesIterativelyWithOffsets(SDL_Rect inputSprite, SDL_Rect *outputSpriteArray, int numberOfSprites, int xOffset, int yOffset)
{
    for (int i = 0; i < numberOfSprites; i++)
    {
        outputSpriteArray[i].x = inputSprite.x + i * xOffset;
        outputSpriteArray[i].y = inputSprite.y + i * yOffset;
        outputSpriteArray[i].w = inputSprite.w;
        outputSpriteArray[i].h = inputSprite.h;
    }    
}