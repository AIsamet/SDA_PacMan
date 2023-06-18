#include <stdbool.h>
#include "utils/renderer.h"
#include "main/game.h"
#include "main/input.h"
#include "main/level.h"


int main(int argc, char** argv) 
{
    initGameLoop();

    freeSDL();
    
    return 0;
}