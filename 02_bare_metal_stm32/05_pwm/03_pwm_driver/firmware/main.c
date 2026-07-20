#include "pwm.h"

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

    while (1)
    {
        pwm_set_duty(&led_pwm, 25);
    }
}