# ifndef TIMER_H
# define TIMER_H

# include <stdint.h>
#include "stm32f446xx.h"

typedef struct
{
    volatile uint32_t CR1;      /* Control Register 1 */
    volatile uint32_t CR2;      /* Control Register 2 */
    volatile uint32_t SMCR;     /* Slave Mode Control Register */
    volatile uint32_t DIER;     /* DMA/Interrupt Enable Register */
    volatile uint32_t SR;       /* Status Register */
    volatile uint32_t EGR;      /* Event Generation Register */
    volatile uint32_t CCMR1;    /* Capture/Compare Mode Register 1 */
    volatile uint32_t CCMR2;    /* Capture/Compare Mode Register 2 */
    volatile uint32_t CCER;     /* Capture/Compare Enable Register */
    volatile uint32_t CNT;      /* Counter Register */
    volatile uint32_t PSC;      /* Prescaler Register */
    volatile uint32_t ARR;      /* Auto Reload Register */

} TIM_TypeDef;

#define TIM2_BASE              0x40000000UL
#define TIM2                  ((TIM_TypeDef *)TIM2_BASE)

#define TIM_CR1_CEN_Pos        0U
#define RCC_APB1ENR_TIM2EN_Pos  0U

void timer_init(void);

#endif