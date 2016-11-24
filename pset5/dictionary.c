/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "dictionary.h"
    
// Declare root node of the trie structure
node* root;

// # of words in the dictionary.
unsigned int words;

// Node prototype
void clear(node* ptr);
    
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int length = strlen(word);
    
    // Pointer to the current node in the trie
    node* ptr = root;
    
    // for each letter, i, in the input word
    for (int i = 0; i < length; i++)
    {
        // convert chars to lowercase
        char c = tolower(word[i]);
        
        // go to the corresponding element in children
        if (c == '\'')
        {
            // Value of apostrophe, - 97 = 26 (The position in the node).
            c = 123;
        }
        
        // Find location of next node
        struct node* nextNode = ptr->nodes[c-97];
        
        if (nextNode == NULL)
        {
            return false; // misspelled
        }
        else
        {
            ptr = nextNode;
        }
    }
        // Check if the value word in the trie is true, which indicates if the word is actually present in the dictionary.
        if (ptr->word == true)
        {
            return true;
        }
        
        return false;
    
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)
{
    
    // Open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
 
    // Allocate space for the first root node
    root = calloc(1, sizeof(node));
 
    // Points to current node as the program descends through the trie
    node* ptr = root;
 
    // Read the dictionary one character at a time
    for (char c = tolower(fgetc(dict)); c != EOF; c = fgetc(dict))
    {
        // If the word is finished
        if (c == '\n')
        {
            // Check that the word is at least one letter long
            if (ptr != root)
            {
                words++;
 
                ptr->word = true;
 
                // Reset the pointer back to the top of the trie
                ptr = root;                
            }
        }
        // If the word is still in progress
        else
        {
            // Check if character is apostrophe
            if (c == '\'')
            {
                // 123 - 97 = 26 (apostrophes go at nodes[26])
                c = 123;
            }
 
            // Try to get the address of the next node in the trie
            struct node* nextNode = ptr->nodes[c-97];
            if (nextNode == NULL)
            {
                // Allocate space if it is not yet there
                ptr->nodes[c-97] = calloc(1, sizeof(node));
 
                ptr = ptr->nodes[c-97];
            }
            else
            {
                ptr = nextNode;
            }
            
        }
    }
 
    fclose(dict);
 
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // Return variable words, which incremented # of words during dictionary load.
    return words;
}

/**
 * Recursive function that frees a trie from memory
 */
void clear(node* ptr)
{
    for (int i = 0; i < 27; i++)
    {
        if (ptr->nodes[i] != NULL)
        {
            clear(ptr->nodes[i]);
        }
    }
 
    free(ptr);
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    clear(root);
    return true;
}
