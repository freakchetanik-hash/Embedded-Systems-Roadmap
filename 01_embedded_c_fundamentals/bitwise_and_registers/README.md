Bitwise Operations and Register Manipulation
Why I Am Learning This

In embedded systems, hardware is controlled using registers, and registers are controlled using bits.

Every peripheral (GPIO, Timer, UART, CAN, etc.) is configured by:

Setting specific bits

Clearing specific bits

Checking status bits

If I don’t understand bitwise operations deeply, I cannot write reliable firmware.

This section is focused on building that foundation.

Concepts Covered
1. Basic Bitwise Operations

AND (&)

OR (|)

XOR (^)

NOT (~)

Left shift (<<)

Right shift (>>)

Goal: Understand how bits change during operations.

2. Bit Masking

Creating bit masks using macros

Setting a specific bit

Clearing a specific bit

Toggling a specific bit

Checking if a bit is set

This is directly applicable to register-level programming.

3. Register Simulation

Simulating a 32-bit hardware register using volatile

Writing helper functions to manipulate bits

Understanding how firmware interacts with memory-mapped registers

This builds a mental model of how microcontrollers expose peripherals.

Key Things I Understood

A register is just a memory location.

Each bit in a register has a specific meaning.

Bit masking allows modifying only selected bits without affecting others.

volatile is important when dealing with hardware registers.

Shifting is often used to position configuration bits.

Why This Matters for My Embedded Journey

This section prepares me for:

GPIO configuration

Timer setup

Interrupt control

Communication protocol registers

CAN controller configuration

Bitwise operations are the foundation of low-level embedded firmware.