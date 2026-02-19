#include <stdio.h>
#include <stdint.h>

// Simulating a hardware register
volatile uint32_t GPIO_REGISTER = 0x00000000;

#define BIT(n) (1U << (n))

void set_pin(uint8_t pin) {
    GPIO_REGISTER |= BIT(pin);
}

void clear_pin(uint8_t pin) {
    GPIO_REGISTER &= ~BIT(pin);
}

void toggle_pin(uint8_t pin) {
    GPIO_REGISTER ^= BIT(pin);
}

int main() {
    printf("Initial Register: 0x%08X\n", GPIO_REGISTER);

    set_pin(5);
    printf("Set pin 5:        0x%08X\n", GPIO_REGISTER);

    toggle_pin(5);
    printf("Toggle pin 5:     0x%08X\n", GPIO_REGISTER);

    clear_pin(5);
    printf("Clear pin 5:      0x%08X\n", GPIO_REGISTER);

    return 0;
}
