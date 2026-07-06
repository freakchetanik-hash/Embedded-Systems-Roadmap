#include "gpio.h"
#include <stdint.h>

/*-------------------------------------------------------
    Global Application State
-------------------------------------------------------*/
static uint8_t current_pattern = 0;

/*-------------------------------------------------------
    Function Prototypes
-------------------------------------------------------*/
void delay(uint32_t count);
void button_update(void);

void pattern_slow(void);
void pattern_fast(void);
void pattern_sos(void);

void morse_symbol(uint32_t on_time);

/*-------------------------------------------------------
    Delay Function
-------------------------------------------------------*/
void delay(uint32_t count)
{
    for (volatile uint32_t i = 0; i < count; i++);
}

/*-------------------------------------------------------
    Button Handler
-------------------------------------------------------*/
void button_update(void)
{
    /* Button not pressed */
    if (gpio_read(GPIOC, 13) != GPIO_LOW)
    {
        return;
    }

    /* Next Pattern */
    current_pattern++;

    /* Wrap Around */
    if (current_pattern > 2)
    {
        current_pattern = 0;
    }

    /* Debounce */
    delay(200000);

    /* Wait Until Released */
    while (gpio_read(GPIOC, 13) == GPIO_LOW)
    {
    }
}

/*-------------------------------------------------------
    Pattern 1 : Slow Blink
-------------------------------------------------------*/
void pattern_slow(void)
{
    gpio_write(GPIOA, 5, GPIO_HIGH);
    delay(500000);

    gpio_write(GPIOA, 5, GPIO_LOW);
    delay(500000);
}

/*-------------------------------------------------------
    Pattern 2 : Fast Blink
-------------------------------------------------------*/
void pattern_fast(void)
{
    gpio_write(GPIOA, 5, GPIO_HIGH);
    delay(100000);

    gpio_write(GPIOA, 5, GPIO_LOW);
    delay(100000);
}

/*-------------------------------------------------------
    Reusable Morse Symbol
-------------------------------------------------------*/
void morse_symbol(uint32_t on_time)
{
    gpio_write(GPIOA, 5, GPIO_HIGH);
    delay(on_time);

    gpio_write(GPIOA, 5, GPIO_LOW);
    delay(100000);
}

/*-------------------------------------------------------
    Pattern 3 : SOS (... --- ...)
-------------------------------------------------------*/
void pattern_sos(void)
{
    /* S = ... */
    morse_symbol(100000);
    morse_symbol(100000);
    morse_symbol(100000);

    delay(300000);

    /* O = --- */
    morse_symbol(300000);
    morse_symbol(300000);
    morse_symbol(300000);

    delay(300000);

    /* S = ... */
    morse_symbol(100000);
    morse_symbol(100000);
    morse_symbol(100000);

    /* Gap before repeating */
    delay(700000);
}

/*-------------------------------------------------------
    Main
-------------------------------------------------------*/
int main(void)
{
    /* LD2 */
    gpio_init(GPIOA, 5, GPIO_MODE_OUTPUT);

    /* User Button */
    gpio_init(GPIOC, 13, GPIO_MODE_INPUT);

    while (1)
    {
        button_update();

        switch (current_pattern)
        {
            case 0:
                pattern_slow();
                break;

            case 1:
                pattern_fast();
                break;

            case 2:
                pattern_sos();
                break;

            default:
                current_pattern = 0;
                break;
        }
    }
}