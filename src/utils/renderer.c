#include "renderer.h"


void initGraphics()
{   
    // Init SDL 
    initSDL();

    // Init SDL game window
    initWindow();

    // Init common graphics
    initCommonGraphics();

    // Init the maze
    initMaze();

    // Init Pacman
    initPacman();

    // Init the ghosts
    initGhost();
}