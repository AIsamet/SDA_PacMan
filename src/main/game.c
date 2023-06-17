#include "main/game.h"

int score;
int highScore;
int pacmanLives;

void initGame() 
{
    score = DEFAULT_SCORE;
    highScore = DEFAULT_HIGH_SCORE;
    pacmanLives = PACMAN_LIVES;    
}

void initGameLoop() 
{
    initGame();
    initGraphics();
}

int getScore() 
{
    return score;
}

int getHighScore() 
{
    return highScore;
}

int getPacmanLives() 
{
    return pacmanLives;
}

void setScore(int newScore) 
{
    score = newScore;
}

void setHighScore(int newHighScore) 
{
    highScore = newHighScore;
}

void setPacmanLives(int newPacmanLives) 
{
    pacmanLives = newPacmanLives;
}