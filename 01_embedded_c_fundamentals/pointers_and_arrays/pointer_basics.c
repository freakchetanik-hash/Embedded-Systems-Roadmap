#include <stdio.h>

int main(void)
{
    int value = 10;
    int *ptr = &value;

    printf("Value        : %d\n", value);
    printf("Address      : %p\n", (void*)&value);
    printf("Pointer holds: %p\n", (void*)ptr);
    printf("Dereferenced : %d\n", *ptr);

    *ptr = 25;   // modify value using pointer

    printf("Modified value: %d\n", value);

    return 0;
}
