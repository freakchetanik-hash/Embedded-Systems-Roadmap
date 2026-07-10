#include "systick.h"

/*---------------------------------------------------------
    Internal Helper Function
---------------------------------------------------------*/
static void wait_1ms(void)
{
    while ((SYSTICK->CTRL &
           (1U << SYSTICK_CTRL_COUNTFLAG_Pos)) == 0)
    {
        /* Wait until COUNTFLAG becomes 1 */
    }
}

/*---------------------------------------------------------
    Initialize SysTick
---------------------------------------------------------*/
void systick_init(void)
{
    /* 16 MHz / 1000 = 16000 counts = 1 ms */
    SYSTICK->LOAD = 16000U - 1U;

    /* Clear current value */
    SYSTICK->VAL = 0U;

    /* Enable SysTick
       CPU Clock
       Interrupt Disabled
    */
    SYSTICK->CTRL =
        (1U << SYSTICK_CTRL_ENABLE_Pos) |
        (1U << SYSTICK_CTRL_CLKSOURCE_Pos);
}

/*---------------------------------------------------------
    Blocking Delay
---------------------------------------------------------*/
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms; i++)
    {
        wait_1ms();
    }
}