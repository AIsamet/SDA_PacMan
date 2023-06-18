#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../utils/renderer.h"

extern bool isGameStarted;
extern bool isGameRunning;
extern bool isGamePaused;
extern bool isGameOver;


void initGame();
void initGameLoop();
int getScore();
int getHighScore();
int getPacmanLives();
void setScore(int newScore);
void setHighScore(int newHighScore);
void setPacmanLives(int newPacmanLives);
void addScore(int scoreToAdd);
void addHighScore(int highScoreToAdd);
void addPacmanLives(int livesToAdd);

#endif