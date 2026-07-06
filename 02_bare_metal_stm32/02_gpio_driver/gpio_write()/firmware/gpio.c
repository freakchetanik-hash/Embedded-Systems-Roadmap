#include "gpio.h"

/*-----------------------------------------------------------
    GPIO Initialization
-----------------------------------------------------------*/
void gpio_init(GPIO_TypeDef *GPIOx,
               uint8_t pin,
               uint8_t mode)
{
    /*-------------------------------------------------------
        Enable GPIO Clock
    -------------------------------------------------------*/
    if (GPIOx == GPIOA)
    {
        RCC->AHB1ENR |= (1U << 0);
    }
    else if (GPIOx == GPIOB)
    {
        RCC->AHB1ENR |= (1U << 1);
    }
    else if (GPIOx == GPIOC)
    {
        RCC->AHB1ENR |= (1U << 2);
    }

    /*-------------------------------------------------------
        Configure Pin Mode
    -------------------------------------------------------*/
    GPIOx->MODER &= ~(3U << (pin * 2));

    GPIOx->MODER |= (mode << (pin * 2));
}

/*-----------------------------------------------------------
    GPIO Write
-----------------------------------------------------------*/
void gpio_write(GPIO_TypeDef *GPIOx,
                uint8_t pin,
                uint8_t value)
{
    if (value == GPIO_HIGH)
    {
        GPIOx->ODR |= (1U << pin);
    }
    else
    {
        GPIOx->ODR &= ~(1U << pin);
    }
}