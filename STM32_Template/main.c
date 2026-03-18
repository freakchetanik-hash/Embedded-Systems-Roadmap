#include "stm32f446xx.h"

void delay(void)
{
    for(volatile int i = 0; i < 500000; i++);
}

int main(void)
{
    // Enable GPIOA clock
    RCC->AHB1ENR |= (1 << 0);

    // PA5 as output
    GPIOA->MODER &= ~(3 << (5 * 2));
    GPIOA->MODER |=  (1 << (5 * 2));

    while(1)
    {
        GPIOA->ODR ^= (1 << 5);
        delay();
    }
}