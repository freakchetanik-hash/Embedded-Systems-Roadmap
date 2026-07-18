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

    volatile uint32_t RCR;      /* Repetition Counter Register */
    volatile uint32_t CCR1;     /* Capture Compare Register 1 */
    volatile uint32_t CCR2;     /* Capture Compare Register 2 */
    volatile uint32_t CCR3;     /* Capture Compare Register 3 */
    volatile uint32_t CCR4;     /* Capture Compare Register 4 */

    volatile uint32_t BDTR;     /* Break and Dead-Time Register */
    volatile uint32_t DCR;      /* DMA Control Register */
    volatile uint32_t DMAR;     /* DMA Address Register */

} TIM_TypeDef;

#define TIM2       ((TIM_TypeDef *)TIM2_BASE)

/******************************************************************
 *                     Bit Position Definitions
 ******************************************************************/

/*-------------------------------------------------
 * RCC
 *------------------------------------------------*/

/* GPIO Clock Enable */
#define RCC_AHB1ENR_GPIOAEN_Pos      0U
#define RCC_AHB1ENR_GPIOBEN_Pos      1U
#define RCC_AHB1ENR_GPIOCEN_Pos      2U
#define RCC_AHB1ENR_GPIODEN_Pos      3U
#define RCC_AHB1ENR_GPIOEEN_Pos      4U

/* TIM2 Clock Enable */
#define RCC_APB1ENR_TIM2EN_Pos       0U

/*-------------------------------------------------
 * TIM2 - CR1
 *------------------------------------------------*/
#define TIM_CR1_CEN_Pos              0U

/*-------------------------------------------------
 * TIM2 - DIER
 *------------------------------------------------*/
#define TIM_DIER_UIE_Pos             0U

/*-------------------------------------------------
 * TIM2 - SR
 *------------------------------------------------*/
#define TIM_SR_UIF_Pos               0U

/*-------------------------------------------------
 * TIM2 - EGR
 *------------------------------------------------*/
#define TIM_EGR_UG_Pos               0U

/*-------------------------------------------------
 * TIM2 - CCMR1
 *------------------------------------------------*/
#define TIM_CCMR1_CC1S_Pos           0U
#define TIM_CCMR1_OC1FE_Pos          2U
#define TIM_CCMR1_OC1PE_Pos          3U
#define TIM_CCMR1_OC1M_Pos           4U

/*-------------------------------------------------
 * TIM2 - CCER
 *------------------------------------------------*/
#define TIM_CCER_CC1E_Pos            0U
#define TIM_CCER_CC1P_Pos            1U

/*-------------------------------------------------
 * GPIO Pin Numbers
 *------------------------------------------------*/
#define GPIO_PIN_0                   0U
#define GPIO_PIN_1                   1U
#define GPIO_PIN_2                   2U
#define GPIO_PIN_3                   3U
#define GPIO_PIN_4                   4U
#define GPIO_PIN_5                   5U
#define GPIO_PIN_6                   6U
#define GPIO_PIN_7                   7U
#define GPIO_PIN_8                   8U
#define GPIO_PIN_9                   9U
#define GPIO_PIN_10                  10U
#define GPIO_PIN_11                  11U
#define GPIO_PIN_12                  12U
#define GPIO_PIN_13                  13U
#define GPIO_PIN_14                  14U
#define GPIO_PIN_15                  15U

#endif // STM32F446XX_H