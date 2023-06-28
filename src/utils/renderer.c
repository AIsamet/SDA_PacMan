#include "renderer.h"


void initGraphics()
{   
    // Init common graphics
    initCommonGraphics();

    // Init the maze
    initMaze();

    // Init Pacman
    initPacman();

    // Init the ghosts
    initGhost();
}