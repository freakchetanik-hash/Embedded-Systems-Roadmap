#include <stdio.h>
#include <stdlib.h>

// Global initialized variable → .data
int global_initialized = 10;

// Global uninitialized variable → .bss
int global_uninitialized;

// Static initialized → .data
static int static_initialized = 20;

// Static uninitialized → .bss
static int static_uninitialized;

void function_demo() {
    // Local variable → stack
    int local_variable = 5;

    printf("Address of local variable (stack):        %p\n", &local_variable);
}

int main() {
    // Dynamic memory → heap
    int *heap_memory = malloc(sizeof(int));
    *heap_memory = 30;

    printf("Address of global_initialized (.data):     %p\n", &global_initialized);
    printf("Address of global_uninitialized (.bss):    %p\n", &global_uninitialized);
    printf("Address of static_initialized (.data):     %p\n", &static_initialized);
    printf("Address of static_uninitialized (.bss):    %p\n", &static_uninitialized);
    printf("Address of heap memory (heap):             %p\n", heap_memory);

    function_demo();

    free(heap_memory);
    return 0;
}