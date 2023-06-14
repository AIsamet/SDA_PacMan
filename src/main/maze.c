#include "main/maze.h"

const int MAZE_WIDTH = 21;
const int MAZE_HEIGHT = 27;
SDL_Rect pacGum = { 4, 81, 2, 2 };
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
//    struct  Position position = { 0,0 };
//    drawIntoMaze(pacman_closed, position, 32, 32, 32, 32);
}

void drawPacGum(SDL_Rect pacGum, SDL_Rect superPacGum){
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            struct Position position = getGridToUIPosition((struct Position){j, i});

            if(map_array[i][j] == 2) {
                drawIntoMaze(pacGum, position, pacGum.x, pacGum.y, pacGum.w, pacGum.h);
            }
            if(map_array[i][j] == 3) {
                drawIntoMaze(superPacGum, position, superPacGum.x, superPacGum.y, superPacGum.w, superPacGum.h);
            }
        }
    }
}

struct Position getGridToUIPosition(struct Position pos) {
    struct Position position;
    position.x = pos.x * 25;
    position.y = pos.y * 25;
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