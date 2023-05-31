#include "input.h"


void handleInput(bool* quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                // If the quit event is triggered, set quit to true
                *quit = true;
                break;
            case SDL_KEYDOWN:
                // Handle key presses
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        // If the Escape key is pressed, set quit to true
                        *quit = true;
                        break;
                    case SDLK_LEFT:
                        // If the Left arrow key is pressed, print "LEFT"
                        puts("LEFT");
                        break;
                    case SDLK_RIGHT:
                        // If the Right arrow key is pressed, print "RIGHT"
                        puts("RIGHT");
                        break;
                    case SDLK_UP:
                        // If the Up arrow key is pressed, print "UP"
                        puts("UP");
                        break;
                    case SDLK_DOWN:
                        // If the Down arrow key is pressed, print "DOWN"
                        puts("DOWN");
                        break;
                }
                break;
            default:
                break;
        }
    }
}
