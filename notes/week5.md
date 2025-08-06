### CS50 Week 5 - Data Structures 

## Topics Covered
- Arrays and Resizing
- Linked Lists
- Stacks and Queues
- Trees
- Dictionaries
- Hashing and hash tables
- Tries
- Memory management in Data Strcutures

## Arrays and Resizing 
- Arrays store items of the same type in a contiguous memory
- Fast access with index, but
    - Fixed size once declared
    - Insertion/Deletion of elements in the middle is expensive ```O(n)```
- Arrays can be resized by allocating new memory dynamically
```
int *arr = malloc(3 * sizeof(int));
// For more space
arr = realloc(arr, 6 * sizeof(int));
```
- ```realloc()``` may move data to a new location
- Must always check if ```realloc()``` returns ```NULL```

## Linked Lists 
- A linked list is made up of nodes that point to the next node
- They are dynamically sized which is useful when the data size is unknown
```
typedef struct node
{
    int node;
    struct node *next;
] node;
```
- Adding to the list:
```
node *n = malloc(sizeof(node));
n->number = 10;
n->next = list;
list = n;
```
- We must ```free()``` the nodes after use

## Stacks 
- LIFO: Last In, First Out
- e.g. pile of trays: last one added to the top is the first used
- Operations:
    - ```push()``` add to the top
    - ```pop()``` remove from the top
- Can be implemented using arrays or linked lists

## Queues 
- FIFO: First In, First Out
- e.g line of people: first person is served first
- Operations:
    - ```enqueue()``` add to end
    - ```dequeue()``` remove from the front
- Also can be impleted using arrays or linked lists

## Trees
- A tree is a hierarchical structure
- Each node can have children (binary tree = max 2)
- Useful for:
    - Searching
    - Sorting
    - Decision-making
 
## Dictionaries 
- A dictionary maps words (keys) to definitions (values)
- Implemented using:
    - Hash Tables
    - Tries

## Hashing and Hash Tables 
- Hashing turns a key into an index
```
int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}
```
- Collisions occur when multiple keys map to the same index
- Handle with chaining (linked lists at each bucket)
- Fast lookups (```O(1)``` on average)
- Uneven distribution

## Tries 
- A trie is a tree where each node represents a character
- Used to store a large set of strings efficiently
- Each path down the trie is a prefix
```
typedef struct node
{
    bool is_word;
    struct node *children[26];
} node;
```
- Good for dictionaries, autocomplete and spell-checking

## Overall
Arrays are simple but rigid
Linked lists provide dynamic memory 
Stacks and Queues help with ordering 
Trees and Tries help with structured and fast searching 
Hash tables give fast lookups using keys 

## Code Descriptions 
