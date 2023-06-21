#include "game.h"

int score;
int pacmanLives;
int highScore = DEFAULT_HIGH_SCORE;
bool isGameStarted;
bool isGameRunning;
bool isGamePaused;
bool isGameOver;
struct Timer gameStartTime;

void initGame() 
{
    bool isGameStarted = false;
    bool isGameRunning = false;
    bool isGamePaused = false;
    bool isGameOver = false;

    score = DEFAULT_SCORE;
    pacmanLives = PACMAN_LIVES;
}

void initGameTimers()
{
    Timer_init(&gameStartTime, GAME_RUNNING_WAIT_DELAY);
}

void startGameTimers()
{
    Timer_start(&gameStartTime);
}

void initGameLoop() 
{
    initGame();
    initGameTimers();
}

void resetGameLoop() 
{
    isGameRunning = false;
    isGameStarted = false;
    Timer_reset(&gameStartTime);
  
    score = DEFAULT_SCORE;
    highScore = DEFAULT_HIGH_SCORE;
    pacmanLives = PACMAN_LIVES;

    initGraphics();
}

void startGame() 
{
    initGameLoop();
    startGameTimers();
    startGameGraphics();
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
    if(Timer_isDone(&gameStartTime))
    {
        isGameRunning = true;
    }
    else
    {
        isGameRunning = false;
    }
    return isGameRunning;
}

bool getIsGameOver() 
{
    if(getPacmanLives() == 0)
    {
        isGameOver = true;
    }
    else
    {
        isGameOver = false;
    }
    return isGameOver;
}