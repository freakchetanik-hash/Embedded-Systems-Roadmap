#ifndef SOFTWARE_TIMER_H
#define SOFTWARE_TIMER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint32_t start_time;
    uint32_t period;

} SoftwareTimer;

void timer_start(SoftwareTimer *timer, uint32_t period);

bool timer_expired(SoftwareTimer *timer);

#endif