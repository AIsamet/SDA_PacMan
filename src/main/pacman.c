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

int durationAnimationOnGhostEaten = 0;

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
        setElementInMazeArray(PACMAN, pacmanGridPos);
        break;
    case SUPER_PAC_GUM:
        setElementInMazeArray(PACMAN, pacmanGridPos);
        break;
    default:
        setElementInMazeArray(PACMAN, pacmanGridPos);
        break;
    }

    return *pacmanUiPos;
}

void drawPacman()
{
    SDL_Rect newPacman = {0, 0, 0, 0};
    int pacmanAnimation = (fps / ANIMATION_SPEED) % 3;
    struct Coordinates pacmanPosCopy = pacmanUIPos;

//    if (pacmanDirection != pacmanWishedDirection && canPacmanMove(pacmanWishedDirection))
//    {
        pacmanDirection = pacmanWishedDirection;
//    }

    //print pacman direction
    printf("pacman direction : %d\n", pacmanDirection);
    // print wished pacman direction
    printf("pacman wished direction : %d\n", pacmanWishedDirection);
    //pacman UI positions x and y
    printf("pacman UI position X : %d ; Y : %d\n", pacmanUIPos.x, pacmanUIPos.y);
    // pacman grid positions
    printf("pacman grid position X : %d ; Y : %d\n", pacmanGridPos.x, pacmanGridPos.y);
    //can move
    printf("can move : %d\n", canPacmanMove(pacmanWishedDirection));

    // Then we can choose the sprite corresponding to direction
    newPacman = pacmanSpritesByDirection[pacmanDirection][pacmanAnimation];

    // Calculate the target UI position
    sumCoordinatesWithOffset(&pacmanPosCopy, pacmanDirection, 3);

    // bugged, to be fixed
//    if (isColliding(pacmanPosCopy, CELL_SIZE - 1))
//    {
//        pacmanBlit(lastPacmanDirection);
//        return;
//    }

    // Get target pacman position in grid
    struct Coordinates newPacmanGridPos = getUIToGridPosition(getCellCenter(pacmanPosCopy));

    if (!isEqual(pacmanGridPos, newPacmanGridPos))
    {
        // Pacman has moved in grid
        pacmanGridPos = newPacmanGridPos;
        pacmanPosCopy = movePacmanOnGrid(&pacmanPosCopy);
    }

    // Move is valid, update pacman position
    pacmanUIPos = pacmanPosCopy;
    lastPacmanDirection = newPacman;

    pacmanBlit(newPacman);
}