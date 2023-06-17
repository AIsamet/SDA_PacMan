#include "graphics/headerGraphics.h"


SDL_Rect src_header = {0, 0, 0, 0};
SDL_Rect header = {0, 0, TOTAL_SCREEN_WIDTH, HEADER_SCREEN_HEIGHT};

SDL_Rect alphabetSprites[LETTERS_IN_ALPHABET];
SDL_Rect alphabetFirstLetter = {45, 301, LETTERS_SIZE, LETTERS_SIZE};

SDL_Rect numbersSprites[10];
SDL_Rect firstNumber = {4, 53, NUMBERS_SIZE, NUMBERS_SIZE};

SDL_Rect scoreFirstLetter = {50, 20, LETTERS_SIZE, LETTERS_SIZE};

// Get the sprite for a given character
SDL_Rect getCharSprite(char c)
{
    int ascii = (int)c;
    int index = ascii - 65;
    return alphabetSprites[index];
}

// Convert a string to an array of sprites stored in the output array
void stringToSprite(char *string, SDL_Rect *output)
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        output[i] = getCharSprite(string[i]);
    }
}

SDL_Rect getNumberToSprite(int number)
{
    return numbersSprites[number];
}

// Initialize the header sprites
void initHeaderSprites()
{
    extractSpritesIterativelyWithOffsets(alphabetFirstLetter, alphabetSprites, LETTERS_IN_ALPHABET, LETTERS_X_OFFSET, LETTERS_Y_OFFSET);
    extractSpritesIterativelyWithOffsets(firstNumber, numbersSprites, NUMBER_OF_NUMBERS, NUMBERS_X_OFFSET, NUMBERS_Y_OFFSET);
}

// Convert a string to uppercase
void toUpperCase(char *string)
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        string[i] = toupper(string[i]);
    }
}

// Draw a string of text at the specified position with the specified text size
void drawText(char *string, SDL_Rect position, int textSize)
{
    // Store the length of the string 
    int length = strlen(string);

    // Create a copy of the string to avoid modifying the original
    char stringCopy[length];

    // Copy the string to the new string
    strcpy(stringCopy, string);

    // Convert the string to uppercase
    toUpperCase(stringCopy);

    // Create an array of SDL_Rects to store the sprites for each letter
    SDL_Rect test_src[length];
    // Convert the string to sprites and store them in the array
    stringToSprite(stringCopy, test_src);


    SDL_Rect test_dest[length];
    extractSpritesIterativelyWithOffsets(position, test_dest, length, 0, 0);

    for (int i = 0; i < length; ++i) 
    {
        test_dest[i].x +=  i * ((float)textSize * LETTERS_DISPLAY_RATIO);

        test_dest[i].w = textSize;
        test_dest[i].h = textSize;
        SDL_Rect src = test_src[i];
        SDL_Rect dest = test_dest[i];
        SDL_BlitScaled(plancheSprites, &src, pWindowSurface, &dest);
    }
}

void drawScoreTitle()
{
    drawText("ratio", scoreFirstLetter,15);
}

// Draw the game header
void drawGameHeader()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    //SDL_Rect test = src_score[0];
    
    // Draw the black header onto the window surface
    SDL_BlitScaled(plancheSprites, &src_header, pWindowSurface, &header);
    
    // Draw the score title
    drawScoreTitle();    
}