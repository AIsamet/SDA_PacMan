#include "graphics/commonGraphics.h"


SDL_Rect alphabetSprites[LETTERS_IN_ALPHABET];
SDL_Rect alphabetFirstLetter = {ALPHABET_FIRST_LETTER_X_POSITION, ALPHABET_FIRST_LETTER_Y_POSITION, LETTERS_SIZE, LETTERS_SIZE};

SDL_Rect numbersSprites[NUMBER_OF_NUMBERS];
SDL_Rect numbersFirstNumber = {NUMBERS_FIRST_NUMBER_X_POSITION, NUMBERS_FIRST_NUMBER_Y_POSITION, NUMBERS_SIZE, NUMBERS_SIZE};

// Get the sprite for a given character
SDL_Rect getCharToSprite(char c)
{
    int ascii = (int)c;
    int index = ascii - 65;
    return alphabetSprites[index];
}

// Convert a string to an array of sprites stored in the output array
void getStringToSprite(char *string, SDL_Rect *output)
{
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(string[i]))
        {
            output[i] = getNumberToSpriteFromChar(string[i]);
        }
        else
        {
            output[i] = getCharToSprite(string[i]);
        }
    }
}

// Get the sprite for a given number
SDL_Rect getNumberToSpriteFromInt(int number)
{
    return numbersSprites[number];
}

// Get the sprite for a given character
SDL_Rect getNumberToSpriteFromChar(char c)
{
    int ascii = (int)c;
    int index = ascii - 48;
    return numbersSprites[index];
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

// Initialize the header sprites
void initCommonGraphics()
{
    // Initialize the alphabet sprites
    extractSpritesIterativelyWithOffsets(alphabetFirstLetter, alphabetSprites, LETTERS_IN_ALPHABET, LETTERS_X_OFFSET, LETTERS_Y_OFFSET);
    // Initialize the numbers sprites
    extractSpritesIterativelyWithOffsets(numbersFirstNumber, numbersSprites, NUMBER_OF_NUMBERS, NUMBERS_X_OFFSET, NUMBERS_Y_OFFSET);
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
    SDL_Rect src[length];
    // Convert the string to sprites and store them in the array
    getStringToSprite(stringCopy, src);

    // Create an array of SDL_Rects to store the destination positions for each letter
    SDL_Rect dest[length];
    // Initialize the destination positions
    extractSpritesIterativelyWithOffsets(position, dest, length, 0, 0);

    // Draw each letter
    for (int i = 0; i < length; ++i) 
    {
        // Scale the sprite to the desired size
        dest[i].x +=  i * ((float)textSize * LETTERS_DISPLAY_RATIO);
        dest[i].w = textSize;
        dest[i].h = textSize;
        // Draw the sprite
        SDL_BlitScaled(plancheSprites, &src[i], pWindowSurface, &dest[i]);
    }
}
