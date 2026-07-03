ENTRY(Reset_Handler)

/*=========================================================
  Memory Map
=========================================================*/
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}

/* Initial Stack Pointer */
_estack = ORIGIN(RAM) + LENGTH(RAM);

/*=========================================================
  Sections
=========================================================*/
SECTIONS
{
    /*---------------- Vector Table + Code ----------------*/
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
    } > FLASH

    /* Start address of initialized data in FLASH */
    _sidata = LOADADDR(.data);

    /*---------------- Initialized Data ----------------*/
    .data :
    {
        _sdata = .;
        *(.data*)
        _edata = .;
    } > RAM AT > FLASH

    /*---------------- Uninitialized Data ----------------*/
    .bss :
    {
        _sbss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM
}