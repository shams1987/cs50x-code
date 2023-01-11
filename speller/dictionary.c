// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// variable declaration
unsigned int word_count;
unsigned int hash_value;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // get hash value for word
    hash_value = hash(word);

    // start looking from the first word on linked list
    node *cursor = table[hash_value];

    // traverse through list
    while (cursor != 0)
    {
        //  comapre word with current word on list
        if (strcasecmp(word, cursor->word) == 0)
        {
            // if they match
            return true;
        }
        // move cursor to next on list
        cursor = cursor->next;
    }
    // if they do not match
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // return toupper(word[0]) - 'A';
    unsigned long total = 0;
    // go through each word, add up the ascii
    for (int i = 0; i < strlen(word); i++)
    {
        // lowercase first then add
        total += tolower(word[i]);
    }
    // mod 26 for the hash value
    return total % N;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opens dictionary
    FILE *file = fopen(dictionary, "r");

    // return null if it cannot be opened
    if (file == NULL)
    {
        return false;
    }

    //varinbale declaration word
    char word[LENGTH + 1];

    // Scans dictionary until end of file
    while (fscanf(file, "%s", word) != EOF)
    {
        // set memory for new node
        node *n = malloc(sizeof(node));

        // if malloc is Null, returns false
        if (n == NULL)
        {
            unload();
            return false;
        }
        // Copies word from dictionary to node
        strcpy(n->word, word);

        // Initializes & calculates index of word for insertion into hashtable
        hash_value = hash(word);
        n -> next = table[hash_value];
        table[hash_value] = n;
        word_count++;

    }
    fclose(file);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // loop through each bucket
    for (int i = 0; i < N; i++)
    {
        // cursor to the start of list
        node *cursor = table[i];
        // while there are values
        while (cursor)
        {
            // create a temporary value so cursor can move as we free up memory
            node *temp = cursor;
            // move cursor to next
            cursor = cursor->next;
            // free the temp value
            free(temp);
        }
        // when we reach the end of linked list
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
