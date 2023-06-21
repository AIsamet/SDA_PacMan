#include "pacman.h"


SDL_Rect pacmanSpritesByDirection[4][3] = {
    {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {21, 90, PACMAN_SIZE, PACMAN_SIZE}, {38, 90, PACMAN_SIZE, PACMAN_SIZE}},  // RIGHT
    {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {56, 90, PACMAN_SIZE, PACMAN_SIZE}, {72, 90, PACMAN_SIZE, PACMAN_SIZE}},  // LEFT
    {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {89, 90, PACMAN_SIZE, PACMAN_SIZE}, {106, 90, PACMAN_SIZE, PACMAN_SIZE}}, // UP
    {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {123, 90, PACMAN_SIZE, PACMAN_SIZE}, {140, 90, PACMAN_SIZE, PACMAN_SIZE}} // DOWN
};

SDL_Rect wantedDirectionArrowSpritesByDirection[4] = {
    {4, 301, DIRECTION_ARROW_SIZE, DIRECTION_ARROW_SIZE}, // RIGHT
    {11, 301, DIRECTION_ARROW_SIZE, DIRECTION_ARROW_SIZE}, // LEFT
    {18, 301, DIRECTION_ARROW_SIZE, DIRECTION_ARROW_SIZE}, // UP
    {25, 301, DIRECTION_ARROW_SIZE, DIRECTION_ARROW_SIZE}, // DOWN
};

SDL_Rect pacmanDeathSprites[10];
SDL_Rect firstPacmanDeathSpritesPostion = {4, 106, PACMAN_SIZE, PACMAN_SIZE};

SDL_Rect lastPacmanPosition = {0, 0, 0, 0};

struct Coordinates pacmanSpawnPos;
struct Coordinates pacmanUIPos = {0, 0};
struct Coordinates pacmanGridPos = {0, 0};

Direction defaultDirection = DIRECTION_RIGHT;

Direction pacmanDirection;
Direction pacmanWantedDirection;

bool isPacmanDead = false;

// Function to spawn Pacman at the beginning of the game
void initPacman()
{
    initPacmanDeathAnimationSprites();

    bool isPacmanDead = false;
    pacmanSpawnPos = searchElementInMazeArray(PACMAN);
    pacmanGridPos = pacmanSpawnPos;
    pacmanUIPos = getGridToUIPosition(pacmanGridPos);

    pacmanDirection = defaultDirection;
    pacmanWantedDirection = defaultDirection;

    lastPacmanPosition = pacmanSpritesByDirection[defaultDirection][0];
}

void spawnPacman()
{
    initPacman();
    pacmanBlit(lastPacmanPosition);
}

// Function to handle the events related to Pacman
void pacmanEventHandler()
{
    pacmanInputHandler(&pacmanWantedDirection);
}

// Function to check if Pacman can move in a given direction
int canPacmanMove(Direction direction)
{
    struct Coordinates newPacmanUIPos = pacmanUIPos;
    sumCoordinatesWithOffset(&newPacmanUIPos, direction, 1);
    return !isColliding(newPacmanUIPos, CELL_SIZE - 1);
}

// Function to draw the Pacman character on the screen
void pacmanBlit(SDL_Rect srcRect)
{
    SDL_Rect rect = {pacmanUIPos.x, pacmanUIPos.y + HEADER_SCREEN_HEIGHT, CELL_SIZE, CELL_SIZE};
    SDL_SetColorKey(plancheSprites, 1, 0);
    SDL_BlitScaled(plancheSprites, &srcRect, pWindowSurface, &rect);
}

void killPacman()
{
    removePacmanLives(1);
    Timer_reset(&gameStartTime);
    Timer_start(&gameStartTime);
    resetPacmanPosition();
}

void ghostColisionHandler()
{
    killPacman();
}

// Function to update the element under Pacman in the maze array
void updateUnderPacmanGridElement()
{
    removeElementFromMazeArray(PACMAN);
    MazeObstacles element = getElementFromMazeArray(pacmanGridPos);

    switch (element)
    {
    case PAC_GUM:
        setElementInMazeArray(EMPTY, pacmanGridPos);
        addScore(PAC_GUM_SCORE);
        break;
    case SUPER_PAC_GUM:
        addScore(SUPER_PAC_GUM_SCORE);
        setElementInMazeArray(EMPTY, pacmanGridPos);
        break;
    case GHOST:
        ghostColisionHandler();
    default:
        break;
    }
}

// Function to get the current animation frame of Pacman
int getPacmanCurrentAnimationIndex()
{
    return (pacmanAnimationCount / ANIMATION_SPEED) % 3;
}

int getPacmanCurrentDeathAnimationIndex()
{
    return (pacmanDeathAnimationCount / ANIMATION_SPEED) % 10;
}

