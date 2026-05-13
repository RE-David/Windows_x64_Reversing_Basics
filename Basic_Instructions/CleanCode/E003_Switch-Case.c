#include <stdio.h>
#include <string.h>

/*
In this exercise we will see how the switch case statement is handled by the compiler. 
The switch case is a more efficient way to handle multiple if statements that compare the same variable.
[No tip on this one, just try to understand how the switch case is implemented in assembly, and how the compiler optimizes it]

"If you are not happy with the output, switch the case" - Me (someone who had to write a lot of switch cases!!)
*/

int main(int argc, char * argvar[]) {
    int guess;
    
    printf("Write a number\n");
    scanf("%d", guess);

    switch (guess)
    {
    case 1:
        printf("1 selected");
        break;
    
    case 2:
        printf("2 selected!");
        break;
    
    case 3:
        printf("selected 3!");
        break;
    
    default:
        printf("Default obtained");
        break;
    }
    return 0;
} 