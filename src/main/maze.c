#include "main/maze.h"

SDL_Rect pacGum = { 1, 78, 8, 8 };
SDL_Rect superPacGum = { 9, 79, 7, 7 };

// Maze modelisation
// 0 : Emplacement vide
// 1 : Mur
// 2 : PacGomme
// 3 : Super PacGomme
// 4 : Porte de la maison des fantomes
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
        { 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 1, 4, 4, 4, 1, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 0, 1, 0, 0, 0, 1, 0, 1, 2, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 2, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1, 1, 1, 1, 1 },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
        { 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1 },
        { 1, 3, 2, 2, 1, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 1, 2, 2, 3, 1 },
        { 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1 },
        { 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1 },
        { 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1 },
        { 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1 },
        { 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void initMaze() {
    drawPacGum(pacGum, superPacGum);
}

void drawPacGum(SDL_Rect pacGum, SDL_Rect superPacGum){
for (int i = 0; i < MAZE_HEIGHT_IN_ARRAY ; i++)
    {
        for (int j = 0; j < MAZE_WIDTH_IN_ARRAY; j++)
        {
            struct Position position = getGridToUIPosition((struct Position){j, i});

            if(map_array[i][j] == 2) {
                drawIntoMaze(pacGum, position, PACGUM_X, PACGUM_Y, PACGUM_W, PACGUM_H);
            }
            if(map_array[i][j] == 3) {
                drawIntoMaze(superPacGum, position, PACGUM_X, PACGUM_Y, PACGUM_W, PACGUM_H);
            }
        }
    }
}

struct Position getGridToUIPosition(struct Position pos) {
    struct Position position;
    position.x = pos.x * CELL_SIZE;
    position.y = pos.y * CELL_SIZE;
    return position;
}

void drawIntoMaze(SDL_Rect sprite, struct Position positionToDraw, int x, int y, int w, int h){
    SDL_Rect position;
    position.x = positionToDraw.x + x;
    position.y = positionToDraw.y + y;
    position.w = w;
    position.h = h;
    SDL_BlitScaled(plancheSprites, &sprite, pWindowSurface, &position);
}