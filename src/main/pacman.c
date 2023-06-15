#include "main/pacman.h"


SDL_Rect pacmanSpritesByDirection[4][3] = {
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {21, 90, PACMAN_SIZE, PACMAN_SIZE}, {38, 90, PACMAN_SIZE, PACMAN_SIZE}},  // RIGHT
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {56, 90, PACMAN_SIZE, PACMAN_SIZE}, {72, 90, PACMAN_SIZE, PACMAN_SIZE}},  // LEFT
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {89, 90, PACMAN_SIZE, PACMAN_SIZE}, {106, 90, PACMAN_SIZE, PACMAN_SIZE}}, // UP
        {{4, 90, PACMAN_SIZE, PACMAN_SIZE}, {123, 90, PACMAN_SIZE, PACMAN_SIZE}, {140, 90, PACMAN_SIZE, PACMAN_SIZE}} // DOWN
};


SDL_Rect lastPacmanDirection = {0, 0, 0, 0};

struct Coordinates pacmanSpawnPos = {1, 1};
struct Coordinates pacmanUIPos = {0, 0};
struct Coordinates pacmanGridPos = {0, 0};

Direction defaultDirection = DIRECTION_RIGHT;

Direction pacmanDirection;
Direction pacmanWishedDirection;

int durationAnimationOnGhostEaten = 0;

void spawnPacman()
{
    pacmanGridPos = pacmanSpawnPos;
    pacmanUIPos = getGridToUiPosition(pacmanGridPos);

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

void drawPacman()
{
    SDL_Rect newPacman = {0, 0, 0, 0};
    int pacmanAnimation = (fps / ANIMATION_SPEED) % 3;
    struct Coordinates pacmanPosCopy = pacmanUIPos;
}