# Timer Interrupt

## Objective
Implement TIM2 Update Interrupt using NVIC and ISR.

## Concepts Learned
- TIM2 PSC and ARR
- Update Interrupt (UIE)
- Update Interrupt Flag (UIF)
- NVIC
- Vector Table
- Weak Aliases
- Interrupt Service Routine
- volatile
- extern

## Verification
- Observe `system_ticks` in the debugger.
- Verify it increments every 500 ms without any polling in `main()`.
