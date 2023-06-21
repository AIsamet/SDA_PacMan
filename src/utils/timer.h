#ifndef TIMER_H
#define TIMER_H
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// using clock_t
struct Timer
{
    clock_t startTime;
    int duration;
    bool isRunning;
    bool isDone;
};

void Timer_init(struct Timer *timer, int duration);
void Timer_start(struct Timer *timer);
void Timer_stop(struct Timer *timer);
void Timer_reset(struct Timer *timer);
void Timer_update(struct Timer *timer);
bool Timer_isDone(struct Timer *timer);

#endif