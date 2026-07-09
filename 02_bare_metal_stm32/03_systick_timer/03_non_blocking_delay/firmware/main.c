#include "gpio.h"
#include "systick.h"

int main(void)
{
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    systick_init();

    uint32_t last_toggle = 0;

    while (1)
    {
        if ((millis() - last_toggle) >= 500)
        {
            last_toggle = millis();

            gpio_toggle(GPIOA, 5);
        }

        /* CPU is FREE here */

        // read_button();
        // uart_process();
        // check_emergency();
        // read_sensor();
    }
}