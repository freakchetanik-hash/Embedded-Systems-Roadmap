#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>

/*-------------------------------------------------
 * Periodic Timer Object
 *------------------------------------------------*/
typedef struct
{
    uint32_t start_time;
    uint32_t period;

} timer_t;

/*-------------------------------------------------
 * Hardware Timer Driver
 *------------------------------------------------*/
void timer_init(void);

/*-------------------------------------------------
 * System Tick API
 *------------------------------------------------*/
uint32_t millis(void);

/*-------------------------------------------------
 * Periodic Timer API
 *------------------------------------------------*/
void timer_start(timer_t *timer, uint32_t period);

bool timer_expired(timer_t *timer);

void timer_restart(timer_t *timer);

#endif