#include "graphics.h"


// Global graphics variables
SDL_Window* pWindow = NULL;
SDL_Surface* win_surf = NULL;
SDL_Surface* plancheSprites = NULL;

SDL_Rect src_bg = { 200,3, 168,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 4,4, 672,864 }; // ici scale x4

SDL_Rect ghost_r = { 3,123, 16,16 }; 
SDL_Rect ghost_l = { 37,123, 16,16 }; 
SDL_Rect ghost_d = { 105,123, 16,16 }; 
SDL_Rect ghost_u = { 71,123, 16,16 }; 
SDL_Rect ghost = { 34,34, 32,32 };     // ici scale x2
int count;


void initWindow()
{
	// Create the game window with the title "PacMan" and the specified dimensions
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 900, SDL_WINDOW_SHOWN);

	// Get the surface associated with the window for drawing
	win_surf = SDL_GetWindowSurface(pWindow);

	// Load the sprite sheet containing the game graphics from the specified BMP file
	plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");

	// Initialize the count variable to 0 (used for animation)
	count = 0;
}

void initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Echec de l'initialisation de la SDL %s", SDL_GetError());
        return;
    }
}

void initGraphics(){
    initSDL();
    initWindow();
    graphicsHandler();
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
    SDL_BlitScaled(plancheSprites, &ghost_in2, win_surf, &ghost);
}

void draw()
{
    // Set the color key for transparent pixels in the sprite sheet
    SDL_SetColorKey(plancheSprites, false, 0);

    // Draw the background image onto the window surface
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);

    // Animate and draw the ghosts
    animateGhosts();
}

void destroyGraphics()
{
    // Free the sprite sheet surface
    SDL_FreeSurface(plancheSprites);

    // Destroy the window
    SDL_DestroyWindow(pWindow);

    // Quit SDL
    SDL_Quit();
}

void graphicsHandler(){
    bool quit = false;

    while (!quit) {
        handleInput(&quit);
        draw();
        SDL_Delay(20);
        SDL_UpdateWindowSurface(pWindow);
    }

    destroyGraphics();
}