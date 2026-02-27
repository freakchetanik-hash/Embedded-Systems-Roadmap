# GPIO Register Level – PA5 LED Toggle

## Objective
Blink onboard LED using direct register access.

## Board
STM32F446RE (Nucleo)

## Registers Used
- RCC_AHB1ENR
- GPIOA_MODER
- GPIOA_ODR

## Steps
1. Enable GPIOA clock
2. Configure PA5 as output
3. Toggle using ODR

## Result
LED blinks continuously.