#include "pwm.h"

int main(void)
{
    /* Initialize PWM */
    pwm_init();

    /* Set LED Brightness to 50% */
    pwm_set_duty(50);

    while (1)
    {
        /* Hardware PWM runs automatically */
    }
}