#include "pwm.h"

void pwm_init(PWM_Handle_t *handle)
{
    /**************************************************************
     * Enable GPIO Clock
     **************************************************************/
    if (handle->GPIOx == GPIOA)
    {
        RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOAEN_Pos);
    }
    else if (handle->GPIOx == GPIOB)
    {
        RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOBEN_Pos);
    }
    else if (handle->GPIOx == GPIOC)
    {
        RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOCEN_Pos);
    }
    else if (handle->GPIOx == GPIOD)
    {
        RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIODEN_Pos);
    }
    else if (handle->GPIOx == GPIOE)
    {
        RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOEEN_Pos);
    }

    /**************************************************************
     * Enable Timer Clock
     **************************************************************/
    if (handle->TIMx == TIM2)
    {
        RCC->APB1ENR |= (1U << RCC_APB1ENR_TIM2EN_Pos);
    }

    /**************************************************************
     * Configure GPIO Alternate Function Mode
     **************************************************************/
    handle->GPIOx->MODER &= ~(3U << (handle->pin * 2U));
    handle->GPIOx->MODER |=  (2U << (handle->pin * 2U));

    /**************************************************************
     * Configure Alternate Function
     **************************************************************/
    volatile uint32_t *afr;
    uint8_t shift;

    if (handle->pin < 8U)
    {
        afr = &handle->GPIOx->AFRL;
        shift = handle->pin * 4U;
    }
    else
    {
        afr = &handle->GPIOx->AFRH;
        shift = (handle->pin - 8U) * 4U;
    }

    *afr &= ~(0xFU << shift);
    *afr |= ((uint32_t)handle->alternate_function << shift);

    /**************************************************************
     * Timer Configuration
     **************************************************************/

    /* 16 MHz / (15+1) = 1 MHz */
    handle->TIMx->PSC = 15;

    /* 1 MHz / (999+1) = 1 kHz PWM */
    handle->TIMx->ARR = 999;

    /**************************************************************
     * PWM Mode 1
     **************************************************************/

    handle->TIMx->CCMR1 &= ~(7U << 4);
    handle->TIMx->CCMR1 |=  (6U << 4);

    /* Enable CCR preload */
    handle->TIMx->CCMR1 |= (1U << 3);

    /**************************************************************
     * Enable Channel 1
     **************************************************************/

    handle->TIMx->CCER |= (1U << 0);

    /**************************************************************
     * Initial Duty Cycle
     **************************************************************/

    handle->TIMx->CCR1 = 0;

    /**************************************************************
     * Generate Update Event
     **************************************************************/

    handle->TIMx->EGR |= (1U << 0);

    /**************************************************************
     * Enable Timer
     **************************************************************/

    handle->TIMx->CR1 |= (1U << 0);
}

/******************************************************************
 * Set Duty Cycle
 ******************************************************************/

void pwm_set_duty(PWM_Handle_t *handle, uint8_t duty)
{
    if (duty > 100U)
    {
        duty = 100U;
    }

    handle->TIMx->CCR1 =
        ((handle->TIMx->ARR + 1U) * duty) / 100U;
}