#include "graphics/gameGraphics.h"

SDL_Rect src_bg = { 369,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 4,4, 672,864 }; // ici scale x4

SDL_Rect ghost_r = { 3,123, 16,16 };
SDL_Rect ghost_l = { 37,123, 16,16 };
SDL_Rect ghost_d = { 105,123, 16,16 };
SDL_Rect ghost_u = { 71,123, 16,16 };
SDL_Rect ghost = { 32,36, 32,32 };     // ici scale x2

SDL_Rect pacman_closed = { 4,90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_spawn = { 21,90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_eat_r = { 38, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_eat_l = { 72, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_eat_d = { 140, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_eat_u = { 106, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_r = { 21,90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_l = { 56, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_d = { 123, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman_u = { 89, 90, PACMAN_SIZE, PACMAN_SIZE };
SDL_Rect pacman = { 32,32, 32,32 };
SDL_Rect* pacman_in = &pacman_spawn;

int count = 0;
bool isPacmanEating = false;

void animateGhosts()
{
    // Variable to hold the current ghost sprite rectangle
    SDL_Rect* ghost_in = NULL;

    // Determine the current ghost sprite based on the count value
    switch (count / 128)
    {
        case 0:
            ghost_in = &(ghost_r); // Right-facing ghost sprite
            ghost.x++; // Move the ghost one unit to the right
            break;
        case 1:
            ghost_in = &(ghost_d); // Down-facing ghost sprite
            ghost.y++; // Move the ghost one unit down
            break;
        case 2:
            ghost_in = &(ghost_l); // Left-facing ghost sprite
            ghost.x--; // Move the ghost one unit to the left
            break;
        case 3:
            ghost_in = &(ghost_u); // Up-facing ghost sprite
            ghost.y--; // Move the ghost one unit up
            break;
    }

    // Increment the count value and wrap it around to 0 when it reaches 512
    count = (count + 1) % 512;

    // Create a copy of the current ghost sprite rectangle
    SDL_Rect ghost_in2 = *ghost_in;

    // Modify the ghost sprite rectangle if it is in the alternate state
    if ((count / 4) % 2)
        ghost_in2.x += 17;

    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, true, 0);

    // Draw the appropriate ghost sprite onto the window surface
    SDL_BlitScaled(plancheSprites, &ghost_in2, pWindowSurface, &ghost);
}

void animatePacman(){
    if ((count / 4) % 2 == 0)
    {
        isPacmanEating = true;
    }
    else
    {
        isPacmanEating = false;
    }
}

void drawGameBackground(){
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the background image onto the window surface
    SDL_BlitScaled(plancheSprites, &src_bg, pWindowSurface, &bg);

    // Init in maze elements
    initMaze(); // TEST
}

void drawPacMan(){
    if (isPacmanEating)
    {
        if (pacman_in == &pacman_r)
        {
            SDL_BlitScaled(plancheSprites, &pacman_eat_r, pWindowSurface, &pacman);
        }
        else if(pacman_in == &pacman_l)
        {
            SDL_BlitScaled(plancheSprites, &pacman_eat_l, pWindowSurface, &pacman);
        }
        else if(pacman_in == &pacman_d)
        {
            SDL_BlitScaled(plancheSprites, &pacman_eat_d, pWindowSurface, &pacman);
        }
        else if(pacman_in == &pacman_u)
        {
            SDL_BlitScaled(plancheSprites, &pacman_eat_u, pWindowSurface, &pacman);
        }
        else
        {
            SDL_BlitScaled(plancheSprites, &pacman_eat_r, pWindowSurface, &pacman);
        }
    }
    else
    {
        SDL_BlitScaled(plancheSprites, pacman_in, pWindowSurface, &pacman);
    }
}

void drawGameGraphics(){
    // Draw the background image onto the window surface
    drawGameBackground();

    // Animate and draw the ghosts
    animateGhosts();
    animatePacman();

    // Draw pacman
    drawPacMan();
}


bool isPacmanInMapLimits(double x, double y) {
    double new_x = pacman.x + x;
    double new_y = pacman.y + y;
    double pacman_x = pacman.x;
    double pacman_y = pacman.y;
    double tolerance = 0.0001; // Adjust the tolerance as needed

//    printf("current pacman_x = %f, current pacman_y = %f\n", pacman_x, pacman_y); // TEST
//    printf("new_x = %f, new_y = %f\n", new_x, new_y);

//    printf("New x = %f, new y = %f\n", new_x, new_y);
    getCurrentPositionInArray(&pacman_x, &pacman_y); // TEST
    getCurrentPositionInArray(&new_x, &new_y); // Overwrite

//    printf("current pacman_x = %f, current pacman_y = %f\n", pacman_x, pacman_y); // TEST
//    printf("new_x = %f, new_y = %f\n", new_x, new_y);
//    printf("BOOL: %d\n", (fabs(pacman_x - floor(pacman_x)) < tolerance) && (fabs(pacman_y - floor(pacman_y)) < tolerance));

    if (map_array[(int)new_y][(int)new_x] == 1) {
//        printf("new_x = %f, new_y = %f\n", new_x, new_y);
        return false;
    } else {
//        printf("new_x = %f, new_y = %f\n", new_x, new_y);
        return true;
    }

//    if ((fabs(pacman_x - floor(pacman_x)) < tolerance) && (fabs(pacman_y - floor(pacman_y)) < tolerance)) {
//        if (map_array[(int)new_y][(int)new_x] == 1) {
//            printf("Current pacman_x = %f, current pacman_y = %f\n", pacman_x, pacman_y); // TEST
//            printf("new_x = %f, new_y = %f\n", new_x, new_y);
//            return false;
//        } else {
//            printf("Current pacman_x = %f, current pacman_y = %f\n", pacman_x, pacman_y); // TEST
//            printf("new_x = %f, new_y = %f\n", new_x, new_y);
//            return true;
//        }
//    }

    return false;
}



void movePacmanLeft(SDL_Rect** pacman_in) {
    if(isPacmanInMapLimits(-4, 0)){
        pacman.x -= 4;
        *pacman_in = &pacman_l;
    }

}

void movePacmanRight(SDL_Rect** pacman_in) {
    if(isPacmanInMapLimits(PACMAN_SIZE, 0)){
        pacman.x += 4;
        *pacman_in = &pacman_r;
    }
}

void movePacmanUp(SDL_Rect** pacman_in) {
    if(isPacmanInMapLimits(0, -4)){
        pacman.y -= 4;
        *pacman_in = &pacman_u;
    }
}

void movePacmanDown(SDL_Rect** pacman_in) {
    if(isPacmanInMapLimits(0, PACMAN_SIZE)){
        pacman.y += 4;
        *pacman_in = &pacman_d;
    }
}

void getCurrentPositionInArray(double* x, double* y) {
    double arrayX = MAZE_WIDTH/MAZE_WIDTH_IN_ARRAY;
    double arrayY = MAZE_HEIGHT/MAZE_HEIGHT_IN_ARRAY;
    *x = *x/arrayX;
    *y = *y/arrayY;
}