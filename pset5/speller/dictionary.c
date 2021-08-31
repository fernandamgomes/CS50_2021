// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];

//number of words
long sum_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //hash word to obtain hash value
    int index = hash(word);

    //store a pointer that points to the hash value
    node *cursor = table[index];

    //traverse linked list looking for the word and stop at the end of the linked list
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
// Source: djib2 by Dan Bernstein (http://www.cse.yorku.ca/~oz/hash.html)
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;

    int c = *word;

    c = tolower(c);

    while (*word != 0)

    {

        hash = ((hash << 5) + hash) + c;

        c = *word++;

        c = tolower(c);

    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];

    //open dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return false;
    }

    //read strings from file one at a time
    while (fscanf(input, "%s", word) != EOF)
    {
        //create a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //copy word into node
        strcpy(n->word, word);

        //hash word: use the hash function
        int index = hash(n->word);

        //insert node into hash table
        //if there is nothing at that index yet
        if (table[index] == NULL)
        {
            n->next = NULL;
            table[index] = n;
            //reads: table[index] = new node
        }
        else
        {
            //set node pointer to point at the head of the list
            n->next = table[index];
            //insert new node (n) at the beginning of the list (new head of the list)
            table[index] = n;
        }
        //update the total of words that have been loaded to the dictionary
        sum_words = sum_words + 1;
    }
    //close file and return true
    fclose(input);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sum_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //go through the hash table freeing memory, remember that a hash table is an array of linked lists
    //starts at index 0, ends at N-1
    for (int i = 0; i < N; i = i + 1)
    {
        //point cursor to the head of the linked list (= table[i])
        node *cursor = table[i];
        node *tmp = cursor;
        while (cursor != NULL)
        {
            //point cursor to the next node
            cursor = cursor->next;
            //free tmp (it will free tmp + whatever it was pointing to)
            free(tmp);
            //set tmp to be the same thing as cursor
            tmp = cursor;
        }
    }
    return true;
}
