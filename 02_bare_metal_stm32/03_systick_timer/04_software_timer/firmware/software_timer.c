#include "software_timer.h"
#include "systick.h"

void timer_start(SoftwareTimer *timer, uint32_t period)
{
    timer->start_time = millis();
    timer->period = period;
}

bool timer_expired(SoftwareTimer *timer)
{
    if ((millis() - timer->start_time) >= timer->period)
    {
        timer->start_time = millis();   // Auto-restart (periodic)

        return true;
    }

    return false;
}