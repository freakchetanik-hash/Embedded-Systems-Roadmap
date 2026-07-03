#include "stm32f446xx.h"

static void delay(void)
{
    for (volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    /*-------------------------------------------------------
      Step 1: Enable GPIOA Clock
      RCC_AHB1ENR bit 0 = GPIOA Clock Enable
    -------------------------------------------------------*/
    RCC->AHB1ENR |= (1U << 0);

    /*-------------------------------------------------------
      Step 2: Configure PA5 as General Purpose Output

      MODER5 = 01

      Bits:
      11 10
       0  1
    -------------------------------------------------------*/
    GPIOA->MODER &= ~(3U << (5 * 2));   // Clear bits 11:10
    GPIOA->MODER |=  (1U << (5 * 2));   // Set bit 10

    /*-------------------------------------------------------
      Step 3: Toggle LED Forever
    -------------------------------------------------------*/
    while (1)
    {
        GPIOA->ODR ^= (1U << 5);     // Toggle PA5

        delay();
    }
}