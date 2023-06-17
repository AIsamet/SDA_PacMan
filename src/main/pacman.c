#include "main/pacman.h"


SDL_Rect pacmanSpritesByDirection[4][3] = {
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {21, 90, PACMAN_SIZE, PACMAN_SIZE}, {38, 90, PACMAN_SIZE, PACMAN_SIZE}},  // RIGHT
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {56, 90, PACMAN_SIZE, PACMAN_SIZE}, {72, 90, PACMAN_SIZE, PACMAN_SIZE}},  // LEFT
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {89, 90, PACMAN_SIZE, PACMAN_SIZE}, {106, 90, PACMAN_SIZE, PACMAN_SIZE}}, // UP
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {123, 90, PACMAN_SIZE, PACMAN_SIZE}, {140, 90, PACMAN_SIZE, PACMAN_SIZE}} // DOWN
};

SDL_Rect lastPacmanPosition = {0, 0, 0, 0};

struct Coordinates pacmanSpawnPos;
struct Coordinates pacmanUIPos = {0, 0};
struct Coordinates pacmanGridPos = {0, 0};

Direction defaultDirection = DIRECTION_RIGHT;

Direction pacmanDirection;
Direction pacmanWishedDirection;

// Function to spawn Pacman at the beginning of the game
void spawnPacman()
{
    pacmanSpawnPos = searchElementInMazeArray(PACMAN);
    pacmanGridPos = pacmanSpawnPos;
    pacmanUIPos = getGridToUIPosition(pacmanGridPos);

    pacmanDirection = defaultDirection;
    pacmanWishedDirection = defaultDirection;

    lastPacmanPosition = pacmanSpritesByDirection[defaultDirection][0];
}

// Function to handle the events related to Pacman
void pacmanEventHandler()
{
    SDL_Event event;
    pacmanInputHandler(&event, &pacmanWishedDirection);
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
    SDL_Rect rect = {pacmanUIPos.x, pacmanUIPos.y, CELL_SIZE, CELL_SIZE};
    SDL_SetColorKey(plancheSprites, 1, 0);
    SDL_BlitScaled(plancheSprites, &srcRect, pWindowSurface, &rect);
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
        break;
    case SUPER_PAC_GUM:
        setElementInMazeArray(EMPTY, pacmanGridPos);
        break;
    default:
        break;
    }
}

// Function to get the current animation frame of Pacman
int getPacmanCurrentAnimationIndex()
{
    return (pacmanAnimationCount / ANIMATION_SPEED) % 3;
}

// Function to update the direction of Pacman if possible
void updatePacmanDirection(Direction pacmanWishedDirection)
{
    // Check if the desired direction for Pacman has changed and if Pacman can move in that direction
    if (pacmanDirection != pacmanWishedDirection && canPacmanMove(pacmanWishedDirection))
    {
        // Update the direction of Pacman
        pacmanDirection = pacmanWishedDirection;
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
    updatePacmanDirection(pacmanWishedDirection);

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