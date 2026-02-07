## Pointers and Arrays

This folder focuses on understanding pointer behavior in C,
which is critical for embedded systems programming.

### Key Learnings
- A pointer stores the address of a variable.
- Dereferencing allows direct modification of memory.
- Pointer to pointer enables indirect access (used in drivers and APIs).
- Arrays decay into pointers when passed to functions.
- sizeof(array) works only in the same scope where the array is declared.

### Embedded Relevance
- Register access uses pointers.
- Driver APIs rely heavily on pointer passing.
- Incorrect pointer handling can corrupt memory or crash systems.

Understanding these concepts is essential before working with
microcontrollers and RTOS-based systems.
