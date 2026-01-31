#include <stdio.h>
#include <stdlib.h>

int global_var = 10;

void stack_example(void) {
    int stack_var = 20;
    printf("Stack var address: %p\n", (void*)&stack_var);
}

void heap_example(void) {
    int *heap_var = (int*)malloc(sizeof(int));
    *heap_var = 30;
    printf("Heap var address: %p\n", (void*)heap_var);
    free(heap_var);
}

int main(void) {
    printf("Global var address: %p\n", (void*)&global_var);

    stack_example();
    heap_example();

    return 0;
}
