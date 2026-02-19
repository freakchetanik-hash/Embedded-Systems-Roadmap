#include <stdio.h>
#include <stdint.h>

#define BIT(n) (1U << (n))

int main() {
    uint8_t reg = 0x00;

    // Set bit 3
    reg |= BIT(3);
    printf("Set bit 3: 0x%X\n", reg);

    // Set bit 5
    reg |= BIT(5);
    printf("Set bit 5: 0x%X\n", reg);

    // Clear bit 3
    reg &= ~BIT(3);
    printf("Clear bit 3: 0x%X\n", reg);

    // Toggle bit 5
    reg ^= BIT(5);
    printf("Toggle bit 5: 0x%X\n", reg);

    // Check if bit 5 is set
    if (reg & BIT(5)) {
        printf("Bit 5 is SET\n");
    } else {
        printf("Bit 5 is CLEAR\n");
    }

    return 0;
}
