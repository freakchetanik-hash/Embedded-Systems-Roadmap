#ifndef GPIO_H
#define GPIO_H

#include "stm32f446xx.h"
#include <stdint.h>

/*-----------------------------------------------------------
    GPIO Modes
-----------------------------------------------------------*/
#define GPIO_MODE_INPUT      0U
#define GPIO_MODE_OUTPUT     1U

/*-----------------------------------------------------------
    GPIO States
-----------------------------------------------------------*/
#define GPIO_LOW             0U
#define GPIO_HIGH            1U

/*-----------------------------------------------------------
    Function Prototypes
-----------------------------------------------------------*/
void gpio_init(GPIO_TypeDef *GPIOx,
               uint8_t pin,
               uint8_t mode);

void gpio_write(GPIO_TypeDef *GPIOx,
                uint8_t pin,
                uint8_t value);
 
uint8_t gpio_read(GPIO_TypeDef *GPIOx,
                  uint8_t pin);
                                  
void gpio_toggle(GPIO_TypeDef *GPIOx,
                 uint8_t pin);
                 
#endif