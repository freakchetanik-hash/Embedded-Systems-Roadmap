#include <stdio.h>

void print_size(int *ptr)
{
    printf("Inside function sizeof(ptr): %lu\n", sizeof(ptr));
}

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf("Inside main sizeof(arr): %lu\n", sizeof(arr));

    print_size(arr);

    printf("Array elements using indexing:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nArray elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(arr + i));
    }

    printf("\n");

    return 0;
}