// Function to update the direction of Pacman if possible
void updatePacmanDirection(Direction pacmanWantedDirection)
{
    // Check if the desired direction for Pacman has changed and if Pacman can move in that direction
    if (pacmanDirection != pacmanWantedDirection && canPacmanMove(pacmanWantedDirection))
    {
        // Update the direction of Pacman
        pacmanDirection = pacmanWantedDirection;
    }
}

// Function to retrieve the appropriate sprite for the current direction and animation frame
SDL_Rect getPacmanSprite(Direction direction, int animationIndex)
{
    return pacmanSpritesByDirection[direction][animationIndex];
}

// Function to draw the Pacman character on the screen
void drawPacman()
{
    // Get the current animation frame of Pacman
    int pacmanAnimation = getPacmanCurrentAnimationIndex();

    // Update the direction of Pacman if possible
    updatePacmanDirection(pacmanWantedDirection);

    // Retrieve the appropriate sprite for the current direction and animation frame
    SDL_Rect newPacmanPosition = getPacmanSprite(pacmanDirection,pacmanAnimation);

    // Make a copy of the current UI position of Pacman
    struct Coordinates newPacmanUIPos = pacmanUIPos;
    // Add an offset to the Pacman's UI position copy based on its direction
    sumCoordinatesWithOffset(&newPacmanUIPos, pacmanDirection, 1);

    // Check if Pacman is colliding with an obstacle
    if (isColliding(newPacmanUIPos, CELL_SIZE - 1))
    {
        // Restore the previous direction of Pacman and exit the function
        pacmanBlit(lastPacmanPosition);
        return;
    }
    else
    {
        // Get the new grid position of Pacman based on its updated UI position
        struct Coordinates newPacmanGridPos = getUIToGridPosition(getCellCenter(newPacmanUIPos));

        // Check if Pacman has moved to a new grid position
        if (!isEqual(pacmanGridPos, newPacmanGridPos))
        {
            // Update the grid position of Pacman and adjust the UI position accordingly
            pacmanGridPos = newPacmanGridPos;
            updateUnderPacmanGridElement();
        }

        // Update the UI position of Pacman
        pacmanUIPos = newPacmanUIPos;
        // Update the last direction of Pacman
        lastPacmanPosition = newPacmanPosition;

        // Draw Pacman on the screen
        pacmanBlit(newPacmanPosition);
    }
}

// Function to retrieve the appropriate sprite for the current direction
SDL_Rect getWantedDirectionArrowSprite(Direction direction)
{
    return wantedDirectionArrowSpritesByDirection[direction];
}

// Function to draw the wanted direction arrow on the screen
void drawWantedDirectionArrow()
{   
    // Retrieve the appropriate sprite for the current direction
    SDL_Rect currentDirectionArrowSprite = getWantedDirectionArrowSprite(pacmanWantedDirection);

    // Calculate the UI position of the wanted direction arrow
    struct Coordinates arrowUIPos = {
        pacmanUIPos.x + DIRECTION_ARROW_OFFSET,
        pacmanUIPos.y + DIRECTION_ARROW_OFFSET,
    };

    // Add an offset to the wanted direction arrow's UI position based on its direction
    sumCoordinatesWithOffset(&arrowUIPos, pacmanWantedDirection, DIRECTION_ARROW_PADDING);

    // Calculate the destination rectangle of the wanted direction arrow
    struct SDL_Rect arrowDestRect = {
        arrowUIPos.x,
        arrowUIPos.y + HEADER_SCREEN_HEIGHT,
        DIRECTION_ARROW_DISPLAY_SIZE,
        DIRECTION_ARROW_DISPLAY_SIZE
    };

    // Blit the wanted direction arrow sprite on the screen
    SDL_BlitScaled(plancheSprites, &currentDirectionArrowSprite, pWindowSurface, &arrowDestRect);
}

void resetPacmanPosition()
{
    resetElementPositionInMazeArray(PACMAN);
}

void initPacmanDeathAnimationSprites()
{
    // TO BE CHECKED
    extractSpritesIterativelyWithOffsets(firstPacmanDeathSpritesPostion, pacmanDeathSprites, 10, 17, 0);
}

void drawPacmanDeathAnimation()
{
    SDL_Rect pacmanDeathSprite = pacmanDeathSprites[getPacmanCurrentDeathAnimationIndex()];
    SDL_Rect rect = {pacmanUIPos.x, pacmanUIPos.y + HEADER_SCREEN_HEIGHT, CELL_SIZE, CELL_SIZE};
    SDL_SetColorKey(plancheSprites, 1, 0);
    SDL_BlitScaled(plancheSprites, &pacmanDeathSprite, pWindowSurface, &rect);
}