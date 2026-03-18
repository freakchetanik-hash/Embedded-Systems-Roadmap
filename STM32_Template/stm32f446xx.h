#ifndef STM32F446XX_H
#define STM32F446XX_H

#include <stdint.h>

/*************** BASE ADDRESSES ****************/

#define PERIPH_BASE        0x40000000UL
#define AHB1PERIPH_BASE    (PERIPH_BASE + 0x00020000UL)

/*************** GPIO ****************/

#define GPIOA_BASE (AHB1PERIPH_BASE + 0x0000UL)

/*************** RCC ****************/

#define RCC_BASE   (AHB1PERIPH_BASE + 0x3800UL)

/*************** STRUCTURES ****************/

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO_TypeDef;

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;

    uint32_t RESERVED0[8];

    volatile uint32_t AHB1ENR;
} RCC_TypeDef;

/*************** PERIPHERAL DEFINITIONS ****************/

#define GPIOA ((GPIO_TypeDef*) GPIOA_BASE)
#define RCC   ((RCC_TypeDef*) RCC_BASE)

#endif