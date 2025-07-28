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
- Sorting an array in size order
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
