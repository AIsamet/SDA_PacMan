#include "main/game.h"

int score;
int highScore;
int pacmanLives;
bool isGameStarted = false;
bool isGameRunning = false;
bool isGamePaused = false;
bool isGameOver = false;
clock_t gameStartTime;

void initGame() 
{
    clock_t gameStartTime = clock();

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

void removeScore(int scoreToRemove) 
{
    score -= scoreToRemove;
}

void removeHighScore(int highScoreToRemove) 
{
    highScore -= highScoreToRemove;
}

void removePacmanLives(int livesToRemove) 
{
    pacmanLives -= livesToRemove;
}

bool getIsGameStarted() 
{
    return isGameStarted;
}

bool getIsGameRunning() 
{
    // wait for 3 seconds before starting the game
    if ((clock() - gameStartTime) / CLOCKS_PER_SEC > GAME_RUNNING_WAIT_DELAY)    
    {
        isGameRunning = true;
    }
    return isGameRunning;
}