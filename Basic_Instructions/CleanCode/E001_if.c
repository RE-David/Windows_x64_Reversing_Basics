#include <stdio.h>
#include <string.h>

/*
After the last exercise, you should be familiar with the decompilation tool, and how to find main. In this exercise you will find a simple password checker. 
The objective is to familiarize with the if statement, notice how functions such as printf are called, and find the password in the decompiled code.
[Tip: if only there was a simple function to compare strings, maybe something like strcmp?]


"Every decision begins with a check" - Unknown (probably someone who had to write a lot of if statements)
*/

int main(int argc, char * argvar[]) {
    char guess[10];
    char solution[] = "password12";
    printf("Guess the password!\n");
    scanf("%s", guess);
    if(strcmp(guess, solution) == 0)
    {
        printf("good job!");
    }else
    {
        printf("incorrect"); 
    }
    return 0;
} 