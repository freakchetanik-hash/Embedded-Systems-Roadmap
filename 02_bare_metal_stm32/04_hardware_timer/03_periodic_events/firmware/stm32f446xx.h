#ifndef STM32F446XX_H
#define STM32F446XX_H

#include <stdint.h>

/******************************************************************
 *                     BASE ADDRESSES
 ******************************************************************/

#define PERIPH_BASE         0x40000000UL

#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000UL)

/******************************************************************
 *                     GPIO BASE ADDRESSES
 ******************************************************************/

#define GPIOA_BASE          (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x1000UL)

/******************************************************************
 *                     RCC
 ******************************************************************/

#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800UL)

/******************************************************************
 *                     TIMERS
 ******************************************************************/

#define TIM2_BASE           (APB1PERIPH_BASE + 0x0000UL)

/******************************************************************
 *                     SYSCFG
 ******************************************************************/

#define SYSCFG_BASE         (APB2PERIPH_BASE + 0x3800UL)

/******************************************************************
 *                     EXTI
 ******************************************************************/

#define EXTI_BASE           (APB2PERIPH_BASE + 0x3C00UL)

/******************************************************************
 *                     NVIC
 ******************************************************************/

#define NVIC_ISER0          (*(volatile uint32_t*)0xE000E100)
#define NVIC_ISER1          (*(volatile uint32_t*)0xE000E104)

#define NVIC_ICER0          (*(volatile uint32_t*)0xE000E180)
#define NVIC_ICER1          (*(volatile uint32_t*)0xE000E184)

/******************************************************************
 *                     GPIO Registers
 ******************************************************************/

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;

} GPIO_TypeDef;

/******************************************************************
 *                     RCC Registers
 ******************************************************************/

typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;

    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;

    uint32_t RESERVED0;

    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;

    uint32_t RESERVED1[2];

    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;

    uint32_t RESERVED2;

    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;

} RCC_TypeDef;

/******************************************************************
 *                     SYSCFG Registers
 ******************************************************************/

typedef struct
{
    volatile uint32_t MEMRMP;
    volatile uint32_t PMC;
    volatile uint32_t EXTICR[4];

} SYSCFG_TypeDef;

/******************************************************************
 *                     EXTI Registers
 ******************************************************************/

typedef struct
{
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RTSR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;

} EXTI_TypeDef;

/******************************************************************
 *                     Peripheral Definitions
 ******************************************************************/

#define GPIOA      ((GPIO_TypeDef*) GPIOA_BASE)
#define GPIOB      ((GPIO_TypeDef*) GPIOB_BASE)
#define GPIOC      ((GPIO_TypeDef*) GPIOC_BASE)
#define GPIOD      ((GPIO_TypeDef*) GPIOD_BASE)
#define GPIOE      ((GPIO_TypeDef*) GPIOE_BASE)

#define RCC        ((RCC_TypeDef*) RCC_BASE)

#define SYSCFG     ((SYSCFG_TypeDef*) SYSCFG_BASE)

#define EXTI       ((EXTI_TypeDef*) EXTI_BASE)
#define TIM2       ((TIM_TypeDef *)TIM2_BASE)

/******************************************************************
 *                     TIM Registers
 ******************************************************************/

typedef struct
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;

} TIM_TypeDef;

/******************************************************************
 *                     TIM Bit Positions
 ******************************************************************/

#define TIM_CR1_CEN_Pos          0U

#define TIM_DIER_UIE_Pos         0U

#define TIM_SR_UIF_Pos           0U

#define RCC_APB1ENR_TIM2EN_Pos   0U

#endif