# 03 - Periodic Events

## Objective

Build a reusable periodic timer driver on top of the TIM2 interrupt driver.

## Concepts Learned

- Hardware Timer
- Interrupt-driven software tick
- Driver abstraction
- Encapsulation
- Timer Objects
- Periodic Scheduling
- static
- extern
- millis()

## API

timer_init()

millis()

timer_start()

timer_expired()

timer_restart()

## Demo

Blink LED every 500 ms using the periodic timer driver.
