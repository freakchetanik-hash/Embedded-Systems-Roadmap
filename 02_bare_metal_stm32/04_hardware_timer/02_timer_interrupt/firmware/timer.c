#include "timer.h"

volatile uint32_t system_ticks = 0;

void timer_init(void)
{
    /* Enable TIM2 Clock */
    RCC->APB1ENR |= (1U << RCC_APB1ENR_TIM2EN_Pos);

    /* Timer Tick = 1 ms */
    TIM2->PSC = 15999;

    /* Overflow after 1000 counts = 1 second */
    TIM2->ARR = 999;

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
    /* Clear Update Interrupt Flag */
    TIM2->SR &= ~(1U << TIM_SR_UIF_Pos);

    /* Application Work */
    system_ticks++;
}