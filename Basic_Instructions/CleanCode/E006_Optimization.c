#include <stdio.h>

/*
Here we have an example of how the code we write can be changed and optimized by the compiler. 
The function my_operation is a simple mathematical operation, but when we call it in a loop, the compiler can optimize it and make it faster. 
[Tip: different compilers have different optimization techniques, try to understand how your compiler optimizes this code, and how it changes the assembly code]


"Small steps lead to great distances." - Chinese proverb
*/

int my_operation(int x) {
    return (x * 3) + 5;
}

int main(int argc, char * argvar[]) {
    int sum = 0;
    
    
    for (int i = 0; i < 100; i++) {
        sum += my_operation(i);
    }
    
    printf("The sum is: %d\n", sum);
    return 0;
}