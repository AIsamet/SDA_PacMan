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
    struct Coordinates pacmanPosCopy = pacmanUIPos;
    sumCoordinatesWithOffset(&pacmanPosCopy, direction, 1);
    return !isColliding(pacmanPosCopy, CELL_SIZE - 1);
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

void drawPacman()
{
    SDL_Rect newPacman = {0, 0, 0, 0};  // Initialize a new SDL rectangle for pacman
    int pacmanAnimation = (fps / ANIMATION_SPEED) % 3;  // Determine the current animation frame of pacman
    struct Coordinates pacmanUIPosCopy = pacmanUIPos;  // Make a copy of pacman's UI position

    // Check if pacman's desired direction is different from the current direction and if pacman can move in the desired direction
    if (pacmanDirection != pacmanWishedDirection && canPacmanMove(pacmanWishedDirection))
    {
        pacmanDirection = pacmanWishedDirection;  // Update pacman's direction to the desired direction
    }

    // Choose the sprite corresponding to pacman's direction and animation frame
    newPacman = pacmanSpritesByDirection[pacmanDirection][pacmanAnimation];

    // Calculate the target UI position for pacman
    sumCoordinatesWithOffset(&pacmanUIPosCopy, pacmanDirection, 1);

    // Check if pacman's target UI position collides with an obstacle
    if (isColliding(pacmanUIPosCopy, CELL_SIZE - 1))
    {
        // If pacman ran into an obstacle, blit him without updating his position
        pacmanBlit(lastPacmanDirection);
        return;
    }

    // Get the target grid position for pacman
    struct Coordinates newPacmanGridPos = getUIToGridPosition(getCellCenter(pacmanUIPosCopy));

    // Check if pacman has moved to a new grid position
    if (!isEqual(pacmanGridPos, newPacmanGridPos))
    {
        // Pacman has moved to a new grid position
        pacmanGridPos = newPacmanGridPos;
        pacmanUIPosCopy = movePacmanOnGrid(&pacmanUIPosCopy);
    }

    // Update pacman's position to the new UI position
    pacmanUIPos = pacmanUIPosCopy;
    lastPacmanDirection = newPacman;

    // Blit pacman with the new sprite
    pacmanBlit(newPacman);
}
