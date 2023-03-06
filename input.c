#include "input.h"

//to be cleaned and optimized
bool input(SDL_Rect* pacman){
        int nbk;
        const Uint8* keys = SDL_GetKeyboardState(&nbk);
        printf("LEFT pos x : %d\n", pacman->x);
        printf("DOWN pos y : %d\n", pacman->y);

        if (keys[SDL_SCANCODE_ESCAPE]){
            return true;
        }
        if (keys[SDL_SCANCODE_LEFT]){
            printf("LEFT pos x : %d\n", pacman->x);
            if(pacman->x-4>=pacman->w && pacman->x-4<=(672-(pacman->w*2))){
            pacman->x-=4;
            }
        }
        if (keys[SDL_SCANCODE_RIGHT]){
            printf("RIGHT pos x : %d\n", pacman->x);
            if(pacman->x+4>=pacman->w && pacman->x+4<=(672-(pacman->w*2))){
            pacman->x+=4;
            }
        }
        if (keys[SDL_SCANCODE_UP]){
            printf("UP pos y : %d\n", pacman->y);
            if(pacman->y-4>=pacman->h+4 && pacman->y-4<=(864-4-(pacman->h*2))){
            pacman->y-=4;}
        }
        if (keys[SDL_SCANCODE_DOWN]){
            printf("DOWN pos y : %d\n", pacman->y);
            if(pacman->y+4>=pacman->h+4 && pacman->y+4<=(864-4-(pacman->h*2))){
            pacman->y+=4;
            }
        }
        return false;
    }