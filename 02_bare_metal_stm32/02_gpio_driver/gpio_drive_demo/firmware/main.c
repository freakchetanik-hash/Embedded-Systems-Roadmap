#include "gpio.h"

void delay(uint32_t count)
{
    for (volatile uint32_t i = 0; i < count; i++);
}

int main(void)
{
    /*-------------------------------------------------------
        Initialize Peripherals
    -------------------------------------------------------*/

    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);   // LD2
    gpio_init(GPIOC, 13, GPIO_MODE_INPUT);   // User Button

    /*-------------------------------------------------------
        Application Loop
    -------------------------------------------------------*/

    while (1)
    {
        /* Button Pressed ? */
        if (gpio_read(GPIOC, 13) == GPIO_LOW)
        {
            /* Toggle LED */
            gpio_toggle(GPIOA, 5);

            /* Debounce Delay */
            delay(200000);

            /* Wait Until Button is Released */
            while (gpio_read(GPIOC, 13) == GPIO_LOW)
            {
                /* Do Nothing */
            }
        }
    }
}