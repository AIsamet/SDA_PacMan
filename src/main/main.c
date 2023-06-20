#include <stdbool.h>
#include "../utils/renderer.h"
#include "game.h"
#include "input.h"
#include "level.h"


int main(int argc, char** argv) 
{
    initGraphics();

    startMainMenu();

    freeSDL();
    
    return 0;
}