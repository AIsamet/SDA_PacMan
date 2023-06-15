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

    // print wished direction
    printf("Wished direction: %d\n", pacmanWishedDirection);
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
    // removeMazeElement(PACMAN);
    // MazeElement element = getMazeElementAt(pacmanGridPos);

    // switch (element)
    // {
    // case LEFT_TELEPORTER:
    //     return teleportPacman(RIGHT_TELEPORTER);
    // case RIGHT_TELEPORTER:
    //     return teleportPacman(LEFT_TELEPORTER);
    // case SMALL_COIN:
    //     incrementScore(10);
    //     setElementAtPositionOnMazeAs(pacmanGridPos, PACMAN);
    //     break;
    // case BIG_COIN:
    //     incrementScore(50);
    //     makeGhostsEatable();
    //     setElementAtPositionOnMazeAs(pacmanGridPos, PACMAN);
    //     break;
    // case RED_GHOST:
    //     handleGhost(RED_GHOST);
    //     break;
    // case PINK_GHOST:
    //     handleGhost(PINK_GHOST);
    //     break;
    // case BLUE_GHOST:
    //     handleGhost(BLUE_GHOST);
    //     break;
    // case ORANGE_GHOST:
    //     handleGhost(ORANGE_GHOST);
    //     break;
    // default:
    //     setElementAtPositionOnMazeAs(pacmanGridPos, PACMAN);
    //     break;
    // }

    // return *pacmanUiPos;
}

void drawPacman()
{
    SDL_Rect newPacman = {0, 0, 0, 0};
    int pacmanAnimation = (fps / ANIMATION_SPEED) % 3;
    struct Coordinates pacmanPosCopy = pacmanUIPos;

     // Test is wished direction can be applied
    if (pacmanDirection != pacmanWishedDirection && canPacmanMove(pacmanWishedDirection))
    {
        pacmanDirection = pacmanWishedDirection;
    }

    // Then we can choose the sprite corresponding to direction
    newPacman = pacmanSpritesByDirection[pacmanDirection][pacmanAnimation];

    // Calculate the target UI position
    sumCoordinatesWithOffset(&pacmanPosCopy, pacmanDirection, 1);

    if (isColliding(pacmanPosCopy, CELL_SIZE - 1))
    {
        // If pacman ran into obstacle, just blit him at without updating his position
        pacmanBlit(lastPacmanDirection);
        return;
    }

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