#include <stdint.h>

#define RCC_BASE        0x40023800UL
#define GPIOA_BASE      0x40020000UL

#define RCC_AHB1ENR     (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define GPIOA_MODER     (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

void delay(void)
{
    for(volatile uint32_t i = 0; i < 500000; i++);
}

int main(void)
{
    /* Enable GPIOA clock */
    RCC_AHB1ENR |= (1 << 0);

    /* Configure PA5 as output */
    GPIOA_MODER &= ~(3 << (5 * 2));
    GPIOA_MODER |=  (1 << (5 * 2));

    while(1)
    {
        GPIOA_ODR ^= (1 << 5);
        delay();
    }
}