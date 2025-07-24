# CS50 Week 2 notes 

## Topics Covered
- Compiling and building process 
- Use of debug50
- Arrays
- Strings as an array of characters, string length and using ```#include <string.h>```
- ```ctype.h``` (character functions)
- Command-line arguements (```argc```, ```argv```)
- Exit status (```return 0``` and ```return 1```)
- use of ```echo $?``` to determine exit status
- Cryptography (Caesar cipher)
- ASCII values and character manipulation 

## Arrays: 
- Arrays store multiple values of the same type in contiguous memory
- Indexing starts at 0
- Must define array size or initialise values

```
int scores[3] = {72, 73, 33};
```

Loops through an array: 
```
for (int i = 0; i < 3; i++)
{
    printf("%i\n", scores[i]);
}
```

## Strings:
- Strings are arrays or characters which end in \0
- Characters in the string can be accessed via index

```
string s = "Hi!";
printf("%c\n", s[0]); // H
```

Use ```strlen()``` to get a string length:
```
#include <string.h>
int len = strlen(s);
```

## Command-Line Arguements:
- ```main(int argc, string argv[])```
- argc: number of arguements
- argv[]: arrary of arguements (strings)

```
int main(int argc, string argv[]) {
    printf("Hello, %s\n", argv[1]);
}
```

## Code Description 
1. scrabble.c - calculates the score of two words and uses this to determine which player wins 

2. readability.c - calculates the approximate grade level of a given text 

3. caesar.c - encrypt a message using Caesar's algorithm, where the key is also input by the user

4. substitution.c - uses a substitution cipher based on a 26-letter key provided as a command-line argument, replacing each letter according to a custom alphabet mapping

5. no-vowels.c - 
