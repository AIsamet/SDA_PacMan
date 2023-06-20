#include <stdbool.h>
#include "../utils/renderer.h"
#include "game.h"
#include "input.h"
#include "level.h"


int main(int argc, char** argv) 
{
    // Init SDL 
    initSDL();

    // Init SDL game window
    initWindow();

    // Init game graphics
    initGraphics();

    // Start the main menu
    startMainMenu();

    // Free ressources and quit SDL
    freeSDL();
    
    return 0;
}