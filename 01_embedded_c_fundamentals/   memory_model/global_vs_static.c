#include <stdio.h>

/* Global variable (external linkage, lifetime = entire program) */
int global_var = 10;

/* Static global variable (internal linkage, lifetime = entire program) */
static int static_global_var = 20;

void demo_function(void)
{
    /* Static local variable (retains value across function calls) */
    static int static_local_var = 0;

    /* Automatic local variable (stack allocated) */
    int local_var = 0;

    static_local_var++;
    local_var++;

    printf("Inside function:\n");
    printf("  static_local_var = %d, address = %p\n",
           static_local_var, (void *)&static_local_var);
    printf("  local_var        = %d, address = %p\n",
           local_var, (void *)&local_var);
}

int main(void)
{
    printf("Global variables:\n");
    printf("  global_var        = %d, address = %p\n",
           global_var, (void *)&global_var);
    printf("  static_global_var = %d, address = %p\n\n",
           static_global_var, (void *)&static_global_var);

    printf("Calling demo_function first time:\n");
    demo_function();

    printf("\nCalling demo_function second time:\n");
    demo_function();

    return 0;
}
