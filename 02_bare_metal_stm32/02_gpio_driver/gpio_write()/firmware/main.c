#include "gpio.h"

void delay(uint32_t count)
{
    for (volatile uint32_t i = 0; i < count; i++);
}

int main(void)
{
    /* Initialize PA5 as Output */
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_write(GPIOA, 5, GPIO_HIGH);
        delay(500000);

        gpio_write(GPIOA, 5, GPIO_LOW);
        delay(500000);
    }
}