#include <stdio.h>

// Function that does not modify data
void print_value(const int *ptr) {
    printf("Value: %d\n", *ptr);
}

// Function that modifies data
void increment(int *ptr) {
    (*ptr)++;
}

int main() {
    int x = 10;

    print_value(&x);

    increment(&x);
    print_value(&x);

    return 0;
}
