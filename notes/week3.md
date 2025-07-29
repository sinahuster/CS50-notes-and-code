# CS50 Week 3 - Algorithms 

## Topics Covered
- Algorithms and Efficiency
- Searching Algorithms (Linear and Binary Search)
- Sorting Algorithms (Bubble, Selection and Merge Sort)
- Big O Notation (Time and Space Efficiency)
- Structs
- Recursion

## Searching algorithms 

Linear Search 
- Iterates through each elemnent one by one
- O(n) time complexity
- If looking for ```target``` within ```array[i]```
```
  for (int i = 0; i < n; i++)
{
    if (array[i] == target)
    {
        return true;
    }
}
return false;
```

Binary Search 
- Only works in sorted arrays
- Repeated divides the search interval in half
- O(log n) time complexity
- If looking for ```target``` within ```array[i]```
```
int binary_search(int array[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (array[mid] == target)
            return true;
        else if (array[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
```

## Sorting Algorithms 

Bubble Sort 
- Repeatedly swaps adjascent elements if they are in the wrong order
- Worst case time: O(n^2)
- Sorting an array in size order:
```
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < n - 1; j++)
    {
        if (array[j] > array[j + 1])
        {
            // swap
        }
    }
}
```

Selection Sort 
- Repeatedly delects the smallest element and moves it to the front
- Worst case time: O(n^2)
- Sorting an array in size order:
```
for (int i = 0; i < n; i++)
{
    int min_index = i;
    for (int j = i + 1; j < n; j++)
    {
        if (array[j] < array[min_index])
        {
            min_index = j;
        }
    }
    if (min_index != i)
    {
        // swap array[i] and array[min_index]
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}
```

Merge Sort 
- Recursively splits the array in half, sorts each half and then merges then back together
- Time complexity: O(n log n)
- Space complexity: O(n)
- Sorting an array in size order:
```
void merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // Sort first half
        merge_sort(array, left, mid);

        // Sort second half
        merge_sort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}
```

## Recursion 
- A function that calls itself
- Requires a base case shich stops conversion
- Useful for problems that need to be broken into smaller problems
- A recursive function that counts down
```
void countdown(int n)
{
    if (n <= 0)
        return;
    printf("%d\n", n);
    countdown(n - 1);
}
```

## Code Descriptons 

1. phonebook.c - checks if the name input is in the phonebook, and if it is prints the number. 

2. recursion.c - prints a pyramid of the input height using a recurisive function.

3. plurality.c - runs a pluraity election, where each person votes for one person to select a winner.
