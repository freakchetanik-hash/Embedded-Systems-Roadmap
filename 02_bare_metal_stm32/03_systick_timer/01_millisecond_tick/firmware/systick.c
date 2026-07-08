#include "systick.h"

void systick_init(void)
{
    /*---------------------------------------------
        Reload Value
        16 MHz / 1000 = 16000 cycles = 1 ms
    ---------------------------------------------*/
    SYSTICK->LOAD = 16000U - 1U;

    /*---------------------------------------------
        Clear Current Value Register
    ---------------------------------------------*/
    SYSTICK->VAL = 0U;

    /*---------------------------------------------
        Enable SysTick
        CPU Clock
        Interrupt Disabled
    ---------------------------------------------*/
    SYSTICK->CTRL =
            (1U << SYSTICK_CTRL_ENABLE_Pos) |
            (1U << SYSTICK_CTRL_CLKSOURCE_Pos);
}