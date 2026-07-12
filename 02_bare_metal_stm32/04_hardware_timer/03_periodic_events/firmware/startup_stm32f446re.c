#include <stdint.h>

/* Linker Symbols */
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

/* Function Prototypes */
int main(void);
void Reset_Handler(void);
void Default_Handler(void);
void EXTI15_10_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)
    __attribute__((weak, alias("Default_Handler")));    
/* Weak aliases for interrupts */
void NMI_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)      __attribute__((weak, alias("Default_Handler")));

/* Default Handler */
void Default_Handler(void)
{
    while (1);
}

/* Reset Handler */
void Reset_Handler(void)
{
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;

    while (dst < &_edata)
    {
        *dst++ = *src++;
    }

    dst = &_sbss;

    while (dst < &_ebss)
    {
        *dst++ = 0;
    }

    main();

    while (1);
}

/* Vector Table */
__attribute__((section(".isr_vector")))
const void *VectorTable[] =
{
    &_estack,              /* Initial Stack Pointer */
    Reset_Handler,         /* Reset */
    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    /* External Interrupts 0-39 */
    [16 ... 55] = Default_Handler,

    /* IRQ28 = TIM2 */
    [44] = TIM2_IRQHandler,

    /* IRQ40 = EXTI15_10 */
    [56] = EXTI15_10_IRQHandler,
};