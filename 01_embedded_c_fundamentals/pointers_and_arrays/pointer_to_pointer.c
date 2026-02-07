#include <stdio.h>

int main(void)
{
    int value = 42;
    int *ptr = &value;
    int **pptr = &ptr;

    printf("Value          : %d\n", value);
    printf("Using ptr      : %d\n", *ptr);
    printf("Using pptr     : %d\n", **pptr);

    **pptr = 100;

    printf("Modified value : %d\n", value);

    return 0;
}
