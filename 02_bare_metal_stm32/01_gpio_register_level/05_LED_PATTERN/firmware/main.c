#include "stm32f446xx.h"
#include <stdint.h>

/*-------------------------------------------------------
    Delay Definitions
-------------------------------------------------------*/
#define SHORT_DELAY     150000U
#define MEDIUM_DELAY    250000U
#define LONG_DELAY      500000U
#define VERY_LONG_DELAY 1000000U

/*-------------------------------------------------------
    LED Helper Functions
-------------------------------------------------------*/

void led_on(void)
{
    GPIOA->ODR |= (1U << 5);
}

void led_off(void)
{
    GPIOA->ODR &= ~(1U << 5);
}

void led_toggle(void)
{
    GPIOA->ODR ^= (1U << 5);
}

/*-------------------------------------------------------
    Software Delay
-------------------------------------------------------*/

void delay(uint32_t time)
{
    for (volatile uint32_t i = 0; i < time; i++);
}

/*-------------------------------------------------------
    LED Patterns
-------------------------------------------------------*/

/* Pattern 1 : Slow Blink */
void slow_blink(void)
{
    led_on();
    delay(LONG_DELAY);

    led_off();
    delay(LONG_DELAY);
}

/* Pattern 2 : Fast Blink */
void fast_blink(void)
{
    led_on();
    delay(SHORT_DELAY);

    led_off();
    delay(SHORT_DELAY);
}

/* Pattern 3 : Double Blink */
void double_blink(void)
{
    led_on();
    delay(MEDIUM_DELAY);

    led_off();
    delay(MEDIUM_DELAY);

    led_on();
    delay(MEDIUM_DELAY);

    led_off();
    delay(LONG_DELAY);
}

/* Pattern 4 : Heartbeat */
void heartbeat_pattern(void)
{
    led_on();
    delay(100000);

    led_off();
    delay(100000);

    led_on();
    delay(100000);

    led_off();
    delay(700000);
}

/* Pattern 5 : SOS (... --- ...) */
void sos_pattern(void)
{
    /* ---------- S ---------- */
    for(int i = 0; i < 3; i++)
    {
        led_on();
        delay(SHORT_DELAY);

        led_off();
        delay(SHORT_DELAY);
    }

    delay(MEDIUM_DELAY);

    /* ---------- O ---------- */
    for(int i = 0; i < 3; i++)
    {
        led_on();
        delay(LONG_DELAY);

        led_off();
        delay(SHORT_DELAY);
    }

    delay(MEDIUM_DELAY);

    /* ---------- S ---------- */
    for(int i = 0; i < 3; i++)
    {
        led_on();
        delay(SHORT_DELAY);

        led_off();
        delay(SHORT_DELAY);
    }

    delay(VERY_LONG_DELAY);
}

/*-------------------------------------------------------
    Main
-------------------------------------------------------*/

int main(void)
{
    /* Enable GPIOA Clock */
    RCC->AHB1ENR |= (1U << 0);

    /* Configure PA5 as Output */
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    while (1)
    {
        /* Uncomment ONLY ONE pattern */

        // slow_blink();

        // fast_blink();

        // double_blink();

        // heartbeat_pattern();

        sos_pattern();
    }
}