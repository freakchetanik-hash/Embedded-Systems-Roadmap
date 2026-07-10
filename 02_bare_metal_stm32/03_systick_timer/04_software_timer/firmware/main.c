#include "gpio.h"
#include "systick.h"
#include "software_timer.h"

int main(void)
{
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    systick_init();

    SoftwareTimer led_timer;

    timer_start(&led_timer, 500);

    while (1)
    {
        if (timer_expired(&led_timer))
        {
            gpio_toggle(GPIOA, 5);
        }

        /* CPU is FREE */

        // read_uart();
        // read_button();
        // read_adc();
        // check_emergency();
    }
}