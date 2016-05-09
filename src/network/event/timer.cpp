/*
 * libevent timer
 * usage: event_init() => evtimer_set() => event_add() => event_dispatch()
 */

#include <iostream>
#include <event.h>
using namespace std;

// callback
void onTimer(int sock, short event, void *arg)
{
    cout << "Game Over!" << endl;
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    // add event again
    event_add((struct event*)arg, &tv);
}

int main()
{
    // 1. initialize
    event_init();

    struct event evTime;
    // 2. set timer
    evtimer_set(&evTime, onTimer, &evTime);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    // 3. add event
    event_add(&evTime, &tv);

    // 4. event loop
    event_dispatch();

    return 0;
}

    
