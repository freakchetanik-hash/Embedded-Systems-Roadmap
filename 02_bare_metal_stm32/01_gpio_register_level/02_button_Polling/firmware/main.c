#include "stm32f446xx.h"

int main(void)
{
    /*-------------------------------------------------------
      Enable GPIOA Clock (LED)
    -------------------------------------------------------*/
    RCC->AHB1ENR |= (1U << 0);

    /*-------------------------------------------------------
      Enable GPIOC Clock (Button)
    -------------------------------------------------------*/
    RCC->AHB1ENR |= (1U << 2);

    /*-------------------------------------------------------
      PA5 -> Output
    -------------------------------------------------------*/
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    /*-------------------------------------------------------
      PC13 -> Input
      (Reset state is already Input, but we'll explicitly
      configure it for clarity.)
    -------------------------------------------------------*/
    GPIOC->MODER &= ~(3U << (13 * 2));

    while (1)
    {
        /* Blue button is ACTIVE LOW */

        if ((GPIOC->IDR & (1U << 13)) == 0)
        {
            /* Button Pressed */
            GPIOA->ODR |= (1U << 5);
        }
        else
        {
            /* Button Released */
            GPIOA->ODR &= ~(1U << 5);
        }
    }
}