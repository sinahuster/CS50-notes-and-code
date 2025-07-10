# CS50 Week 1 notes 

## Topics Covered
- C programming basics (syntax, compilation, variables)
- Data types: 'int', 'float', 'char', 'string', 'bool', 'long' 
- Input/output with 'printf' and 'get_int, 'get_string
- Conditionals ('if', 'else if', 'else')
- Loops ('for', 'while', 'do while')
- Functions
- Greedy algorithm (Cash problem)
- Luhn’s algorithm (Credit problem)
- Comparison operators: '==', '!=', '>', '<', '<=', '>='


## C Basics
- To compile: 'cc program.c -o program'
- Always declare variable types
- '#include <stdio.h> lets you use 'printf', 'scanf', etc.
- '#inlcude <cs50.h>' gives you functions like 'get_int'

## Basic Example
```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
}
```

## Conditionals 
```c
if (x > 0) {
    // do something
} else if (x < 0) {
    // do something else
} else {
    // do another thing
}
```

## Loops 
For loops where the number of iterations is known 
```c 
for (int i = 0; i < n; i++) {
    // do something
}
```

 While loop where the number of iterations is unknown 
```c
while (condition) {
    // do something
}
```

Do-While loop which runs at least once
```c 
do {
    // do something
} while (condition);
```

## Code Desciptions 
1. hello.c - prints 'hello, world' to the screen

2. mario.c - creates a pyramid with a gap in the middle, where the user inputs the height
           - uses nested loops

3. cash.c - uses a greedy algorithm to compute the minimum number of coins required for change

4. credit.c - uses Luhn's algorithm to determine whether a credit number number is valid, and which type it corresponds to

5. half.c - creating the function which calculates the amount owed by each person, taking into account tax and tip

6. prime.c - created a boolean function which determines if a number is prime or not
