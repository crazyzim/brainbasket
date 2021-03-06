/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"
#include "llist.h"


list *head;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE *fd = fopen(dictionary, "r");
    if (fd == NULL)
    {
        printf ("file is not valid");
        return false;
    }    
    char c = 0;
    int index = 0;
    char words[LENGTH];
    
    while ((c = fgetc(fd)) != EOF )
    {
        if (c =='\n')
        {
            list_add(head, words);
            index = 0;
        }
        else
            words[index++] = c;
    }
    
  
    fclose(fd);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
     int size = list_size(head);
     printf("head=%p\n",head);
    return size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    while (list_remove_last(head));
    return true;
}

void print (void)
{
    list_print(head);
    
}