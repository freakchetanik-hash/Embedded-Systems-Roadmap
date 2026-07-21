#include "pwm.h"
#include "timer.h"

#include <stdbool.h>
#include <stdint.h>

int main(void)
{
    PWM_Handle_t led_pwm;

    led_pwm.TIMx = TIM2;
    led_pwm.GPIOx = GPIOA;
    led_pwm.pin = 5;
    led_pwm.alternate_function = GPIO_AF1;
    led_pwm.channel = PWM_CHANNEL_1;
    led_pwm.frequency = 1000;

    pwm_init(&led_pwm);

    timer_init();          // Your millis() timer

    uint32_t previous_time = 0;

    uint8_t duty = 0;

    bool increasing = true;

    while (1)
    {
        if ((millis() - previous_time) >= 10)
        {
            previous_time = millis();

            /* Display current duty */
            pwm_set_duty(&led_pwm, duty);

            /* Prepare next duty */
            if (increasing)
            {
                if (duty < 100)
                {
                    duty++;
                }
                else
                {
                    increasing = false;
                }
            }
            else
            {
                if (duty > 0)
                {
                    duty--;
                }
                else
                {
                    increasing = true;
                }
            }
        }

        /* CPU is free for other work */
    }
}