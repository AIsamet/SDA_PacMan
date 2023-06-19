#include "main/maze.h"


int newMapArray[27][21];

SDL_Rect pacGum = { 1, 78, 8, 8 };
SDL_Rect superPacGum = { 9, 79, 7, 7 };

int map_array[27][21] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
        { 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1 },
        { 1, 3, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 3, 1 },
        { 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1 },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
        { 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1 },
        { 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1 },
        { 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1 },
        { 1, 1, 1, 1, 1, 2, 1, 1, 1, 0, 1, 0, 1, 1, 1, 2, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 6, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 1, 1, 4, 1, 1, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 0, 1, 0, 0, 0, 1, 0, 1, 2, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 2, 0, 0, 1, 6, 6, 6, 1, 0, 0, 2, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1 },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
        { 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1 },
        { 1, 3, 2, 2, 1, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 1, 2, 2, 3, 1 },
        { 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1 },
        { 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1 },
        { 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1 },
        { 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1 },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void copyMapArray() 
{
    for (int i = 0; i < MAZE_HEIGHT_IN_ARRAY ; i++)
    {
        for (int j = 0; j < MAZE_WIDTH_IN_ARRAY; j++)
        {
            newMapArray[i][j] = map_array[i][j];
        }
    }
}

void drawPacGum(SDL_Rect pacGum, SDL_Rect superPacGum) 
{
    for (int i = 0; i < MAZE_HEIGHT_IN_ARRAY; i++)
    {
        for (int j = 0; j < MAZE_WIDTH_IN_ARRAY; j++)
        {
            if (newMapArray[i][j] == 2 || newMapArray[i][j] == 3)
            {
                struct Coordinates position = getGridToUIPosition((struct Coordinates){j, i});

                if (newMapArray[i][j] == 2)
                {
                    drawIntoMaze(pacGum, position, PACGUM_X, PACGUM_Y, PACGUM_W, PACGUM_H);
                } else if (newMapArray[i][j] == 3)
                {
                    drawIntoMaze(superPacGum, position, PACGUM_X, PACGUM_Y, PACGUM_W, PACGUM_H);
                }
            }
        }
    }
}

void drawMazeElements()
{
    drawPacGum(pacGum, superPacGum);
}

void initMaze() 
{
    copyMapArray();
}

struct Coordinates getUIToGridPosition(struct Coordinates UIPos)
{
    struct Coordinates coordinates;
    coordinates.x = UIPos.x / CELL_SIZE;
    coordinates.y = UIPos.y / CELL_SIZE;
    return coordinates;
}

struct Coordinates getGridToUIPosition(struct Coordinates gridPos)
{
    struct Coordinates coordinates;
    coordinates.x = gridPos.x * CELL_SIZE;
    coordinates.y = gridPos.y * CELL_SIZE;
    return coordinates;
}


void drawIntoMaze(SDL_Rect sprite, struct Coordinates positionToDraw, int x, int y, int w, int h) 
{
    SDL_Rect coordinates = {
            .x = positionToDraw.x + x,
            .y = positionToDraw.y + y,
            .w = w,
            .h = h
    };
    SDL_BlitScaled(plancheSprites, &sprite, pWindowSurface, &coordinates);
}

int getElementFromMazeArray(struct Coordinates pos) 
{
    return newMapArray[pos.y][pos.x];
}

struct Coordinates searchElementInMazeArray(MazeObstacles element) 
{
    for (int i = 0; i < MAZE_HEIGHT_IN_ARRAY; i++)
    {
        for (int j = 0; j < MAZE_WIDTH_IN_ARRAY; j++)
        {
            if (newMapArray[i][j] == element)
            {
                return (struct Coordinates){j, i};
            }
        }
    }
    return (struct Coordinates){-1, -1};
}

struct Coordinates searchElementInMazeArrayByOccurenceNumber(MazeObstacles element, int occurenceNumber) 
{
    int occurence = 0;
    for (int i = 0; i < MAZE_HEIGHT_IN_ARRAY; i++)
    {
        for (int j = 0; j < MAZE_WIDTH_IN_ARRAY; j++)
        {
            if (newMapArray[i][j] == element)
            {
                occurence++;
                if (occurence == occurenceNumber)
                {
                    return (struct Coordinates){j, i};
                }
            }
        }
    }
    return (struct Coordinates){-1, -1};
}

bool isInArrayRange (struct Coordinates pos) 
{
    return pos.x >= 0 && pos.x < MAZE_WIDTH_IN_ARRAY && pos.y >= 0 && pos.y < MAZE_HEIGHT_IN_ARRAY;
}

void setElementInMazeArray(MazeObstacles element, struct Coordinates pos) 
{
    if (isInArrayRange(pos))
    {
        newMapArray[pos.y][pos.x] = element;
    }
}

void removeElementFromMazeArray(MazeObstacles element)
{
    struct Coordinates coordinates = searchElementInMazeArray(element);
    if (coordinates.x != -1 && coordinates.y != -1)
    {
        newMapArray[coordinates.y][coordinates.x] = 0;
    }
}

int getMapArrayValue(int mapArray[27][21] , int x, int y) 
{
    return mapArray[y][x];
}

bool isObstacle(struct Coordinates coordinates)
{
    MazeObstacles element = getMapArrayValue(newMapArray, coordinates.x, coordinates.y);
    return element == WALL;
}

bool isColliding(struct Coordinates coordinates, int hitboxOffset)
{
    for (int i = 0; i <= hitboxOffset; i += hitboxOffset)
    {
        for (int j = 0; j <= hitboxOffset; j += hitboxOffset)
        {
            if (isObstacle(getUIToGridPosition((struct Coordinates){
                    coordinates.x + i,
                    coordinates.y + j,
            })))
                return true;
        }
    }

    return false;
}

void displayMazeInConsole()
{
    for (int i = 0; i < MAZE_HEIGHT_IN_ARRAY; i++)
    {
        for (int j = 0; j < MAZE_WIDTH_IN_ARRAY; j++)
        {
            printf("%d", newMapArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}