# CS50 Week 6 - Python 

## Topics Covered 
- Python Basics
- Variables and Data Types
- Conditionals
- Loops
- Functions
- Lists, Tuples, Sets and Dictionaries
- Strings and String Methods
- File I/O
- Command-line Arguements
- Libraries and Modules

## Python Basics
- **Dynamically typed** – no need to declare variable types explicitly.
- **Indentation matters** – defines code blocks instead of `{}`.
- **Comments**:  
  - Single line: `# comment`  
  - Multiline/docstrings: `''' text '''` or `""" text """`
- No semicolon needed at the end of statements

## Variables and Data Types 
Common data types include ``` int```, ```float```, ```str```, ```bool ```
```
x, y = 5, 10     # Multiple assignment
type(x)          # <class 'int'>
int("42")        # 42
str(42)          # "42"
float(42)        # 42.0
```

## Conditionals 
- Comparisons: ```==```, ```!=```, ```<```, ```<=```,``` >```,``` >=```
- Logical Operators: ```and```, ```or```, ```not```
```
if x > 0:
    print("Positive")
elif x == 0:
    print("Zero")
else:
    print("Negative")
```

## Loops 
- For loops (iterate over a sequence):
```
for i in range(5):
  print(i)
```
- While loops:
```
while n > 0:
    print(n)
    n -= 1
```
- ```break``` exits loop
- ```continue``` skips to the next iteration

## Functions 
```
def greet(name="world"):
    print(f"Hello, {name}")

greet()        # Hello, world
greet("Alice") # Hello, Alice
```
- ```return``` sends back values
- Functions are first-class objects (can be passed/ stored like variables)

## Lists 
- Ordered, mutable collections
```
numbers = [1, 2, 3]
numbers.append(4)
numbers[0] = 10
print(numbers[1:3])  # Slicing
```
Common methods: ```.append()```, ```.remove()```, ```.pop()```, ```.sort()```

## Tuples
Ordered, immutable collections 
```
point = (3, 4)
x, y = point  # Unpacking
```

## Sets 
Unordered, unique elements 
```
fruits = {"apple", "banana"}
fruits.add("orange")
```
Methods: ```.add()```, ```.remove()```, ```.union()```, ```.intersection()```

## Dictionaries 
Key-valued pairs 
```
ages = {"Alice": 25, "Bob": 30}
ages["Charlie"] = 35
```
Methods: ```.keys()```, ```.values()```, ```.items()```

## Strings 
- Immutable sequence of characters
```
name = "Alice"
print(name.lower(), name.upper())
```
- f-strings for formatting
```
f"Hello, {name}"
```
- Methods: ```.lower()```, ```.upper()```, ```.strip()```, ```.split()```, ```.join()```

## File I/O
- Reading:
```
with open("file.txt", "r") as file:
    contents = file.read()
```
- Writing
```
with open("file.txt", "w") as file:
    file.write("Hello")
```
- Modes:
    - ```r``` = read
    - ```w``` = write 
    - ```a``` = append

 ## Command Line Arguements 
 ```
import sys
print(sys.argv[1])  # First argument after script name
```

## Libraries and Modules 
```
import math
from random import randint
```
Install external libraries: 
```
pip install libraryname
```

## Code Descriptions 

1. mario-more.py - Create a pyramid of a height given by the user. 

2. credit.py - Determining if a number is a valid credit card number, if so, which type of card it is. 

3. readability.py - Determining the reading level of a text, taking length of words and sentances into account.

4. dna.py - Identify which person a DNA sequence belongs to, using dictionaries (only completed main()).

5. phrases.py - Use of for loops. 

6. jar.py - definition of a class and adding methods. 
