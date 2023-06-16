#include "main/pacman.h"


SDL_Rect pacmanSpritesByDirection[4][3] = {
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {21, 90, PACMAN_SIZE, PACMAN_SIZE}, {38, 90, PACMAN_SIZE, PACMAN_SIZE}},  // RIGHT
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {56, 90, PACMAN_SIZE, PACMAN_SIZE}, {72, 90, PACMAN_SIZE, PACMAN_SIZE}},  // LEFT
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {89, 90, PACMAN_SIZE, PACMAN_SIZE}, {106, 90, PACMAN_SIZE, PACMAN_SIZE}}, // UP
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {123, 90, PACMAN_SIZE, PACMAN_SIZE}, {140, 90, PACMAN_SIZE, PACMAN_SIZE}} // DOWN
};

SDL_Rect lastPacmanDirection = {0, 0, 0, 0};

struct Coordinates pacmanSpawnPos;
struct Coordinates pacmanUIPos = {0, 0};
struct Coordinates pacmanGridPos = {0, 0};

Direction defaultDirection = DIRECTION_RIGHT;

Direction pacmanDirection;
Direction pacmanWishedDirection;

void spawnPacman()
{
    pacmanSpawnPos = searchElementInMazeArray(PACMAN);
    pacmanGridPos = pacmanSpawnPos;
    pacmanUIPos = getGridToUIPosition(pacmanGridPos);

    pacmanDirection = defaultDirection;
    pacmanWishedDirection = defaultDirection;

    lastPacmanDirection = pacmanSpritesByDirection[defaultDirection][0];
}

void pacmanEventHandler()
{
    SDL_Event event;
    pacmanInputHandler(&event, &pacmanWishedDirection);
}

int canPacmanMove(Direction direction)
{
    struct Coordinates pacmanUIPosCopy = pacmanUIPos;
    sumCoordinatesWithOffset(&pacmanUIPosCopy, direction, 1);
    return !isColliding(pacmanUIPosCopy, CELL_SIZE - 1);
}

void pacmanBlit(SDL_Rect srcRect)
{
    SDL_Rect rect = {pacmanUIPos.x, pacmanUIPos.y, CELL_SIZE, CELL_SIZE};
    SDL_SetColorKey(plancheSprites, 1, 0);
    SDL_BlitScaled(plancheSprites, &srcRect, pWindowSurface, &rect);
}

struct Coordinates movePacmanOnGrid(struct Coordinates *pacmanUiPos)
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

    return *pacmanUiPos;
}

// Function to draw the Pacman character on the screen
void drawPacman()
{
// Define a new rectangle for Pacman
SDL_Rect newPacman = {0, 0, 0, 0};
// Calculate the current animation frame for Pacman
int pacmanAnimation = (pacmanAnimationCount / ANIMATION_SPEED) % 3;

// Make a copy of the current UI position of Pacman
struct Coordinates pacmanUIPosCopy = pacmanUIPos;

// Check if the desired direction for Pacman has changed and if Pacman can move in that direction
if (pacmanDirection != pacmanWishedDirection && canPacmanMove(pacmanWishedDirection))
{
    // Update the direction of Pacman
    pacmanDirection = pacmanWishedDirection;
}

// Retrieve the appropriate sprite for the current direction and animation frame
newPacman = pacmanSpritesByDirection[pacmanDirection][pacmanAnimation];

// Add an offset to the Pacman's UI position based on its direction
sumCoordinatesWithOffset(&pacmanUIPosCopy, pacmanDirection, 1);

// Check if Pacman is colliding with an obstacle
if (isColliding(pacmanUIPosCopy, CELL_SIZE - 1))
{
    // Restore the previous direction of Pacman and exit the function
    pacmanBlit(lastPacmanDirection);
    return;
}

// Get the new grid position of Pacman based on its updated UI position
struct Coordinates newPacmanGridPos = getUIToGridPosition(getCellCenter(pacmanUIPosCopy));

// Check if Pacman has moved to a new grid position
if (!isEqual(pacmanGridPos, newPacmanGridPos))
{
    // Update the grid position of Pacman and adjust the UI position accordingly
    pacmanGridPos = newPacmanGridPos;
    pacmanUIPosCopy = movePacmanOnGrid(&pacmanUIPosCopy);
}

// Update the UI position of Pacman
pacmanUIPos = pacmanUIPosCopy;
// Update the last direction of Pacman
lastPacmanDirection = newPacman;

// Draw Pacman on the screen
pacmanBlit(newPacman);
}