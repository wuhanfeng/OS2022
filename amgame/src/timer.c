#include <game.h>

int uptime()
{
    AM_TIMER_UPTIME_T event;
    event.us = 0;
    ioe_read(AM_TIMER_UPTIME, &event);
    return event.us;
}