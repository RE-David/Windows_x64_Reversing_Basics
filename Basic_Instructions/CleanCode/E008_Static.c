#include <stdio.h>

/*
 Static variables are variables that retain their value between function calls. Let's see how the compiler handles them, and how they differ from normal variables.

 "Some things persist even when everything else changes." - Unknown 
*/

void my_function() {
    int normal_var = 10;
    static int static_var = 10; 

    normal_var += 5;
    static_var += 5;

    printf("Normal var: %d, Static var: %d\n", normal_var, static_var);
}

int main() {
    printf("First call:\n");
    my_function();
    
    printf("\nSecond call:\n");
    my_function();
    
    return 0;
}