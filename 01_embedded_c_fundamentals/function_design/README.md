04 — Function Design in Embedded C
Overview

In embedded systems, function design directly impacts reliability, safety, and maintainability.

Unlike general application programming, embedded firmware must consider:

Interrupt safety

Memory constraints

Stack usage

Concurrency (RTOS tasks + ISRs)

Hidden side effects

This section focuses on writing safer, clearer, and more structured C functions suitable for embedded systems.

Concepts Covered
1️⃣ Const Correctness

File: const_correctness.c

This demonstrates how to properly use const in function parameters to:

Prevent accidental data modification

Protect input buffers

Make APIs safer and self-documenting

Understanding const is important when designing driver interfaces and shared modules.

2️⃣ Reentrant Functions

File: reentrant_function.c

A reentrant function:

Does not rely on global mutable state

Does not store persistent internal state

Can safely run in interrupts or multiple RTOS tasks

Reentrancy is critical in embedded systems where:

Interrupt Service Routines (ISRs) may preempt tasks

Shared modules may be accessed concurrently

This example compares reentrant and non-reentrant approaches.

3️⃣ Pass by Pointer

File: pass_by_pointer.c

This demonstrates:

Modifying variables using pointers

Avoiding unnecessary copying

Writing output parameters

Memory-efficient data handling

In embedded systems, passing large structures by value can waste stack space and reduce performance. Pointer-based design is commonly used in driver development.

Key Takeaways

Functions should have clear input/output behavior.

Avoid hidden global dependencies.

Use const to protect data integrity.

Design APIs carefully — especially for reusable modules.

Think about how functions behave inside interrupts and RTOS tasks.

Good function design ensures firmware remains:

Predictable

Testable

Maintainable

Scalable
