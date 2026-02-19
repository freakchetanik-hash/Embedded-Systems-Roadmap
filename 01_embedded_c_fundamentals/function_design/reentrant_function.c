#include <stdio.h>

// Reentrant function
int add(int a, int b) {
    return a + b;
}

// Non-reentrant example (uses global variable)
int result;

int add_non_reentrant(int a, int b) {
    result = a + b;
    return result;
}

int main() {
    printf("Reentrant add: %d\n", add(3, 4));
    printf("Non-reentrant add: %d\n", add_non_reentrant(5, 6));

    return 0;
}
