// Taylor Seale, Iheanyi Ekechukwu, Ryan Shea, Andrew Caron
// Fundamentals of Computing II: Final Project
// timer.cpp: This is the implementation file for the Timer class which handles the in game clock

#include "timer.h"
#include "SDL/SDL.h"

Timer::Timer(){ //constructor
    //Initialize the variables
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}

void Timer::start(){ //begins timer
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
}

void Timer::stop(){ //stops timer
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;
}

void Timer::pause(){ //pauses timer
    //If the timer is running and isn't already paused
    if((started == true) && (paused == false)){
        //Pause the timer
        paused = true;

        //Calculate the paused ticks
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Timer::unpause(){ //resumes timer
    //If the timer is paused
    if( paused == true )
    {
        //Unpause the timer
        paused = false;

        //Reset the starting ticks
        startTicks = SDL_GetTicks() - pausedTicks;

        //Reset the paused ticks
        pausedTicks = 0;
    }
}

int Timer::get_ticks(){ //returns ticks of timer
    //If the timer is running
    if( started == true )
    {
        //If the timer is paused
        if( paused == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks;
        }
    }

    //If the timer isn't running
    return 0;
}

bool Timer::is_started(){ //checks if timer has been started
    return started;
}

bool Timer::is_paused(){ //checks if timer is paused
    return paused;
}
