#include <SDL.h>

#include <stdio.h>
#include <stdbool.h>

#include "input.h"

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

SDL_Rect pacman_eat = { 34,89, 14,16 };
SDL_Rect pacman_closed = { 3,89, 16,16 };
SDL_Rect pacman_r = { 20,89, 16,16 }; 
SDL_Rect pacman_l = { 20,89, 16,16 }; 
SDL_Rect pacman_d = { 20,89, 16,16 }; 
SDL_Rect pacman_u = { 20,89, 16,16 }; 
SDL_Rect pacman = { 32,36, 32,32 };

int count;

void init()
{
	pWindow = SDL_CreateWindow("PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 672, 864, SDL_WINDOW_SHOWN);
	win_surf = SDL_GetWindowSurface(pWindow);

	plancheSprites = SDL_LoadBMP("./pacman_sprites.bmp");
    count = 0;
}


// fonction qui met à jour la surface de la fenetre "win_surf"
void draw()
{
    SDL_SetColorKey(plancheSprites, false, 0);
    SDL_BlitScaled(plancheSprites, &src_bg, win_surf, &bg);

    SDL_Rect* ghost_in = NULL;
    SDL_Rect* pacman_in = &(pacman_r);

    switch (count/128)
    {
        case 0:
            ghost_in = &(ghost_r);
            ghost.x++;
            break;
        case 1:
            ghost_in = &(ghost_d);
            ghost.y++;
            break;
        case 2:
            ghost_in = &(ghost_l);
            ghost.x--;
            break;
        case 3:
            ghost_in = &(ghost_u);
            ghost.y--;
            break;
    }
    count =(count+1)%(512);

    SDL_Rect ghost_in2 = *ghost_in;
    if ((count/4)%2)
        ghost_in2.x += 17;
        
    SDL_Rect pacman_in2 = *pacman_in;
    if ((count/4)%2)
        pacman_in2 = pacman_eat;
        if (count%4 == 0)
            pacman_in2 = pacman_closed;

    SDL_SetColorKey(plancheSprites, true, 0);

	SDL_BlitScaled(plancheSprites, &ghost_in2, win_surf, &ghost);

    SDL_BlitScaled(plancheSprites, &pacman_in2, win_surf, &pacman);

}



int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
		fprintf(stderr,"Echec de l'initialisation de la SDL %s",SDL_GetError());
       	return 1;
    }

    init();
        
	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			default: break;
			}
		}
        int nbk;
        const Uint8* keys = SDL_GetKeyboardState(&nbk);
        if (keys[SDL_SCANCODE_ESCAPE])
            quit = true;
        if (keys[SDL_SCANCODE_LEFT])
            puts("LEFT");
        if (keys[SDL_SCANCODE_RIGHT])
            puts("RIGHT");
        if (keys[SDL_SCANCODE_UP])
            puts("UP");
        if (keys[SDL_SCANCODE_DOWN])
            puts("DOWN");

		draw();

        SDL_Delay(20); // ~50 fps use SDL_GetTicks64() pour plus de precision
		SDL_UpdateWindowSurface(pWindow);
	}
    SDL_Quit();
    return 0;
}
