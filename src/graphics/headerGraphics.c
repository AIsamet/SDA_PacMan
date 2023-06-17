#include "graphics/headerGraphics.h"


SDL_Rect src_header = {0, 0, 0, 0};
SDL_Rect header = {0, 0, TOTAL_SCREEN_WIDTH, HEADER_SCREEN_HEIGHT};

SDL_Rect alphabet[LETTERS_IN_ALPHABET];
SDL_Rect alphabetFirstLetter = {45, 301, LETTERS_SIZE, LETTERS_SIZE};

void initHeaderSprites()
{
    extractSpritesIterativelyWithOffsets(alphabetFirstLetter, alphabet, LETTERS_IN_ALPHABET, LETTERS_X_OFFSET, LETTERS_Y_OFFSET);
}

SDL_Rect charToAlphabet(char c)
{
    int ascii = (int)c;
    int index = ascii - 65;
    return alphabet[index];
}

void stringToAlphabet(char *string, SDL_Rect *output)
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        output[i] = charToAlphabet(string[i]);
    }
}

void drawGameHeader()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the black header onto the window surface
    SDL_BlitScaled(plancheSprites, &src_header, pWindowSurface, &header);
}