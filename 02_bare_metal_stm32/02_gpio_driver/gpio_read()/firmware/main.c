#include "gpio.h"

void delay(uint32_t count)
{
    for (volatile uint32_t i = 0; i < count; i++);
}

int main(void)
{
    /* Initialize LED */
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    /* Initialize Button */
    gpio_init(GPIOC, 13, GPIO_MODE_INPUT);

    while (1)
    {
        if (gpio_read(GPIOC, 13) == GPIO_LOW)
        {
            gpio_write(GPIOA, 5, GPIO_HIGH);
        }
        else
        {
            gpio_write(GPIOA, 5, GPIO_LOW);
        }
    }
}