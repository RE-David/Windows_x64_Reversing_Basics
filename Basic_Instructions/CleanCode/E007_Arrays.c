#include <stdio.h>

/*
 Arrays are a way to store multiple values of the same type in a single variable. But the compiler handles them in a very specific way, 
 and understanding how they work can help you to understand how the code is executed.

 "Divide each difficulty into as many parts as is feasible and necessary." - René Descartes 
*/

int main() {

    int my_array[5];
    
    my_array[0] = 100;
    my_array[1] = 200;
    my_array[2] = 300;
    my_array[3] = 400; 
    my_array[4] = 500;
    
    int my_int = my_array[3];
    
    printf("The value is: %d\n", my_int);
    
    return 0;
}