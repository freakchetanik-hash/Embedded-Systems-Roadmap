#include "systick.h"

/*=========================================================
    Private Variables
=========================================================*/

static volatile uint32_t system_ticks = 0;

/*=========================================================
    Public Functions
=========================================================*/

void systick_init(void)
{
    /* 16 MHz / 1000 = 16000 counts = 1 ms */

    SYSTICK->LOAD = 16000U - 1U;

    SYSTICK->VAL = 0U;

    SYSTICK->CTRL =
        (1U << SYSTICK_CTRL_ENABLE_Pos) |
        (1U << SYSTICK_CTRL_TICKINT_Pos) |
        (1U << SYSTICK_CTRL_CLKSOURCE_Pos);
}

uint32_t millis(void)
{
    return system_ticks;
}

/*=========================================================
    Interrupt Handler
=========================================================*/

void SysTick_Handler(void)
{
    system_ticks++;
}