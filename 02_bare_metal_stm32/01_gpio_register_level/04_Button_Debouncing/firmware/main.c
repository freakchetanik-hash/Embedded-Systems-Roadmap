#include "stm32f446xx.h"

/*-----------------------------
    GPIO Initialization
------------------------------*/
void gpio_init(void)
{
    /* Enable GPIOA Clock */
    RCC->AHB1ENR |= (1U << 0);

    /* Enable GPIOC Clock */
    RCC->AHB1ENR |= (1U << 2);

    /* PA5 -> Output */
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    /* PC13 -> Input */
    GPIOC->MODER &= ~(3U << (13 * 2));
}

/*-----------------------------
    Button Interrupt Init
------------------------------*/
void button_interrupt_init(void)
{
    /* Enable SYSCFG Clock */
    RCC->APB2ENR |= (1U << 14);

    /* Connect EXTI13 to GPIOC */
    SYSCFG->EXTICR[3] &= ~(0xFU << 4);
    SYSCFG->EXTICR[3] |=  (2U << 4);

    /* Falling Edge Trigger */
    EXTI->FTSR |= (1U << 13);

    /* Disable Rising Edge */
    EXTI->RTSR &= ~(1U << 13);

    /* Unmask EXTI13 */
    EXTI->IMR |= (1U << 13);

    /* Enable IRQ40 (EXTI15_10) */
    NVIC_ISER1 |= (1U << 8);
}

void delay(void)
{
    for (volatile uint32_t i = 0; i < 200000; i++);
}
/*-----------------------------
    Interrupt Handler
------------------------------*/
void EXTI15_10_IRQHandler(void)
{
    /* Toggle LED */
    GPIOA->ODR ^= (1U << 5);
   
    /* Wait until bouncing stops */
    delay();
    
    /* Clear Pending Flag */
    EXTI->PR = (1U << 13);
}

/*-----------------------------
    Main
------------------------------*/
int main(void)
{
    gpio_init();

    button_interrupt_init();

    while (1)
    {
    }
}