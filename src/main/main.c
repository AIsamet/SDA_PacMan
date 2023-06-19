#include <stdbool.h>
#include "../utils/renderer.h"
#include "game.h"
#include "input.h"
#include "level.h"


int main(int argc, char** argv) 
{
    initGameLoop();

    freeSDL();
    
    return 0;
}