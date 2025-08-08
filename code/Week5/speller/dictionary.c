// Implements a dictionary's functionality
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 26 * 26 * LENGTH;

// Hash table
node *table[N];

// Counter for loaded words
int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word, to obtain it's location in the hash table
    int index = hash(word);

    // Go through the linked list at the location of table[index] and check if
    // any of the strings match with the word
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Find the length of the word
    int len = strlen(word);

    // Single character words will be the first 26 indices
    if (strlen(word) == 1)
    {
        return toupper(word[0]) - 'A';
    }

    // Calculate the values of each letter
    int first = toupper(word[0]) - 'A';
    int second = toupper(word[1]) - 'A';

    // Return hash value dependent on the first 2 letters of the word,
    // offset by 26 values
    return (first * 26 + second) * len;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", buffer) != EOF)
    {
        node *new_word = malloc(sizeof(node));
        new_word->next = NULL;
        strcpy(new_word->word, buffer);

        // Obtain the hash value of the word
        int index = hash(new_word->word);

        // Assign new word the index in the hash table
        // or prepend the word to the list which is found at the index of the hash table
        new_word->next = table[index];
        table[index] = new_word;

        // Increment the counter for the number of words loaded
        count++;
    }

    // Close the dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loop through the hash table, to clear each index
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }
    return true;
}
