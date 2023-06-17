#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../utils/renderer.h"


void initGame();
void initGameLoop();
int getScore();
int getHighScore();
int getPacmanLives();
void setScore(int newScore);
void setHighScore(int newHighScore);
void setPacmanLives(int newPacmanLives);

#endif