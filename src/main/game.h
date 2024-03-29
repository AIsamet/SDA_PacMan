#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../utils/renderer.h"
#include "../utils/timer.h"

extern struct Timer gameOverTimer;
extern struct Timer gameReadyTimer;
extern bool isGameStarted;
extern bool isGameRunning;
extern bool isGamePaused;
extern bool isGameOver;


void initGame();
void initGameTimers();
void startGameTimers();
void initGameLoop();
void startGame();
int getScore();
int getHighScore();
int getPacmanLives();
void setScore(int newScore);
void setHighScore(int newHighScore);
void setPacmanLives(int newPacmanLives);
void addScore(int scoreToAdd);
void addHighScore(int highScoreToAdd);
void addPacmanLives(int livesToAdd);
void removeScore(int scoreToRemove);
void removeHighScore(int highScoreToRemove);
void removePacmanLives(int livesToRemove);
bool getIsGameStarted();
bool getIsGameRunning();
bool getIsGameOver();

#endif