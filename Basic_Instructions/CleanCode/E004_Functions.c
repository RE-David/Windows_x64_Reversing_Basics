#include <stdio.h>
#include <string.h>

/*
This simple crackme will help you understand how functions are handled by the compiler. 
Your mission here is to find the correct input that will make the program print "You entered the correct number!".
[Tip: Remember that the input is modified by two functions, but only one of them returns a value, maybe that is a good place to start?]


"We are what we repeatedly do. Excellence, then, is not an act, but a habit" - Will Durant, paraphrasing Aristotle
*/


void voidFunction(int number){
    number += 1;
    printf("\nHello! this function does not return anything, your number+1 is %d", number);
}

int intFunction(int number){
    number +=2;
    printf("\nThis function returns your number+2. Which at the moment is %d", number);
    return number;
}


int main(int argc, char * argvar[]) {
    int input;
    printf("Give me a number please: ");
    scanf("%d", &input);

    voidFunction(input);
    input = intFunction(input);

    if (input == 10)
    {
        printf("\nYou entered the correct number!\n");
    }else
    {
        printf("\nYou entered the wrong number, try again!\n");
    }
    return 0;
} 

