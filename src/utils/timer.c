#include "timer.h"


void Timer_init(struct Timer *timer, int duration)
{
    timer->isRunning = false;
    timer->isDone = false;
    timer->duration = duration;
}

void Timer_start(struct Timer *timer)
{
    timer->isRunning = true;
    timer->startTime = clock();
}

void Timer_stop(struct Timer *timer)
{
    timer->isRunning = false;
    timer->isDone = false;
}

void Timer_reset(struct Timer *timer)
{
    timer->isRunning = false;
    timer->isDone = false;
    timer->startTime = clock();
}

void Timer_update(struct Timer *timer)
{
    if (timer->isRunning)
    {
        // with timer duration in seconds
        if (clock() - timer->startTime >= timer->duration * CLOCKS_PER_SEC)
        {
            timer->isDone = true;
            timer->isRunning = false;
        }
    }
}

bool Timer_isDone(struct Timer *timer)
{
    return timer->isDone;
}