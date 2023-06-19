#include "main/ghost.h"

// First index is the ghost color, second index is the direction
SDL_Rect ghostSpritesByDirection[4][4];
SDL_Rect ghostsInitialPositions[4] = {
    {4, 124, 14, 14}, // Red
    {4, 142, 14, 14}, // Pink
    {4, 160, 14, 14}, // Blue
    {4, 178, 14, 14} // Orange
};

struct Coordinates ghostSpawnPos[4];
struct Coordinates ghostUIPos[4];
struct Coordinates ghostGridPos[4];

Direction ghostDefaultDirection;
Direction ghostDirection[4];
Direction ghostWantedDirection[4];

SDL_Rect lastGhostPosition[4];


// Function that initializes the ghosts sprites and positions
void initGhost()
{
    for (int i = 0; i < 4; i++)
    {
        extractSpritesIterativelyWithOffsets(ghostsInitialPositions[i], ghostSpritesByDirection[i], 4, 34, 0);

        ghostSpawnPos[i] = searchElementInMazeArrayByOccurenceNumber(GHOST, i+1);
        ghostUIPos[i] = getGridToUIPosition(ghostSpawnPos[i]);
        ghostGridPos[i] = ghostSpawnPos[i];

        ghostDirection[i] = ghostDefaultDirection;
        ghostWantedDirection[i] = ghostDefaultDirection;

        lastGhostPosition[i] = ghostSpritesByDirection[i][ghostDirection[i]];
    }
}

// Function to spawn the ghosts
void spawnGhost()
{
    initGhost();
    for (int i = 0; i < 4; i++)
    {
        ghostBlit(lastGhostPosition[i], i);
    }
}

// Function that blits a ghost at his position
void ghostBlit(SDL_Rect srcRect, int ghostIndex)
{
    SDL_Rect rect = {ghostUIPos[ghostIndex].x, ghostUIPos[ghostIndex].y + HEADER_SCREEN_HEIGHT, CELL_SIZE, CELL_SIZE};
    SDL_SetColorKey(plancheSprites, 1, 0);
    SDL_BlitScaled(plancheSprites, &srcRect, pWindowSurface, &rect);
}