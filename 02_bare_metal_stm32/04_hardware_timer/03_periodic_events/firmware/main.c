#include "gpio.h"
#include "timer.h"

int main(void)
{
    /* Configure PA5 as Output (Nucleo LED) */
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    /* Initialize TIM2 */
    timer_init();

    /* Create a periodic timer object */
    timer_t led_timer;

    /* Start 900 ms timer */
    timer_start(&led_timer, 900);

    while (1)
    {
        if (timer_expired(&led_timer))
        {
            gpio_toggle(GPIOA, 5);

            timer_restart(&led_timer);
        }
    }
}