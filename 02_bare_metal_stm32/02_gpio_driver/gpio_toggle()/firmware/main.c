#include "gpio.h"

void delay(uint32_t count)
{
    for (volatile uint32_t i = 0; i < count; i++);
}

int main(void)
{
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_toggle(GPIOA, 5);
        delay(500000);
    }
}