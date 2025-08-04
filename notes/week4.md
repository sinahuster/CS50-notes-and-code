# CS50 Week 4 - Memory

## Topics Covered
- Memory and Pointers
- Dynamic memory allocation
- Strings as an Array of Characters
- Input Handling and ```scanf```
- File I/O (Reading and Writing Files)
- Buffer Overflow and Memory Safety
- Valgrind (Memory Debugging)

## Memory and Pointers
- Memory stores variables and data while the program runs.
- A pointer is a variable that stores the address of another variable.
- Syntax
```
int x = 42;
int *p = &x;  // p stores the address of x
printf("%p\n", p);    // prints address
printf("%d\n", *p);   // dereference: prints 42
```
- Use ```*``` to dereference, and ```&``` to get an address.
- Pointers can be of other types too, such as ```char``` or ```float```
- You can move through arrays using pointers
```
int numbers[] = {1, 2, 3};
int *ptr = numbers;
printf("%d\n", *(ptr + 1));  // prints 2 (numbers[1])
```

## Dynamic memory allocation
- ```malloc()``` is used to allocate memory on the heap.
```
int *arr = malloc(5 * sizeof(int));
```
- Youa always have to check for ```NULL```
- After use, the memory is freed using ```free()```


## Strings as an Array of Characters
- Strings are actually just ```char *``` pointers to the first character of an array.
- Strings always end in ```'\0'``` (the null terminator)
```
char name[] = "CS50";     // 5 bytes including '\0'
char *ptr = name;
```
- Strings can be manipulated like arrays
```
name[0] = 'c';
printf("%s\n", name);  // prints "cS50"
```

## Input Handling and ```scanf```
- ```scanf``` reads formatted input from the user
```
int x;
scanf("%d", &x);
```
- Must set a max size to prevent risk of overflow 
- Safe way to use ```scanf```
```
char str[20];
scanf("%19s", str);
```


## File I/O (Reading and Writing Files)
- Open a file with ```fopen```
```
FILE *file = fopen("file.txt", "r");
```
- Read and write functions:
    - ```fgetc(file)``` reads one character
    - ```fgets(buffer, size, file)``` reads one line
    - ```fread()```/```fwrite()``` for binary files
- Close the file
```
fclose(file)
```
- Reading with ```fgets```:
```
char buffer[100];
if (fgets(buffer, sizeof(buffer), file))
{
    printf("%s", buffer);
}
```

## Buffer Overflow and Memory Safety
- Writing outside of array boundaries causes undefined behaviour
- It can corrupt memory or crash the program
- We must always:
    - Check array boundaries
    - Allocate enough memory


## Valgrind (Memory Debugging)
- Valgrind helps to detect:
    - Memory leaks
    - Use of uninitialisated memory
    - Accessing freed memory
- Run valgrind with
```
valgrind ./program
```
- Example output:
```
==12345== 10 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x4C301E3: malloc (vg_replace_malloc.c:299)
==12345==    by 0x4005F6: main (program.c:5)
```

## Code Descriptions 

1. recover.c - Recovers JPEGs from raw memory by reading 512-byte blocks.

2. volume.c - Modifies the volume of an audio file.

3. pdf.c - Determines whether a file is a PDF or not.

4. swap.c - Swaps two integers using pointers.

5. cp.c - Copies a file.

6. copy.c - Capitilises a copy of a string without memory errors

7. helpers.c within filter-more - applys filters to images (BMPs).
