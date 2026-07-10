#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

/*=========================================================
    SysTick Register Structure
=========================================================*/
typedef struct
{
    volatile uint32_t CTRL;      /* Control Register */
    volatile uint32_t LOAD;      /* Reload Register */
    volatile uint32_t VAL;       /* Current Value Register */
    volatile uint32_t CALIB;     /* Calibration Register */

} SysTick_TypeDef;

/*=========================================================
    Base Address
=========================================================*/
#define SYSTICK_BASE    0xE000E010UL

/*=========================================================
    SysTick Peripheral
=========================================================*/
#define SYSTICK    ((SysTick_TypeDef *)SYSTICK_BASE)

/*=========================================================
    CTRL Register Bit Positions
=========================================================*/
#define SYSTICK_CTRL_ENABLE_Pos      0U
#define SYSTICK_CTRL_TICKINT_Pos     1U
#define SYSTICK_CTRL_CLKSOURCE_Pos   2U
#define SYSTICK_CTRL_COUNTFLAG_Pos   16U

/*=========================================================
    Function Prototypes
=========================================================*/
void systick_init(void);
uint32_t millis(void);

#endif