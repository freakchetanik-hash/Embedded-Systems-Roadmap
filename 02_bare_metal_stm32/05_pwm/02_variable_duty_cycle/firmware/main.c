#include <stdint.h>
#include <stdbool.h>

#include "pwm.h"

void delay(void)
{
    for (volatile uint32_t i = 0; i < 50000; i++);
}

int main(void)
{
    uint8_t duty = 0;
    bool increasing = true;

    pwm_init();

    while (1)
    {
        if (increasing)
        {
            duty++;

            if (duty >= 100)
            {
                duty = 100;
                increasing = false;
            }
        }
        else
        {
            duty--;

            if (duty == 0)
            {
                increasing = true;
            }
        }

        pwm_set_duty(duty);

        delay();
    }
}