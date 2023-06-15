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
int fps = 0;
bool isPacmanEating = false;


void drawGameBackground(){
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the background image onto the window surface
    SDL_BlitScaled(plancheSprites, &src_bg, pWindowSurface, &bg);

    // Init in maze elements
    initMaze(); // TEST
}

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

void drawGameGraphics(){
    // Draw the background image onto the window surface
    drawGameBackground();

    // Animate and draw the ghosts
    animateGhosts();

    // Draw pacman
    spawnPacman();
    drawPacman();
    pacmanEventHandler();
    fps++;
}