// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *hashtable[HASHTABLE_SIZE];

//Reddit user delipity provided hash function
int hash_index(char *hash_this)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hash_this); i < n; i++)
    {
        hash = (hash << 2) ^ hash_this[i];
    }
    return hash % HASHTABLE_SIZE;
}

// keep tracker for all words
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Copy word as to not accidentally alter anything
    int n = strlen(word);
    char copy[LENGTH + 1];
    for (int i = 0; i < n; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[n] = '\0';
    // Init index
    int h = hash_index(copy);
    //Use cursor pointer
    node *cursor = hashtable[h];
    // While cursor does not point to NULL, search dictionary for word.
    while (cursor != NULL)
    {
        // If strcasecmp returns true, then word has been found
        if (strcasecmp(cursor->word, copy) == 0)
        {
            return true;
        }
        // Else word has not yet been found, advance cursor
        else
        {
            cursor = cursor->next;
        }
    }
    // Cursor has reached end of list and word has not been found in dictionary so it must be misspelled
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
    return false;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
