#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t a = 0b10101010;
    uint8_t b = 0b11001100;

    printf("a = 0x%X\n", a);
    printf("b = 0x%X\n\n", b);

    // AND operation
    uint8_t and_result = a & b;
    printf("a & b = 0x%X\n", and_result);

    // OR operation
    uint8_t or_result = a | b;
    printf("a | b = 0x%X\n", or_result);

    // XOR operation
    uint8_t xor_result = a ^ b;
    printf("a ^ b = 0x%X\n", xor_result);

    // NOT operation
    uint8_t not_result = ~a;
    printf("~a = 0x%X\n", not_result);

    // Left shift (multiply by 2)
    uint8_t left_shift = a << 1;
    printf("a << 1 = 0x%X\n", left_shift);

    // Right shift (divide by 2)
    uint8_t right_shift = a >> 1;
    printf("a >> 1 = 0x%X\n", right_shift);

    return 0;
}
