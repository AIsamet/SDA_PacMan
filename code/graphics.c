#include "graphics.h"


// Global graphics variables
SDL_Window* pWindow = NULL;
SDL_Surface* win_surf = NULL;
SDL_Surface* plancheSprites = NULL;

SDL_Rect src_bg = { 201,3, 167,216 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect bg = { 4,4, 672,864 }; // ici scale x4

SDL_Rect ghost_r = { 3,123, 16,16 }; 
SDL_Rect ghost_l = { 37,123, 16,16 }; 
SDL_Rect ghost_d = { 105,123, 16,16 }; 
SDL_Rect ghost_u = { 71,123, 16,16 }; 
SDL_Rect ghost = { 32,36, 32,32 };     // ici scale x2

SDL_Rect pacman_spawn = { 20,89, 15,16 };
SDL_Rect pacman_eat = { 34,89, 14,16 };
SDL_Rect pacman_closed = { 3,89, 16,16 };
SDL_Rect pacman_r = { 20,89, 15,16 }; 
SDL_Rect pacman_l = { 47,89, 15,16 }; 
SDL_Rect pacman_d = { 109,90, 16,15 }; 
SDL_Rect pacman_u = { 75,90, 16,15 }; 
SDL_Rect pacman = { 32,36, 32,32 };
SDL_Rect* pacman_in = &pacman_spawn;

int count;


void initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Echec de l'initialisation de la SDL %s", SDL_GetError());
        return;
    }
}

void initWindow()
{
	// Create the game window with the title "PacMan" and the specified dimensions
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 672, 864, SDL_WINDOW_SHOWN);

	// Get the surface associated with the window for drawing
	win_surf = SDL_GetWindowSurface(pWindow);

	// Load the sprite sheet containing the game graphics from the specified BMP file
	plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");

	// Initialize the count variable to 0 (used for animation)
	count = 0;
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

    // Draw Pac-Man at its current position
    SDL_BlitScaled(plancheSprites, pacman_in, win_surf, &pacman);
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
        inputHandler(&quit, &pacman_in);
        draw();
        SDL_Delay(20);
        SDL_UpdateWindowSurface(pWindow);
    }

    destroyGraphics();
}

bool isPacmanInMapLimits(int x, int y){
    int new_x = pacman.x + x;
    int new_y = pacman.y + y;

    // Check horizontal limits
    if (new_x < pacman.w || new_x > (672 - pacman.w*2)) {
        return false;
    }

    // Check vertical limits (+1 to make pacman centered)
    if (new_y < pacman.h+1 || new_y > (864 - pacman.h*2)+1) {
        return false;
    }

    return true;
}


void movePacmanLeft(SDL_Rect** pacman_in) {
    if(isPacmanInMapLimits(-4, 0)){
        pacman.x -= 4;
        *pacman_in = &pacman_l;
    }
}

void movePacmanRight(SDL_Rect** pacman_in) {
    if(isPacmanInMapLimits(4, 0)){
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
    if(isPacmanInMapLimits(0, 4)){
        pacman.y += 4;
        *pacman_in = &pacman_d;
    }
}
