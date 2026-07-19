#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include "stm32f446xx.h"

/*-------------------------------------------------
 * Function Prototypes
 *------------------------------------------------*/

/**
 * @brief Initialize TIM2 Channel 1 for PWM output.
 *
 * PA5  -> TIM2_CH1 (AF1)
 * PWM Frequency -> 1 kHz
 */
void pwm_init(void);

/**
 * @brief Set PWM duty cycle.
 *
 * @param duty Duty cycle in percentage (0 - 100)
 */
void pwm_set_duty(uint8_t duty);

#endif // PWM_H