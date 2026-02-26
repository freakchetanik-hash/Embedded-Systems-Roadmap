#include <stdint.h>

extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss, _estack;
extern void main(void);

void Reset_Handler(void) {
    // Copy data section from FLASH to RAM
    uint32_t *pSrc = &_sidata;
    uint32_t *pDest = &_sdata;
    while (pDest < &_edata) *pDest++ = *pSrc++;

    // Initialize BSS section to zero
    pDest = &_sbss;
    while (pDest < &_ebss) *pDest++ = 0;

    main();
    while (1);
}

// Vector Table
__attribute__((section(".isr_vector")))
uint32_t const v_table[] = {
    (uint32_t)&_estack,
    (uint32_t)&Reset_Handler
};