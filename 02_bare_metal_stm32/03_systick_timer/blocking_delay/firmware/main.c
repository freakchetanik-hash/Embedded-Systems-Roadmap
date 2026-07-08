#include "gpio.h"
#include "systick.h"

int main(void)
{
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    systick_init();

    while (1)
    {
        gpio_write(GPIOA, 5, GPIO_HIGH);
        delay_ms(500);

        gpio_write(GPIOA, 5, GPIO_LOW);
        delay_ms(500);
    }
}