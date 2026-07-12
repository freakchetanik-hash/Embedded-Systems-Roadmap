#include "timer.h"
#include "stm32f446xx.h"

/*-------------------------------------------------
 * Private System Tick
 *------------------------------------------------*/
static volatile uint32_t system_ticks = 0;

void timer_init(void)
{
    /* Enable TIM2 Clock */
    RCC->APB1ENR |= (1U << RCC_APB1ENR_TIM2EN_Pos);

    /* Timer Tick = 1 ms */
    TIM2->PSC = 15;

    /* Overflow every 1 count -> interrupt every 1 ms */
    TIM2->ARR = 999;
    TIM2->EGR = 1;
    /* Start from zero */
    TIM2->CNT = 0;

     /* Enable Update Interrupt */
    TIM2->DIER |= (1U << TIM_DIER_UIE_Pos);

    /* Enable TIM2 Interrupt in NVIC */
    NVIC_ISER0 |= (1U << 28);

    /* Start Timer */
    TIM2->CR1 |= (1U << TIM_CR1_CEN_Pos);
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & (1U << TIM_SR_UIF_Pos))
    {
        TIM2->SR &= ~(1U << TIM_SR_UIF_Pos);

        system_ticks++;
    }
}

/*-------------------------------------------------
 * Return Current Tick
 *------------------------------------------------*/
uint32_t millis(void)
{
    return system_ticks;
}

/*-------------------------------------------------
 * Start Timer
 *------------------------------------------------*/
void timer_start(timer_t *timer, uint32_t period)
{
    timer->start_time = millis();
    timer->period = period;
}

/*-------------------------------------------------
 * Check Expiration
 *------------------------------------------------*/
bool timer_expired(timer_t *timer)
{
    uint32_t elapsed = millis() - timer->start_time;

    if (elapsed >= timer->period)
    {
        return true;
    }

    return false;
}

/*-------------------------------------------------
 * Restart Timer
 *------------------------------------------------*/
void timer_restart(timer_t *timer)
{
    timer->start_time = millis();
}