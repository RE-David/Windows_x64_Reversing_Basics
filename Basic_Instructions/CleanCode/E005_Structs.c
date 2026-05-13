#include <stdio.h>
#include <string.h>

/*
Lets take a look to structs, they are a way to group different types of data together. They are very useful to create complex data structures, and to pass them to functions.
[Tip: Try to understand how the struct is stored in memory, and how the compiler handles it when we access its members]

"The whole is greater than the sum of its parts." - Aristotle (Hasnt made a struct in c in his lifetime, but he was a smart guy)
*/

struct myStructure {
  int myNum;
  char myLetter;
};

int main(int argc, char * argvar[]) {
  
  struct myStructure s1;

  s1.myNum = 13;
  s1.myLetter = 'B';

  // Print values
  printf("My number: %d\n", s1.myNum);
  printf("My letter: %c\n", s1.myLetter);

  return 0;
}