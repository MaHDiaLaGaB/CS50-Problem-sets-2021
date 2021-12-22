// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];

int num_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    
    int index = hash(word);
    //make pointer named curser to check on all nodes
    node *curser = table[index];
    
    while (curser != NULL)
    {
        
        
        //if the word match the word in the node return true
        if (strcasecmp(word, curser->word) == 0)
        {
            return true;
        }
       
        
        curser = curser->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //init_hash_table();
    //take the lenght of the each word
    int length = strlen(word);
    unsigned int hash_value = 0;
    //point at the head witch is the hash table
    node *head = table[hash_value];
    
    for (int i = 0 ; i < length ; i++)
    {
        //looping through the word and calculate the ASCII
        hash_value += tolower(word[i]);
        hash_value = hash_value * tolower(word[i]) % N;
    }
    return hash_value;
}



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char words[LENGTH + 1];
    // TODO
    //open the file and read it
    FILE *input = fopen(dictionary, "r");
    //check if its not NULL
    if (input == NULL)
    {
        printf("file dosen't open %s.\n", dictionary);
        return false;
    }
    
    //scan the file and word by word
    while (fscanf(input, "%s", words) != EOF)
    {
        //create new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        //coping the words from words to the new node 
        strcpy(new_node -> word, words);
        //counting how many word we reach
        num_words++;
        //make the new node pointer point to null
        new_node -> next = NULL;
        //give the index hash number
        int index = hash(new_node->word);
        //make the new node point to the table first
        new_node->next = table[index];
        //change the pointer to the new node so we don't loos the link
        table[index] = new_node;
    }
    
    fclose(input);
    return true;
    
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    
    return num_words;
    
    
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0 ; i < N ; i++)
    {
        //make curser look to each node and free it by erasor pointer
        node *curser = table[i];
        while (curser != NULL)
        {
            node *erasor = curser;
            curser = curser->next;
            free(erasor);
        }
        
    }
    return true;
    
}
