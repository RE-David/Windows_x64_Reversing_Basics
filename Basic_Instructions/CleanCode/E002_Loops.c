#include <stdio.h>
#include <string.h>

/*
Now that you got the password, let's see how the compiler handles diferent types of loops. No special trick here, just a simple while, do while and for loop. 
[Tip: This might be a good opportunity to try out dynamic analysis, with a debugger (x64dbg, gdb, radare2 or the one your decompilation tool uses)].

"To understand is to perceive patterns" -Isaiah Berlin
*/


int main(int argc, char * argvar[]) {
    int guess;
    
    printf("Tell me a number please!\n");
    scanf("%d", &guess);
    printf("While is like this!");
    
    int i = 0;
    while(i++ < guess)
    {
        guess = guess * i-4;

    }
    printf("\nwhile number is %d\n", guess);
    printf("do while is like this \n");
    do{
        guess= guess -i +3;
        
    }while (--i > 4);
    printf("do while number is %d\n", guess);
    
    printf("for is like this \n");
    for (int j=0; j<9; j++)
    {
        guess += i-j;
    }
    
    printf("FOR number is %d\n", guess);

    
    return 0;
} 