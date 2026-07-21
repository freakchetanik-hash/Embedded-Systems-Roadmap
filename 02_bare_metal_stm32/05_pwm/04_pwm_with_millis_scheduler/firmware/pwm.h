#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "stm32f446xx.h"

/******************************************************************
 * PWM Channels
 ******************************************************************/

#define PWM_CHANNEL_1      1U
#define PWM_CHANNEL_2      2U
#define PWM_CHANNEL_3      3U
#define PWM_CHANNEL_4      4U

/******************************************************************
 * GPIO Alternate Functions
 ******************************************************************/

#define GPIO_AF1           1U
#define GPIO_AF2           2U
#define GPIO_AF3           3U

/******************************************************************
 * PWM Handle
 ******************************************************************/

typedef struct
{
    TIM_TypeDef  *TIMx;

    GPIO_TypeDef *GPIOx;

    uint8_t pin;

    uint8_t alternate_function;

    uint8_t channel;

    uint32_t frequency;

} PWM_Handle_t;

/******************************************************************
 * Function Prototypes
 ******************************************************************/

void pwm_init(PWM_Handle_t *handle);

void pwm_set_duty(PWM_Handle_t *handle,
                  uint8_t duty);

#endif // PWM_H