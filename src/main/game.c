#include "main/game.h"

int score;
int highScore;
int pacmanLives;
bool isGameStarted = false;
bool isGameRunning = false;
bool isGamePaused = false;
bool isGameOver = false;

void initGame() 
{
    score = DEFAULT_SCORE;
    highScore = DEFAULT_HIGH_SCORE;
    pacmanLives = PACMAN_LIVES;  
    isGameStarted = true;  
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

void addScore(int scoreToAdd) 
{
    score += scoreToAdd;

    if (score > highScore)
        highScore = score;
}

void addHighScore(int highScoreToAdd) 
{
    highScore += highScoreToAdd;
}

void addPacmanLives(int livesToAdd) 
{
    pacmanLives += livesToAdd;
}